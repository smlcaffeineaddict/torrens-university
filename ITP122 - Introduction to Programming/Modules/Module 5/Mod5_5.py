#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 21 13:39:24 2023

@author: tiamegan
"""

try :
    result = 10/0
except ZeroDivisionError:
    print ("Error: Division By Zero")
    
# Handling a file not founds error
try : 
    with open("nonexistent_file.txt", "r") as f:
        contents = f.read()
except FileNotFoundError:
    print("Error: FIle Not Found.")