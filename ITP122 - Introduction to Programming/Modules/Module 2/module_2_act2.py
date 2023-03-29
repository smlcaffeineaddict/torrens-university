#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 28 13:10:20 2023

@author: tiamegan
"""

# Conversion

# Float -> Int
# Float
variable4 = 23.0
print(variable4) #print float

# conversion
variable4 = int(variable4)
print(variable4) #print conversion


#Int -> String
variable4 = 23
# check and print
print (variable4)
print("Type of variable before conversion : ", type(variable4))

#converted from int to string
variable4 = str(variable4)
#check and print
print (variable4)
print("Type of variable after conversion : ", type(variable4))

# Float -> String
variable4 = 23.0
print ("Float :", variable4)
print("Type of variable before conversion : ", type(variable4))

variable4 = str(variable4)
print ("String :", variable4)
print("Type of variable after conversion : ", type(variable4))

#String -> Int
variable4 = "123"
print ("String :", variable4)
print("Type of variable before conversion : ", type(variable4))


variable4 = int(variable4)
print ("Int :", variable4)
print("Type of variable after conversion : ", type(variable4))
