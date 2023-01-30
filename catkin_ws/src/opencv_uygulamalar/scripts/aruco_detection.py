#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 27 12:32:28 2022

@author: rumeysa
"""
import cv2
import rospy
import numpy as np
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from cv_bridge import CvBridge
#from find_object_2d.msg import ObjectsStamped
from cv2 import aruco

class Detection():
    
    def __init__(self):
        rospy.init_node("detection")
        self.bridge=CvBridge()
        rospy.Subscriber("camera/rgb/image_raw",Image,self.aruco_detection)
        self.pub=rospy.Publisher("cmd_vel",Twist,queue_size=10)
        self.hiz_mesaji=Twist()
        rospy.spin()

    def aruco_detection(self,message,matrix_coefficient,distortion_coefficient): 
        marker_dict = aruco.Dictionary_get(aruco.DICT_4X4_50)
        param_markers = aruco.DetectorParameters_create()
        img = self.bridge.imgmsg_to_cv2(message,"bgr8")
        gray_frame=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
        
  
        marker_corners, marker_IDs, reject = aruco.detectMarkers(
                gray_frame,marker_dict,parameters=param_markers,
                cameraMatrix=matrix_coefficient,
                distCoeff=distortion_coefficient)
       
        
        if marker_corners:
            for ids, corners in zip(marker_IDs, marker_corners):
                cv2.polylines(img, [corners.astype(np.int32)],True,(0,255,255),4,cv2.LINE_AA)
                print(corners.shape)
                corners = corners.reshape(4,2)
                corners=corners.astype(int)
                top,right=corners[0].ravel()
                print(top,right)
                for i in range(0,len(ids)):
                    
                    rvec, tvec, markerPoints = aruco.estimatePoseSingleMarkers(corners, 0.02,
                                                                               matrix_coefficient,
                                                                               distortion_coefficient)
                    (rvec - tvec).any()  # get rid of that nasty numpy value array error
                    aruco.drawDetectedMarkers(img, corners)  # Draw A square around the markers
                    aruco.drawAxis(img, matrix_coefficient, distortion_coefficient,rvec, tvec, 0.01)
       
                cv2.putText(
                        img,
                        "id:  "+str(ids[0]),
                    (top,right),
                        cv2.FONT_HERSHEY_COMPLEX_SMALL,
                        1.3,
                        (200,100,0),
                        2,
                        cv2.LINE_AA
                        )
        
        cv2.imshow("img",img)
        cv2.waitKey(1)
         


       


Detection()
        
