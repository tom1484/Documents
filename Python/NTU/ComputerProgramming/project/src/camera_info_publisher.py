#!/usr/bin/env python
import rospy
from sensor_msgs.msg import CameraInfo

class CameraInfoPublisher:

    def __init__(self):
        self.pub0 = rospy.Publisher('cam0/camera_info', CameraInfo, queue_size=10)
        self.pub1 = rospy.Publisher('cam1/camera_info', CameraInfo, queue_size=10)

    def publish(self, stamp):

        cam0_info = CameraInfo()
        cam1_info = CameraInfo()
        
        dimension = (640, 480)
        distortion_model = "plumb_bob"

        K = [502.91079400474706, 0.0, 321.32347275971335, 0.0, 502.4836297325979, 237.03515056116922, 0.0, 0.0, 1.0]
        D = [0.1812110692656436, -0.39943342956103123, -0.0025627573305456075, -0.000716921849030986]
        R = [1, 0, 0, 0, 1, 0, 0, 0, 1]
        P = [502.91079400474706, 0.0, 321.32347275971335, 0.0, 0.0, 502.4836297325979, 237.03515056116922, 0.0, 0.0, 0.0, 1.0, 0.0]

        (cam0_info.width, cam0_info.height) = dimension
        cam0_info.distortion_model = distortion_model
        
        cam0_info.K = K
        cam0_info.D = D
        cam0_info.R = R
        cam0_info.P = P

        cam0_info.header.stamp = stamp
        cam0_info.header.frame_id = "cam0"

        (cam1_info.width, cam1_info.height) = dimension
        cam1_info.distortion_model = distortion_model
        cam1_info.K = K
        cam1_info.D = D
        cam1_info.R = R
        cam1_info.P = P

        cam1_info.header.stamp = stamp
        cam1_info.header.frame_id = "cam1"

        self.pub0.publish(cam0_info)
        self.pub1.publish(cam1_info)

# import rospy
# from sensor_msgs.msg import CameraInfo

# def camera_info_provider():
#     cam0_pub = rospy.Publisher('cam0/camera_info', CameraInfo, queue_size=10)
#     cam1_pub = rospy.Publisher('cam1/camera_info', CameraInfo, queue_size=10)
#     rospy.init_node('camerainfo_publisher', anonymous=False)
#     rate = rospy.Rate(1) # 10hz

#     while not rospy.is_shutdown():

#         cam0_info = CameraInfo()
#         cam1_info = CameraInfo()
        
#         dimension = (1280, 720)
#         distortion_model = "plumb_bob"
#         K = [1276.704618338571, 0, 634.8876509199106, 0, 1274.342831275509, 379.8318028940378, 0, 0, 1]
#         # D = [0.1465167016954302, -0.2847343180128725, 0.00134017721235817, -0.004309553450829512, 0]
#         D = [0.1465167016954302, -0.2847343180128725, 0.00134017721235817, -0.004309553450829512]
#         R = [1, 0, 0, 0, 1, 0, 0, 0, 1]
#         P = [1300.127197265625, 0, 630.215390285608, 0, 0, 1300.670166015625, 380.1702884455881, 0, 0, 0, 1, 0]

#         (cam0_info.width, cam0_info.height) = dimension
#         cam0_info.distortion_model = distortion_model
        
#         cam0_info.K = K
#         cam0_info.D = D
#         cam0_info.R = R
#         cam0_info.P = P

#         cam0_info.header.frame_id = "cam0"

#         (cam1_info.width, cam1_info.height) = dimension
#         cam1_info.distortion_model = distortion_model
#         cam1_info.K = K
#         cam1_info.D = D
#         cam1_info.R = R
#         cam1_info.P = P

#         cam1_info.header.frame_id = "cam1"

#         cam0_pub.publish(cam0_info)
#         cam1_pub.publish(cam1_info)
        
#         rospy.loginfo("Published camera info.")
#         rate.sleep()

# if __name__ == '__main__':
#     try:
#         camera_info_provider()
#     except rospy.ROSInterruptException:
#         pass
