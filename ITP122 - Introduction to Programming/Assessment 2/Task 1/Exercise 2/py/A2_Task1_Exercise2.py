#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 28 13:56:20 2023

@author: tiamegan
"""

# TASK 1 - CODING FOR SIMPLE LOOPS

# EXERCISE 2:
# Write a python program that ask for an integer input 
#from the user and prints its multiplications on the screen.
print("MULTIPLICATION TABLE GENERATOR")     

num = int(input("Enter an integer value : "))                   # Requests input from User 

print("The Multiplication Table of number: ", num)              # Print text and confirmation of integer entered

for count in range(1,11):                                       # For loop, count variable introduced and use of 
                                                                # range which is greater than or equal to 1 and 
                                                                # less than 11. Loop will iterate, multiply by 1 
                                                                #to the given integer before cycling to the 2nd 
                                                                #integer down to the 10th.
    print(num,'x',count,'=', num*count)                         # Output print of the table.