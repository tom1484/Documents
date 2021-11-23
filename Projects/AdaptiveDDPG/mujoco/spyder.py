from mujoco.model import MujocoModel
import numpy as np


class Spyder(MujocoModel):

    def __init__(self, xml_model_path):
        super(Spyder, self).__init__(xml_model_path)
        self.body_name = 'spyder'

        self.set_obs_space()
        self.set_action_space()

    def set_action_space(self):
        self.action_space = self.data.ctrl.shape[0]

    def set_obs_space(self):
        self.obs_space = self.get_obs().shape[0]

    def step(self, action, n_steps):
        self.act(action)
        self.do_simulations(n_steps)

        obs = self.get_obs()
        reward = self.get_reward(obs)
        is_done = self.is_done()

        return obs, reward, is_done

    def get_obs(self):
        body_veloc = self.data.get_body_xvelp(self.body_name)
        body_orien = self.data.get_body_xvelr(self.body_name)

        motor_posit = self.data.qpos
        motor_veloc = self.data.qvel

        obs = np.concatenate([body_veloc, body_orien,
                              motor_posit, motor_veloc])

        return obs

    def get_reward(self, obs):
        return 0

    def is_done(self):
        return False
