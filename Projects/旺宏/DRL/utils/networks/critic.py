from tensorflow.keras.layers import Dense, Input, Add
from tensorflow.keras.models import Model

class Critic(object):

    def __init__(self, state_shape, action_shape, hidden_units=(300, 600)):

        # store parameters
        self.state_shape = state_shape
        self.action_shape = action_shape
        self.hidden = hidden_units

        # generate model
        self.model = self.generate_model()

    def __call__(self, state, action):
        
        return self.model([state, action])
    
    def get_trainable_weights(self):
        
        return self.model.trainable_weights
    
    def set_weights(self, weights):
        
        self.model.set_weights(weights)
    
    def get_weights(self):
        
        return self.model.weights

    def generate_model(self):

        # input state
        s_input_layer = Input(shape=self.state_shape,
                              name="critic_input_state")
        # input action
        a_input_layer = Input(shape=self.action_shape,
                              name="critic_input_action")
        # state hidden layer
        s_layer = Dense(self.hidden[0], activation='relu',
                        kernel_initializer='random_normal',
                        bias_initializer='zeros',
                        name="critic_state_hidden_layer")(s_input_layer)
        # action hidden layer
        a_layer = Dense(self.hidden[0], activation='linear',
                        kernel_initializer='random_normal',
                        bias_initializer='zeros',
                        name="critic_action_hidden_layer")(a_input_layer)
        # add state hidden layer and action hidden layer
        hidden = Add()([s_layer, a_layer])
        # hidden layer2
        hidden = Dense(self.hidden[1], activation='relu',
                      kernel_initializer='random_normal',
                      bias_initializer='zeros',
                      name="critic_hidden_layer2")(hidden)
        # output layer
        output_layer = Dense(1, activation='linear', 
                             kernel_initializer='random_normal',
                             bias_initializer='zeros',
                             name="critic_output")(hidden)
        # create model
        model = Model(inputs=[s_input_layer, a_input_layer],
                      outputs=output_layer)

        return model

