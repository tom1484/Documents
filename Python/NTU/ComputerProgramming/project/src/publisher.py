#!/usr/bin/env python
import rospy

from imu_publisher import ImuPublisher
from camera_info_publisher import CameraInfoPublisher
from image_publisher import ImagePublisher

from threading import Thread
import sys


if __name__ == '__main__':
    try:
        rospy.init_node('publisher', anonymous=False, disable_signals=True)

        dimension = (640, 480)

        imu_pub = ImuPublisher()
        image_pub = ImagePublisher(dimension)
        camera_pub = CameraInfoPublisher()

        counter = 0
        rate = rospy.Rate(200)
        while not rospy.is_shutdown():
            stamp = rospy.Time.from_sec(rospy.get_time())
            
            if counter % 1 == 0:
                imu_pub.publish(stamp)
            if counter % 10 == 0:
                image_pub.publish(stamp)
            if counter % 200 == 0:
                camera_pub.publish(stamp)

            rate.sleep()
            counter += 1

    except (rospy.ROSInterruptException, KeyboardInterrupt):
        rospy.signal_shutdown("Process ended")
        sys.exit()
    except:
        sys.exit()




