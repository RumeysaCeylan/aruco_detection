#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 28 17:25:20 2022

@author: rumeysa
"""

import cv2
import numpy as np
#sari=np.uint8([[[0,255,255]]])
#hsv=cv2.cvtColor(sari,cv2.COLOR_BGR2HSV)
import rospy
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from cv_bridge import CvBridge

class SeritTakip():
    def __init__(self):
        rospy.init_node("serit_takip")
        self.bridge=CvBridge()
        rospy.Subscriber("/realsense/color/image_raw",Image,self.kameraCallback)
        self.pub=rospy.Publisher("cmd_vel",Twist,queue_size=10)
        self.hiz_mesaji=Twist()
        rospy.spin()
    def kameraCallback(self,mesaj):
        img = self.bridge.imgmsg_to_cv2(mesaj,"bgr8")
        hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
        """
        alt_sari=np.array([26, 100, 100])
        ust_sari=np.array([97, 255, 255])
        alt_sari=np.array([45, 100, 100])
        ust_sari=np.array([75, 255, 255])
        

       """
        alt_sari=np.array([10, 100, 100])
        ust_sari=np.array([38, 255, 255])
        maske = cv2.inRange(hsv,alt_sari,ust_sari)
        #sonuc=cv2.bitwise_and(img,img,mask=maske)
        h,w,d=img.shape

        M=cv2.moments(maske)
        if M['m00']>0 : 
            cx=int(M['m10'])/int(M['m00'])
            cy=int(M['m01'])/int(M['m00'])
            #cv2.circle(img,(cx,cy),5,(255,0,0),-1)
            cv2.rectangle(img, (int(w/2),int(h/2)), (cx + w/2, cy + h/2), (200,0,50), 3)
            cv2.circle(img,(int(cx/2),int(cy/2)),5,(0,0,255),-1)
            a = cx+(w/2)  # Çerçeve genişliğinin yarısı
            b = cy+(h/2)  # Çerçeve yüksekliğinin yarısı
            cv2.circle(img,((int(a)),(int(b))), 1, (0,0,255), 6)  #ORTA NOKTA HESAPLAMAK İÇİN YAPTIĞIM İŞLEM KISMI
            sapma=cx - w/2
            cv2.putText(
                        img,
                       "plant",
                       (cx,cy),
                        cv2.FONT_HERSHEY_COMPLEX_SMALL,
                        1.3,
                        (200,100,0),
                        2,
                        cv2.LINE_AA
                        )
            self.hiz_mesaji.linear.x=0.2
            self.hiz_mesaji.angular.z=-sapma/100
            self.pub.publish(self.hiz_mesaji)
        else:
            self.hiz_mesaji.linear.x=0.0
            self.hiz_mesaji.angular.z=0.0

            self.pub.publish(self.hiz_mesaji)
        cv2.imshow("org",img)
        
       # cv2.imshow("maske",maske)
       #cv2.imshow("sonuc",sonuc)
        cv2.waitKey(1)

SeritTakip()
        
        
        
