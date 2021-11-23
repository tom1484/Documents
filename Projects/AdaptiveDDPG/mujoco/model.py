from mujoco_py import load_model_from_path
from mujoco_py import MjSim, MjViewer


class MujocoModel:

    def __init__(self, xml_model_path):
        self.model = load_model_from_path(xml_model_path)
        self.sim = MjSim(self.model)
        self.data = self.sim.data

    def create_viewer(self, speed=1):
        self.viewer = MjViewer(self.sim)
        self.viewer.set_speed(speed)

    def render(self):
        self.viewer.render()

    def act(self, action):
        self.sim.data.ctrl[:] = action
        self.sim.step()

    def do_simulations(self, n_steps):
        for _ in range(n_steps):
            self.sim.step()

