#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 11 12:25:30 2023

@author: tiamegan
"""

# Write a for-else loop that iterates over a list of numbers and prints the
# number if it is even, and prints "Odd number found!" if an odd number is encountered

lst = [1,2,3,4,5,6,7,8,9, 10]
for num in lst:
    if num % 2 == 0:
        print(num)
    else:
        print("odd number found")
        
# Write a while-else loop that prompts the user to enter a positive integer, 
# and keeps prompting until a positive integer is entered
while True:
    user_input = input("please enter a positive integer.")
    if user_input.isdigit() and int(user_input) > 0:
        break
    else:
        print("invalid input, please try again.")