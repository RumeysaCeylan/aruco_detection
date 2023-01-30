#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 26 17:48:11 2022

@author: rumeysa
"""

import rospy
from geometry_msgs.msg import Twist #hız verisi
from nav_msgs.msg import Odometry #konum verisi
from basit_uygulamalar.msg import Mesafe

class HedefeGit():
    def __init__(self):
        rospy.init_node("duz_git")
        self.hedef_konum=5.0
        self.current_konum=0.0
        self.kontrol=True
        rospy.Subscriber("odom",Odometry,self.odomCallback)
        rospy.Subscriber("mesafe_git",Mesafe,self.mesafeCallback)
        pub=rospy.Publisher("cmd_vel",Twist,queue_size=10)
        hiz_mesaji=Twist()
        rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            if self.kontrol:
                hiz_mesaji.linear.x=0.5
                pub.publish(hiz_mesaji)
            else:
                hiz_mesaji.linear.x=0.0
                pub.publish(hiz_mesaji)
                rospy.loginfo("Hedefe varildi ")
            rate.sleep()
    def odomCallback(self,message):
        self.current_konum=message.pose.pose.position.x
        if self.current_konum<=self.hedef_konum:
            self.kontrol=True
        else:
            self.kontrol=False
    def mesafeCallback(self,message):
        self.hedef_konum=message.mesafe
        
try:
    HedefeGit()
except rospy.ROSInterruptException:
    print("Dugum sonlandı")