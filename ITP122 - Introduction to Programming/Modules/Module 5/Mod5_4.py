#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 21 13:27:07 2023

@author: tiamegan
"""

username = "admin"
password = "passw0rd"

if username == "admin":
    if password == "passw0rd":
        print("Access Granted.")
    else: 
        print("Invalid Password.")
else: 
    print("Invalid Username.")