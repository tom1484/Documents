#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Imu

from imu_reader import ImuReader

class ImuPublisher:

    def __init__(self):
        self.pub = rospy.Publisher('imu0', Imu, queue_size=10)

        self.imu_reader = ImuReader()

    def publish(self, stamp):

        imu = Imu()
        imu.header.stamp = stamp
        imu.header.frame_id = "imu4"

        imu_acc, imu_gyro = self.imu_reader.read()

        imu.orientation.x = 0
        imu.orientation.y = 0
        imu.orientation.z = 0
        imu.orientation.w = 1

        imu.orientation_covariance = [99999.9, 0.0, 0.0, 0.0, 99999.9, 0.0, 0.0, 0.0, 99999.9]

        imu.linear_acceleration.x =  0.0
        imu.linear_acceleration.y =  0.0
        imu.linear_acceleration.z = -9.81
        imu.linear_acceleration.x = imu_acc[0]
        imu.linear_acceleration.y = imu_acc[1]
        imu.linear_acceleration.z = imu_acc[2]
        
        imu.angular_velocity.x = 0.0
        imu.angular_velocity.y = 0.0
        imu.angular_velocity.z = 0.0
        imu.angular_velocity.x = imu_gyro[0]
        imu.angular_velocity.y = imu_gyro[1]
        imu.angular_velocity.z = imu_gyro[2]

        self.pub.publish(imu)



