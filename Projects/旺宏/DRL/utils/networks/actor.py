from tensorflow.keras.models import Model
from tensorflow.keras.layers import Dense, Input

class Actor(object):

    def __init__(self, state_shape, action_shape, hidden_units=(300, 600)):

        # store parameters
        self.state_shape = state_shape
        self.action_shape = action_shape
        self.hidden = hidden_units

        # generate model
        self.model = self.generate_model()

    def __call__(self, state):
        
        return self.model(state)
    
    def get_weights(self):
        
        return self.model.weights
    
    def get_trainable_weights(self):
        
        return self.model.trainable_weights
    
    def set_weights(self, weights):
        
        self.model.set_weights(weights)

    def generate_model(self):

        # input state
        input_layer = Input(shape=self.state_shape,
                            name="actor_input_state")
        # hidden layer1
        layer = Dense(self.hidden[0], activation='relu',
                      kernel_initializer='random_normal',
                      bias_initializer='zeros',
                      name="actor_hedden1")(input_layer)
        # hidden layer2
        layer = Dense(self.hidden[1], activation='relu',
                      kernel_initializer='random_normal',
                      bias_initializer='zeros',
                      name="actor_hedden2")(layer)
        # output layer
        output_layer = Dense(self.action_shape[0], activation='sigmoid',
                             kernel_initializer='random_normal',
                             bias_initializer='zeros',
                             name="actor_output")(layer)
        # create model
        model = Model(inputs=input_layer, outputs=output_layer)

        return model
