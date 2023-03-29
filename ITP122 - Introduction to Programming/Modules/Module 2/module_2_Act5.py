#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar  7 11:36:19 2023

@author: tiamegan
"""

print("TASK 1 : ")             
# An algorithm to check if a student has passed in an exam or not, you can follow the given steps:

                                                         # Step 1: START
print("Exam Marking : ")

student_marks = int(input("\tEnter Student Marks : "))  # Step 3: Store the marks obtained by the student in x
minimum_passing = int(50)                               # Step 4: Store the minimum passing score in y                          
print("\tMinimum Passing Marks : ", minimum_passing)

x = student_marks                                       # Step 2: Declare two variables x, y
y = minimum_passing

if x > y :                                              # Step 5: Check if x is greater than or equal to y.
    print("Congratulations! Student Has Passed.")       # If yes, then return “Pass” else return “Fail”
else :
    print("Sorry! Student Has Failed.")
                                                        # Step 6: STOP
                                                         
# ----------------------------------------------------

print("\nTASK 2 : ")
# Write an algorithm for the following tasks.
number = int(input("Input a Number : "))

if (number % 2) == 0 :                                 # Check weather a given numbe r is even or odd
    print ("Even or Odd    : EVEN")
else :
    print ("Even or Odd    : ODD")
    
for a in range(2, number) :                            # Check weather a given number is a prime number.
    if (number % a) == 0 :
        print ("Prime or Not Prime : NOT PRIME")
        break
    else :
        print ("Prime or Not Prime : PRIME")
        break