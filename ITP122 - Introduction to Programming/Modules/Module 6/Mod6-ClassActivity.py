#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 28 12:05:00 2023

@author: tiamegan
"""

# CLASS ACTIVITY
# write a program which repeatedly reads numbers until the user enters “done”. 
# Once “done” is entered, print out the total, count and average of the numbers. 
# If the user enters anything other than a number, detect their mistake using 
# try and except and print an error message and skip to the next number

num = 0                                                                            # Identifying variables
total = 0.0

while True :                                                                       # Start of loop using While
    number = input("Enter a number : ")                                            # Enable input from user
    if number == "done" :                                                          # Idenfify key word to end loop
        break                                                                      # break to end loop
    try :
        num1 = float(number)
    except : 
        print ("Invalid Input.")                                                   # Identify invalid
        continue                                                                   # Continue program until the key word is written
        
    num = num +1
    total = total + num1
    
    if num > 0 :
        average = total/num                                                       # Calculate average, the mean, of the numbers inputed
        print("All Done.")                                                        # Display All Done
        print("Total :",total, "Count : ",num, "Average : %0.2f" %average)        # Print the total, count and mean/average
    else :
        print("No Valid Numbers Entered.")