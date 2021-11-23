from tensorflow.keras import Model
from tensorflow.keras.layers import Input, Dense, Add
from tensorflow.keras.activations import tanh


class Actor:
    
    def __init__(self, action_space, obs_space, hidden_layers):
        self.action_space = action_space
        self.obs_space = obs_space

        # define network
        input_layer = Input(shape=self.obs_space)

        hidden_layer = input_layer
        for h_units in hidden_layers:
            hidden_layer = Dense(units=h_units, activation=tanh,
                                 kernel_initializer='random_normal')(hidden_layer)

        output_layer = Dense(units=self.action_space, activation=tanh,
                             kernel_initializer='random_normal')(hidden_layer)

        self.model = Model(inputs=[input_layer],
                           outputs=[output_layer])

    def __call__(self, obs):
        return self.model([obs])

    @property
    def trainable_variables(self):
        return self.model.trainable_variables


class Critic:
    def __init__(self, action_space, obs_space, hidden_layers):
        self.action_space = action_space
        self.obs_space = obs_space

        # network
        input_layer_o = Input(shape=self.obs_space)
        input_layer_a = Input(shape=self.action_space)

        hidden_layer_o = Dense(units=hidden_layers[0], activation=tanh,
                               kernel_initializer='random_normal')(input_layer_o)
        hidden_layer_a = Dense(units=hidden_layers[0], activation=tanh,
                               kernel_initializer='random_normal')(input_layer_a)

        hidden_layer = Add()([hidden_layer_o, hidden_layer_a])
        for h_units in hidden_layers[1:]:
            hidden_layer = Dense(units=h_units, activation=tanh,
                                 kernel_initializer='random_normal')(hidden_layer)

        output_layer = Dense(units=1, activation=tanh,
                             kernel_initializer='random_normal')(hidden_layer)

        self.model = Model(inputs=[input_layer_o, input_layer_a],
                           outputs=[output_layer])

    def __call__(self, obs, actions):
        return self.model([obs, actions])

    @property
    def trainable_variables(self):
        return self.model.trainable_variables
