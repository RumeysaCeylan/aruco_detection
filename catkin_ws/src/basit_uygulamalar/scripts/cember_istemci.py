#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 27 11:43:14 2022

@author: rumeysa
"""
import rospy
from basit_uygulamalar.srv import CemberHareket

rospy.wait_for_service("cember_servis")

try:
    yaricap = float(input("yaricap giriniz: "))
    servis=rospy.ServiceProxy("cember_servis",CemberHareket)
    servis(yaricap)
except rospy.ServiceException:
    print("error")
