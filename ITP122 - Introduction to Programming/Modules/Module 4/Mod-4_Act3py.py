#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 14 14:26:56 2023

@author: tiamegan
"""
# LEARNING ACTIVITY 3
# This learning activity requires you to read the problem, and design and implement the solution using Python.
# Add comments to your code to explain the purpose of different statements. Submit your code/output screenshots 
# to the discussion forum.

# Write a Python program that computes an investment report.

print("Investment Report\nEnter the values below to print out an investment report.")

# User Input for Amount Invested
investment_amount = float(input("Enter the investment amount:\t"))

# Input number of years invested, User Input
num_year = int(input("\nEnter the number of years(as 1 or 2 or 3 or... or 10):\t"))

# What the investment rate, User Input
rate = float(input("\nEnter the rate as (Ex: 0, 1.5, 5.9, 8 etc)%:\t"))

# Element name change and print of title for table
starting_balance = investment_amount
total_interest = 0
print("\nYear\tStarting Balance\tInterest\tEnding Balance")

for year in range(1, num_year + 1):
    interest =  starting_balance * rate / 100
    ending_balance = starting_balance + interest
    
    # Print data in table
    print("{}\t\t{:.1f}\t\t\t\t{:.1f}\t\t{:.1f}".format(year, starting_balance, interest, ending_balance))
    
    starting_balance = ending_balance
    total_interest += interest

# Print outputs
print("\nEnding Balance: \t\t {:.3f}".format(ending_balance))
print("Total Interest Earned: \t {:.3f}".format(total_interest))