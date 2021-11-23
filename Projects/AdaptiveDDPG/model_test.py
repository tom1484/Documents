from mujoco_py import load_model_from_path
from mujoco_py import MjSim, MjViewer

import numpy as np


model = load_model_from_path(".mujoco.py/xml/spyder.xml")
sim = MjSim(model)

s = sim.data.ctrl.shape[0]

viewer = MjViewer(sim)

for _ in range(1000000):

    act = np.random.normal(size=s)

    sim.data.ctrl[:] = act

    viewer.render()
    sim.step()
