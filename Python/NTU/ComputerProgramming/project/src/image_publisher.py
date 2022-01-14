#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Image

import cv2
from cv_bridge import CvBridge, CvBridgeError

class ImagePublisher:

    def __init__(self, dimension):
        self.pub0 = rospy.Publisher('cam0/image_raw', Image, queue_size=10)
        self.pub1 = rospy.Publisher('cam1/image_raw', Image, queue_size=10)

        self.cam = cv2.VideoCapture(0)

        # dimension = (752, 480)
        # self.cam.set(cv2.CAP_PROP_FRAME_WIDTH, dimension[0])
        # self.cam.set(cv2.CAP_PROP_FRAME_HEIGHT, dimension[1])

    def publish(self, stamp):
        ret, img = self.cam.read()
        img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        image0 = CvBridge().cv2_to_imgmsg(img, encoding="mono8")
        image1 = CvBridge().cv2_to_imgmsg(img, encoding="mono8")
        # image = CvBridge().cv2_to_imgmsg(img)

        image0.header.stamp = stamp
        image0.header.frame_id = "cam0"

        image1.header.stamp = stamp
        image1.header.frame_id = "cam1"

        self.pub0.publish(image0)
        self.pub1.publish(image1)


# if __name__ == "__main__":
#     dimension = (1280, 720)
#     image_publisher = ImagePublisher(dimension)
# 
#     rospy.init("")

# import rospy
# from sensor_msgs.msg import Image

# import cv2
# from cv_bridge import CvBridge, CvBridgeError

# def image_publisher():
#     cam0_pub = rospy.Publisher('cam0/image_raw', Image, queue_size=10)
#     rospy.init_node('image_publisher', anonymous=False)
#     rate = rospy.Rate(20) # 10hz

#     cam = cv2.VideoCapture(0)

#     dimension = (1280, 720)
#     cam.set(cv2.CAP_PROP_FRAME_WIDTH, dimension[0])
#     cam.set(cv2.CAP_PROP_FRAME_HEIGHT, dimension[1])

#     while not rospy.is_shutdown():

#         ret, img = cam.read()
#         img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
#         image = CvBridge().cv2_to_imgmsg(img)

#         image.header.stamp = rospy.Time.from_sec(rospy.get_time())

#         image.header.frame_id = "cam0"

#         cam0_pub.publish(image)
#         rospy.loginfo("{w} {h}".format(w=image.width, h=image.height))
#         rate.sleep()

# if __name__ == '__main__':
#     try:
#         image_publisher()
#     except rospy.ROSInterruptException:
#         pass
