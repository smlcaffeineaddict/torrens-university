#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 28 12:54:31 2023

@author: tiamegan
"""
# EXERCISE 1: Sum of Natural Numbers
# Write a Python program to accept a number from a user and calculate the 
# sum of all numbers from 1 to a given number, For example, if the user 
# entered 10, the output should be 55 (1+2+3+4+5+6+7+8+9+10).
print ("EXERCISE 1: Sum of Natural Numbers")
s = 0
n = int(input("Enter Number: "))

for i in range(1, n+1, 1) :
    s += i
print ("\n")
print("Sum is:", s)

# ---------------------------------------

# EXERCISE 2: Table of a Number
# Write a program to print the multiplication table of a given number.
print ("\nEXERCISE 2: Table of a Number")

n = int(input("Enter Number : "))
for i in range(1,11,1):
    product = n * i
    print(product)
 
# ---------------------------------------
   
# Exercise 3: List and Loop
# Write a program to display only those numbers from a list that satisfy the following conditions:
    # the number must be divisible by five
            # if the number is greater than 150, then skip it and move to the next number
            # if the number is greater than 500, then stop the loop.
            
print ("\nExercise 3: List and Loop")
num = [12, 75, 150, 145, 525, 50]
for item in num :
    if item > 500 :
        break
    elif item > 150 :
        continue
    elif item % 5 == 0 :
        print(item)
         
# ---------------------------------------

# Exercise 4
print ("\nExercise 4: Create a for loop to list the outputs")                   # Exercise 4: Create a for loop to list the outputs
hobby = []
for i in range(3) :                                                             # Create a for loop that prompts the user for a hobby 3 times, 
    hob = input("Enter Hobby: ")    
    hobby.append(hob)                                                           # Appends each one to hobbies
    
print(hobby)                                                                    # Outputs List