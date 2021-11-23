import numpy as np
from .simAPI import sim

_oneshot = sim.simx_opmode_oneshot
_blocking = sim.simx_opmode_blocking

PI = 3.14159265358979
DEG2RAD = PI / 180

class Environment(object):

    def __init__(self, state_shape, action_shape, 
                 dt=0.010, frames=10, 
                 min_vel = 0.10):

        self.state_shape = state_shape
        self.action_shape = action_shape

        self.dt = dt        
        self.frames = frames
        
        self.min_vel = min_vel
        
        self.body_name = "QuadSpider"

        self.joint_num = 8
        self.max_joint_torque = 5
        self.max_joint_velocity = 180 * DEG2RAD
        
        self.w_vx = 20
        self.w_y = 15
        self.w_z = 5
        
        self.w_tor = 0.05

    def open(self):

        # clear communications
        sim.simxFinish(-1)
        # create communication
        self.client_ID = sim.simxStart('127.0.0.1', 19997, True, True, 5000, 5)
        
        self.stop_sim()
        
        # read body's handle
        _, self.body_handle = sim.simxGetObjectHandle(self.client_ID, self.body_name, _blocking)
        
        # read joints' handless
        self.joint_handles = []
        for i in range(self.joint_num):
             _, res = sim.simxGetObjectHandle(self.client_ID, "joint" + str(i), _blocking)
             self.joint_handles.append(res)
        
        sim.simxGetPingTime(self.client_ID)

    def close(self):

        # stop simulation before close communication
        self.stop_sim()
        # close communication
        sim.simxFinish(self.client_ID)
        
        sim.simxGetPingTime(self.client_ID)

    def start_sim(self):

        # set synchronous
#        sim.simxSynchronous(self.client_ID, True)
        # start simulation
        sim.simxStartSimulation(self.client_ID, _oneshot)
        # trigger once
#        sim.simxSynchronousTrigger(self.client_ID)
        
        sim.simxGetPingTime(self.client_ID)

    def stop_sim(self):

        sim.simxStopSimulation(self.client_ID, _oneshot)
        
        sim.simxGetPingTime(self.client_ID)

    def initialize(self):
        for i in range(self.joint_num):
            # set the direction of target velocity
            sim.simxSetJointTargetVelocity(self.client_ID, self.joint_handles[i],
                                           self.max_joint_velocity, _oneshot)
            sim.simxSetJointForce(self.client_ID, self.joint_handles[i], 
                                  self.max_joint_torque, _oneshot)
            
        _, position = sim.simxGetObjectPosition(self.client_ID, self.body_handle, -1, _blocking)
        self.height = position[2]
        
        self.time = 0

    def act(self, act):

        # pause communication until all commands are sent
        sim.simxPauseCommunication(self.client_ID, True)
        
        act = act[0]
        # set target position
        for i in range(self.joint_num):
            tor = (act[i] - 0.5) * 2 * self.max_joint_torque
            # set the direction of target velocity
            if tor >= 0:
                 sim.simxSetJointTargetVelocity(self.client_ID, self.joint_handles[i],
                                                self.max_joint_velocity, _oneshot)
                 sim.simxSetJointForce(self.client_ID, self.joint_handles[i], 
                                       tor, _oneshot)
            else:
                 sim.simxSetJointTargetVelocity(self.client_ID, self.joint_handles[i],
                                                -self.max_joint_velocity, _oneshot)
                 sim.simxSetJointForce(self.client_ID, self.joint_handles[i], 
                                       -tor, _oneshot)
                 
        # restart communication
        sim.simxPauseCommunication(self.client_ID, False)
        # trigger once
        for i in range(self.frames):
            sim.simxSynchronousTrigger(self.client_ID)
            sim.simxGetPingTime(self.client_ID)
            self.time += self.dt

    def get_reward(self, velocity, position, torques):
        
        r_vx = self.w_vx * velocity[0]
        r_y = self.w_y * position[1] * position[1]
        r_z = self.w_z * (position[2] - self.height) * (position[2] - self.height)
        
        r_tor = self.w_tor * np.square(torques).sum()
        
        return r_vx - r_y - r_z - r_tor
    
    def is_done(self, velocity, position, orientation):
        
        if position[0] >= 3:
            return True
        
        if abs(orientation[0]) >= PI / 2:
            return True
        if abs(orientation[1]) >= PI / 2:
            return True
        if abs(orientation[2]) >= PI / 2:
            return True
        
        if self.time >= 2:
            if position[0] < 0:
                return True
            if abs(position[1]) > 0.2:
                return True
            if velocity[0] < 0.05:
                return True
        
        return False

    def get_state(self):

        # read body position
        _, position = sim.simxGetObjectPosition(self.client_ID, self.body_handle, -1, _blocking)
        position = np.array(position)
        # read body velocity
        _, velocity, _ = sim.simxGetObjectVelocity(self.client_ID, self.body_handle, _blocking)
        velocity = np.array(velocity)
        # read body orientation
        _, orientation = sim.simxGetObjectOrientation(self.client_ID, self.body_handle, -1, _blocking)
        orientation = np.array(orientation)

        joint_torques = []
        joint_velocities = []
        for i in range(self.joint_num):
            # read joint force
            _, tor = sim.simxGetJointForce(self.client_ID, self.joint_handles[i], _blocking)
            # read joint velocity
            _, vel = sim.simxGetObjectFloatParameter(self.client_ID, self.joint_handles[i], sim.sim_jointfloatparam_velocity, _blocking)
            vel *= DEG2RAD
            # record joint state
            joint_torques.append(tor)
            joint_velocities.append(vel)
            
        joint_torques = np.array(joint_torques)
        joint_velocities = np.array(joint_velocities)
        
        sim.simxGetPingTime(self.client_ID)

        return np.concatenate([position, velocity, orientation, 
                               joint_torques, joint_velocities]).reshape((1, *self.state_shape)), \
               self.get_reward(velocity, position, joint_torques), \
               self.is_done(velocity, position, orientation)

