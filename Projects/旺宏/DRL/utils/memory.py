import numpy as np

class Buffer(object):
    def __init__(self, maxlen, shape):
        self.maxlen = maxlen
        self.start = 0
        self.length = 0
        self.data = np.zeros((maxlen,) + shape)

    def __len__(self):
        return self.length

    def __getitem__(self, idx):
        if idx < 0 or idx >= self.length:
            raise KeyError()
        return self.data[(self.start + idx) % self.maxlen]

    def get_batch(self, idxs):
        return self.data[(self.start + idxs) % self.maxlen]

    def append(self, v):
        if self.length < self.maxlen:
            # We have space, simply increase the length.
            self.length += 1
        elif self.length == self.maxlen:
            # No space, "remove" the first item.
            self.start = (self.start + 1) % self.maxlen
        else:
            # This should never happen.
            raise RuntimeError()
        self.data[(self.start + self.length - 1) % self.maxlen] = v


def array_min2d(x):
    x = np.array(x)
    if x.ndim >= 2:
        return x
    return x.reshape(-1, 1)


class Memory(object):
    def __init__(self, limit, action_shape, state_shape):
        self.limit = limit

        self.bf_states = Buffer(limit, shape=state_shape)
        self.bf_actions = Buffer(limit, shape=action_shape)
        self.bf_rewards = Buffer(limit, shape=(1, ))
        self.bf_done = Buffer(limit, shape=(1, ))
        self.bf_next_states = Buffer(limit, shape=state_shape)

    def sample(self, batch_size):
        # Draw such that we always have a proceeding element.
        batch_idxs = np.random.randint(self.nb_entries - 2, size=batch_size)

        states = self.bf_states.get_batch(batch_idxs)
        next_states = self.bf_next_states.get_batch(batch_idxs)
        actions = self.bf_actions.get_batch(batch_idxs)
        rewards = self.bf_rewards.get_batch(batch_idxs)
        done = self.bf_done.get_batch(batch_idxs)

        return array_min2d(states), array_min2d(actions), \
               array_min2d(rewards), array_min2d(next_states), array_min2d(done)

    def append(self, state, action, reward, next_state, done, training=True):
        if not training:
            return

        self.bf_states.append(state)
        self.bf_actions.append(action)
        self.bf_rewards.append(reward)
        self.bf_next_states.append(next_state)
        self.bf_done.append(done)

    def __len__(self):
        return len(self.bf_states)

    @property
    def nb_entries(self):
        return len(self.bf_states)
