#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu Oct  6 16:35:49 2022

@author: rumeysa
"""

import rospy
from find_object_2d.msg import ObjectsStamped

class NesneTanima():
    def __init__(self):
        rospy.init_node("nesne_tanima")
        rospy.Subscriber("objectsStamped",ObjectsStamped,self.nesneTani)
        rospy.spin()
    def nesneTani(self,mesaj):
        try: 
            
            self.nesne_id = mesaj.objects.data[0]
            print(self.nesne_id)
        except IndexError:
            print("nesne bulunamadı")
NesneTanima()