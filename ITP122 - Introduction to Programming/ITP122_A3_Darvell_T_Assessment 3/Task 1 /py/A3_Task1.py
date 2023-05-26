#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Apr 29 12:17:06 2023

@author: tiamegan
"""
# Print the header for the distance travelled table
print("\n========== D I S T A N C E  T R A V E L L E D ==========")

# Loop until the user enters valid input values for speed and time
while True :
    # Use the try-except block to handle any incorrect input values entered.
    try:
        # Ask the user to input the speed of the ball and the number of minutes travelled
        print("*answer the below question in meters per minute (mpm)\n")
        speed = float(input("\tWhat is the speed of the ball?\t: "))            
        time = int(input("\tHow many minutes has it travelled?\t: "))   
        
        # Check if the input values are positive
        if speed <= 0 or time <= 0:
            print("Invalid. Enter positive values for speed and time.")
            
        else:
            # Break out of the loop if the input values are valid
            break
    except ValueError:
        # Handle any input value errors using a try-except block
        print("Invalid. Enter Valid Numeric Inputs.")
        
# Print the header for the distance travelled table
print("\n")
print("\t",("-" * 36))
print("\t  Minute \t\tDistance Travelled")
print("\t",("-" * 36))

# Loop through each minute and calculate the distance travelled
for i in range(1, time + 1):
    # Calculate the distance travelled using the formula distance = speed * time
   # Round off the distance to 2 decimal places using the round() function
    distance = round(speed * i, 2) 
    
    # Print the minute and the distance travelled in a table format                                             
    print(f"\t\t{i}\t\t\t{distance}")
    