#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 28 13:11:05 2023

@author: tiamegan
"""
# Exercise 1: 
# Type the missing code so that variable c is updated by one with each loop 
# iteration. Explain as comments in the code how many times the loop iterates and why.
print ("\nEXERCISE 1")
str = "International"
c = 0                                                                           # identify variables

for i in str:                                                                   # Loop through str
    c += 1                                                                      # add one number for each letter in str as loop iterates
    print(c)                                                                    # Output count of letters in str
    
# ---------------------------------------
    
# Exercise 2: 
# Type the missing code so that each item in names_list is updated with a Prof.
# prefix and saved in updated_names_list.
# Hint: You may use the for loop and list append method.
print ("\nEXERCISE 2")
names_list = ["Nandini", "Tony", "Zifen", "Memon"]                              # Pre-identified list
update_names_list = []                                                          # Blank list for updates

for name in names_list :                                                        # For Loop for everything in names_list   
    update_names_list.append("Prof." + name)                                    # append every item in list with additional text "Prof."

print(update_names_list)

# ---------------------------------------

# Exercise 3: 
# Type the missing code so that all positive numbers are stored in a new list.
# Hint: Make use of the for loop and the if statement.
print ("\nEXERCISE 3")
old_list = [222, 64, -11, -55, -19, 8, 96, -9]                                  # list of numbers, predetermined of positive and negative
new_list = []                                                                   # New list

for num in old_list :                                                           # Loop through old list
    if num >= 0 :                                                               # Check if number is a positive or negative
        new_list.append(num)                                                    # if Positive, add to new list
print(new_list)                                                                 # Output new list