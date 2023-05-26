#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 30 23:34:26 2023

@author: tiamegan
"""

# TASK 2 - CODING FOR DIFFERENT TYPES OF LOOPS
# Convert the following loops into the equivalent WHILE loop

# a\
print("A. For Loop:")
for i in range(1,10):
    print (i,i*i)
    
print("\nA. While Loop:")
i = 1               # Initialise i to 1 before loop        
while i < 10:       # While i is smaller than 10, loop
    print (i,i*i)   # Print i and it's square number
    i += 1          # Increase i by 1 to loop until 1 is larger than 10
    
    
# b\
print("\nB. For Loop:")
sum = 0
for i in range(10,0,-1):
    sum = sum + 1
print(i,sum)
    
print("\nB. While Loop:")
sum = 0             # Initialise sum to 0
i = 10              # Initialise i to 10
while i > 0:        # While i smaller than 10, loop
    sum = sum + i   # Add i to sum
    i -= 1          # decrease i by 1 each time
print(i, sum)       # Print value of i and sum after loop.
                    # Sum will be equal to the sum of numbers from 1 to 10