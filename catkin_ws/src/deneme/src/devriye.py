#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 27 12:24:42 2022

@author: rumeysa
"""
import rospy
from geometry_msgs.msg import Twist

def volta():
    rospy.init_node("volta_at")
    pub = rospy.Publisher("cmd_vel",Twist,queue_size=10)
    hiz_mesaji =Twist()
    robot_hiz=0.25
    volta_uzunluk = rospy.get_param("/VoltaUzunluk")
    volta_sayisi = rospy.get_param("/VoltaSayisi")
    volta_sayaci=0
    rospy.loginfo("devriye gezmeye baslandi ")
    
    
    while volta_sayaci <=volta_sayisi:
        t0=rospy.Time.now().to_sec()
        yer_degistirme=0
        if volta_sayaci %2 ==0:
            hiz_mesaji.linear.x=robot_hiz
        else:
            hiz_mesaji.linear.x=-robot_hiz
        while yer_degistirme < volta_uzunluk:
            pub.publish(hiz_mesaji)
            t1=rospy.Time.now().to_sec()
            yer_degistirme=robot_hiz*(t1-t0)
        hiz_mesaji.linear.x=0
        pub.publish(hiz_mesaji)
        volta_sayaci=volta_sayaci+1
        rospy.loginfo("devriye tamamlandı ")
        rospy.is_shutdown()
volta()