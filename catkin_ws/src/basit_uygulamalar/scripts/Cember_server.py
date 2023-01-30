#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 27 10:27:32 2022

@author: rumeysa
"""
import rospy
from geometry_msgs.msg import Twist
from basit_uygulamalar.srv import CemberHareket

def cemberFonksiyonu(istek):
    hiz_mesaji=Twist()
    linear_hiz=0.5
    hiz_mesaji.linear.x=linear_hiz
    yaricap=istek.yaricap
    # w = v/r
    hiz_mesaji.angular.z=linear_hiz/yaricap
    while not rospy.is_shutdown():
        pub.publish(hiz_mesaji)
        
rospy.init_node("cember_hareket")
pub = rospy.Publisher("cmd_vel",Twist,queue_size=10)
rospy.Service("cember_servis",CemberHareket,cemberFonksiyonu)
rospy.spin()

