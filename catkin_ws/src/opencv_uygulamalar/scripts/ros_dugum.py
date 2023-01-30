#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 28 12:28:30 2022

@author: rumeysa
"""

import rospy
import cv2
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

class Kamera():
    def __init__(self):
        rospy.init_node("kamera_dugumu")
        self.bridge=CvBridge()
        rospy.Subscriber("/realsense/color/image_raw",Image,self.kameraCallback)
        rospy.spin()
        
    def kameraCallback(self,mesaj):
        img = self.bridge.imgmsg_to_cv2(mesaj,"mono8")
        img2 = self.bridge.imgmsg_to_cv2(mesaj,"bgr8")

#        img2 = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
#        img3 = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
#        b,g,r=cv2.split(img)
        #img4=cv2.merge((b,g,r)) #birleştirme
#        cv2.imshow("Robot kamerasi",img)
#        cv2.imshow("Robot GRAY",img2)
#        cv2.imshow("Robot KIRMIZI",img3)
#        cv2.imshow("R",r)
#        kenarlar=cv2.Canny(img,100,200,5)
#        cv2.imshow("Robot kamerasi",img)
#        cv2.imshow("Kenarlar",kenarlar)
        ret,esiklenmis=cv2.threshold(img,127,255,cv2.THRESH_BINARY_INV)
        _,sinirlar,hiyerarsi=cv2.findContours(esiklenmis,cv2.RETR_LIST,
                                            cv2.CHAIN_APPROX_SIMPLE)
        cv2.drawContours(img2,sinirlar,-1,(0,255,0),5)
        cnt=sinirlar[0] #listten numpy array listesine çevrilir
#        print(cnt)
        M=cv2.moments(cnt)
        cx = int(M['m10']/M['m00'])
        cy = int(M['m01']/M['m00'])
#        print(cx,cy)
        cv2.circle(img2,(cx,cy),5,(0,0,255),-1) #-1 içini doldurur
        
        sol = tuple(cnt[cnt[:,:,0].argmin()][0])
        sag = tuple(cnt[cnt[:,:,0].argmax()][0])
        ust = tuple(cnt[cnt[:,:,1].argmin()][0])
        alt = tuple(cnt[cnt[:,:,1].argmax()][0])
#        print(cv2.contourArea(cnt))
#        print(cv2.arcLenght(cnt,True)) #hataaa!!!!
#        cv2.putText(img2,
#                    str(cv2.contourArea(cnt)),
#                    (20,150), 
#                    cv2.FONT_HERSHEY_DUPLEX,
#                    1, 
#                    (255,0,0),
#                    2)
        (x,y),r = cv2.minEnclosingCircle(cnt)
        merkez =(int(x),int(y))
        r=int(r)
        cv2.circle(img2,merkez,r,(255,0,0),2)
        
        x,y,w,h=cv2.boundingRect(cnt)
        cv2.rectangle(img2,(x,y),(x+w,y+h),(0,0,255),2)
        
        cv2.imshow("cam",img2)
        cv2.waitKey(1)
        
        
    
Kamera()
            