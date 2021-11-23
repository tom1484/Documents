import os

import numpy as np

from mujoco.spyder import Spyder

from ddpg.models import Actor, Critic

# ====================================================================================================

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# ====================================================================================================

env = Spyder(xml_model_path="./mujoco/xml/spyder.xml")
# env.create_viewer(speed=4.0)

# ====================================================================================================

action_space = env.action_space
obs_space = env.obs_space

actor = Actor(action_space=action_space,
              obs_space=obs_space,
              hidden_layers=[128, 64])
critic = Critic(action_space=action_space,
                obs_space=obs_space,
                hidden_layers=[128, 64])

obs = np.random.normal(size=(1, obs_space))
actions = np.random.normal(size=(1, action_space))

print(actor(obs))
print(critic(obs, actions))
