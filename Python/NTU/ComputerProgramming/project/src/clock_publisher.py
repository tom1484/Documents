#!/usr/bin/env python
import rospy

import time
from std_msgs.msg import Time
from rosgraph_msgs.msg import Clock

class ClockPublisher:

    def __init__(self):
        self.zero_time = rospy.get_time()
        self.pub = rospy.Publisher('clock', Clock, queue_size=10)

    def publish(self, stamp):

        # timepassed_dat = rospy.get_time() - self.zero_time
        time_dat = stamp

        self.pub.publish(time_dat)

if __name__ == "__main__":
    try:
        rospy.init_node("clock", anonymous=False)
        clock_pub = ClockPublisher()

        # rate = rospy.Rate(200)
        # while not raspy.is_shutdown():
        #     clock_pub.publish(rospy.Time.from_sec(rospy.get_time()))
        #     rate.sleep()

        rate = 200
        period = 1.0 / rate

        zero_time = time.time()
        counter = 0
        while not rospy.is_shutdown():
            clock_pub.publish(rospy.Time.from_sec(time.time()))
            counter += 1
            while (time.time() - zero_time) / period < counter:
                pass

    except (rospy.ROSInterruptException, KeyboardInterrupt):
        rospy.signal_shutdown("Process ended")
        sys.exit()

    except:
        pass

