from utils.ddpg import DDPG as Agent
from utils.env import Environment
import numpy as np
import matplotlib.pyplot as plt

state_shape = (25, )
action_shape = (8, )

action_range = (0, 1)
state_range = (-5, -5)

ddpg = Agent(state_shape, action_shape, 
             action_range, state_range, 
             actor_lr=1e-3, critic_lr=5, 
             noise_std=0.2, 
             batch_size=128)

episodes = 200
steps = 200

env = Environment(state_shape, action_shape, 
                  frames=10)

env.open()
episodes_rewards = []

file_name = "test9.txt"
try:
    open(file_name, "x")
except:
    pass

for ep in range(episodes):
    record_file = open(file_name, "a")
    
    env.initialize()
    ep_reward = 0
    
    next_state, _, done = env.get_state()
    env.start_sim()
    
    for sp in range(steps):
        if done:
            break
        
        state = next_state
        
        action = ddpg.step(state)
        env.act(action)
        
        next_state, reward, done = env.get_state()
        ddpg.store_transition(state, action, reward, next_state, done)
        
        ddpg.train()
        ep_reward += reward
        
        print(f"step {sp}: {reward}\n")
        
    env.stop_sim()
    episodes_rewards.append(ep_reward)
    
    print(f"episode {ep}: {ep_reward}\n\n")
    record_file.write(f"episode {ep}: {ep_reward}\n")
    record_file.close()

env.close()

print(episodes_rewards)

#plt.rcParams.update(font = {'family' : 'normal',
#                            'weight' : 'normal',
#                            'size'   : 22})
#
#plt.xlabel('episode', fontsize=22)
#plt.ylabel('reward', fontsize=22)













