#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 27 17:55:09 2022

@author: rumeysa
"""

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class RobotKamera():
    def __init__(self):
        rospy.init_node("kamera")
        rospy.Subscriber("camera/rgb/image_raw",Image,self.kameraCallback)
        self.bridge=CvBridge()
        rospy.spin()
    def kameraCallback(self,mesaj):
        self.foto=self.bridge.imgmsg_to_cv2(mesaj,"bgr8")
        cv2.imshow("Robot kamerasi",self.foto)
        cv2.waitKey(1)

RobotKamera()