import numpy as np
from matplotlib import pyplot as plt

def standadization(X):
    mu = np.mean(X)
    sigma = np.std(X)
    return (X - mu) / sigma

def generateREWARDS(ACTION_SPACE):
    # generate and standardize rewards of actions
    REWARDS = np.random.normal(loc=0, scale=1, size=ACTION_SPACE)
    REWARDS = standadization(REWARDS)
    
    return REWARDS

#calculate rewards
def bandit(action, REWARDS):
    # apply normal distribution to rewards
    return np.random.normal(loc=REWARDS[action], scale=0.5)

ACTION_SPACE = 10
REWARDS = generateREWARDS(ACTION_SPACE)

# generate data of visualization of rewards
REWARDS_actions = []
REWARDS_rewards = []
for i in range(1000):
    action = np.random.randint(0, ACTION_SPACE)
    REWARDS_actions.append(action + (np.random.random() - 0.5) * 0.4)
    REWARDS_rewards.append(bandit(action, REWARDS))
    
plt.figure(figsize=(10, 6))
plt.scatter(REWARDS_actions, REWARDS_rewards, s=1)
plt.show()


def learn_epoch(epochs, epsilon, REWARDS, initialQ):
    Q = np.ones(ACTION_SPACE) * initialQ
    N = np.zeros(ACTION_SPACE)
    rewards = np.zeros(epochs)

    for i in range(epochs):
        # decide the way of choosing action
        decision = np.random.random()
        if decision >= epsilon:
            # choose action by epsilon
            action = np.argmax(Q)
        else:
            # choose a random action
            action = np.random.randint(0, ACTION_SPACE)
        
        # calculate reward of action
        R = bandit(action, REWARDS)
        rewards[i] = R
        
        # update tables
        N[action] += 1
        Q[action] = Q[action] + (R - Q[action]) / N[action]
    
    return rewards

def learn(epochs, epsilon, n_samples, initialQ):
    average_rewards = np.zeros(epochs)
    for i in range(n_samples):
        REWARDS = generateREWARDS(ACTION_SPACE)
        average_rewards += learn_epoch(epochs, epsilon, REWARDS, initialQ) / n_samples
    
    plt.figure(figsize=(10, 6))
    plt.plot(average_rewards)
    x1, x2, y1, y2 = plt.axis()
    plt.axis((x1, x2, -1, y2))
    plt.show()

learn(400, 0, 500, 5)
learn(400, 0.01, 500, 0)







