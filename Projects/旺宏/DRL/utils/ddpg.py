import tensorflow as tf
import numpy as np

from .networks.actor import Actor
from .networks.critic import Critic
from utils.memory import Memory

from tensorflow.keras.losses import MSE
from tensorflow.keras.optimizers import Adam

class DDPG(object):

    def __init__(self, 
                 state_shape, action_shape,
                 action_range, state_range,
                 noise_std=0.05, 
                 actor_lr=1e-4, critic_lr=1e-3,
                 actor_hidden_units=(300, 600), critic_hidden_units=(300, 600),
                 batch_size=128, discount=0.99, memory_size=1e6, tau=0.001):

        self.discount = discount
        self.batch_size = batch_size
        self.tau = tau

        self.state_shape = state_shape
        self.action_shape = action_shape

        self.action_range = action_range
        self.state_range = state_range
        
        self.noise_std = noise_std

        # create actor
        self.actor = Actor(state_shape=state_shape, action_shape=action_shape, hidden_units=actor_hidden_units)
        self.target_actor = Actor(state_shape=state_shape, action_shape=action_shape, hidden_units=actor_hidden_units)
        # create critic
        self.critic = Critic(state_shape=state_shape, action_shape=action_shape, hidden_units=critic_hidden_units)
        self.target_critic = Critic(state_shape=state_shape, action_shape=action_shape, hidden_units=critic_hidden_units)

        self.actor_optimizer = Adam(learning_rate=actor_lr)
        self.critic_optimizer = Adam(learning_rate=critic_lr)

        self.memory = Memory(int(memory_size), action_shape, state_shape)

    def store_transition(self, state, action, reward, next_state, done):
        
        self.memory.append(state, action, reward, next_state, done)

    def step(self, state, apply_noise=True):
        
        action = self.actor(state)
        if apply_noise:
            action += tf.random.normal(self.action_shape, stddev=self.noise_std)
        action = tf.clip_by_value(action, self.action_range[0], self.action_range[1])

        return action

    def train(self):
        
        if len(self.memory) >= self.batch_size:
            states, actions, rewards, next_states, done = self.memory.sample(self.batch_size)
            ct = self.train_critic(states, actions, next_states, rewards, done)
            at = self.train_actor(states)
            self.update_target_models()
            
            return ct, at

    def train_critic(self, states, actions, next_states, rewards, done):

        # q target
        next_actions = self.target_actor(next_states)
        next_q = self.target_critic(next_states, next_actions)
        q_targets = rewards + (1 - done) * self.discount * next_q

        weights = self.critic.get_trainable_weights()
        with tf.GradientTape() as tape:
            tape.watch(weights)
            # compute MSE loss
            q_values = self.critic.model([states, actions])
            loss = MSE(q_targets, q_values)
        # compute gradients
        grads = tape.gradient(loss, weights)
        
        tot = 0
        for w in grads:
            tot += tf.math.reduce_mean(tf.abs(w))
        tot /= len(grads)

        self.critic_optimizer.apply_gradients(zip(grads, weights))
        return np.asarray(tot)

    def train_actor(self, states):

        weights = self.actor.get_trainable_weights()
        with tf.GradientTape() as tape:
            tape.watch(weights)
            # compute policy value
            actions = self.actor(states)
            q_values = self.critic(states, actions)
            loss = -tf.math.reduce_mean(q_values)
        # compute policy gradients
        grads = tape.gradient(loss, weights)

        self.actor_optimizer.apply_gradients(zip(grads, weights))
        return np.asarray(tot)

    def initialize(self):
        
        actor = self.actor.get_trainable_weights()
        target_actor = self.target_actor.get_trainable_weights()
        for weight, target_weight in zip(actor, target_actor):
            target_weight.assign(weight)
            
        critic = self.critic.get_trainable_weights()
        target_critic = self.target_critic.get_trainable_weights()
        for weight, target_weight in zip(critic, target_critic):
            target_weight.assign(weight)

    def update_target_models(self):
        
        actor = self.actor.get_trainable_weights()
        target_actor = self.target_actor.get_trainable_weights()
        for weight, target_weight in zip(actor, target_actor):
            target_weight.assign((1. - self.tau) * target_weight + self.tau * weight)
            
        critic = self.critic.get_trainable_weights()
        target_critic = self.target_critic.get_trainable_weights()
        for weight, target_weight in zip(critic, target_critic):
            target_weight.assign((1. - self.tau) * target_weight + self.tau * weight)











