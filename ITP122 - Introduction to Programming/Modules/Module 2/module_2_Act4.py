#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar  7 11:35:13 2023

@author: tiamegan
"""

# Use the operators to solve for the following equation and print the outputs

# QUESTION 1
print ("QUESTION 1")
x = 10                                          # Assign 10 to x.
if x > 0 :                                      # If x is bigger than 0, print "x is a positive number".
    print("x is a positive number.")
    
# -------------------------------------------
# QUESTION 2
print ("\nQUESTION 2")
family = int(input("How many members are in your family? : "))  # Ask a user how many family members they have.

if family > 5 :                                                 # Based on the input, print the message ‘large family’ 
    print("You have a LARGE FAMILY.")     
else :                                                          # if there are more than 5 members.                        
    print ("You have a NORMAL FAMILY")
    
# -------------------------------------------
# QUESTION 3
print ("\nQUESTION 3")
print("Input two(2) numbers.")                                  # Ask a user for input of two numbers and store them in the 
first_number = int(input("Enter First Number : "))                    # variables ‘first_number’ and ‘second_number’.
second_number = int(input("Enter Second Number : "))

print("\nLet's Begin.\n")

# Perform the following operations.

print("Are the input numbers ODD or EVEN?")                     # Check if the numbers are even or odd.
                                                                # and print the message as ‘first_number is even/odd’ and 
if (first_number % 2) == 0 :                                    #‘second number is even/odd’.
    print ("First Number ", first_number," is EVEN")
else :
    print ("First Number ", first_number," is ODD")
    
if (second_number % 2) == 0 :
    print ("Second Number ", second_number," is EVEN")
else: 
    print("Second Number ", second_number," is ODD")


subtract = first_number - second_number                                                         # Subtract the numbers as first_number - second_number
print ("\nThe Difference between ", first_number, " and ", second_number, " is : ", subtract)     # print the message if the difference is positive or negative.
if subtract < 0 :
    print("Difference is NEGATIVE")
else :
    print("Difference is POSITIVE")

print("\nNEXT TASK:")
print("Let's change it up by adding 5 to ", first_number, " and -2 to ", second_number)         # Add 5 to first_number and -2 to second_number, and 
                                                                                                # perform tasks a and b again.
first_number = first_number + 5
second_number = second_number + -2

print("\nAre the input numbers ODD or EVEN?")                                                   # Check if the numbers are even or odd.
                                                                                                # and print the message as ‘first_number is even/odd’ and 
if (first_number % 2) == 0 :                                                                    #‘second number is even/odd’.
    print ("First Number ", first_number," is EVEN")
else :
    print ("First Number ", first_number," is ODD")
    
if (second_number % 2) == 0 :
    print ("Second Number ", second_number," is EVEN")
else: 
    print("Second Number ", second_number," is ODD")


subtract = first_number - second_number                                                         # Subtract the numbers as first_number - second_number
print ("\nThe Difference between ", first_number, " and ", second_number, " is : ", subtract)   # print the message if the difference is positive or negative.
if subtract < 0 :
    print("Difference is NEGATIVE")
else :
    print("Difference is POSITIVE")
