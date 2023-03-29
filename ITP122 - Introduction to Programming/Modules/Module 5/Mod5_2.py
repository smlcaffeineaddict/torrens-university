#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 21 12:44:29 2023

@author: tiamegan
"""

# import the random module to generate a random number
import random

#generate a random number between 1 and 10
number = random.randint(1,10)

# prompt the user to guess the number
guess = int(input("Guess a number between 1 and 10: "))

# check if the guess is correct
if guess == number :
    print("Correct! You guessed the number.")
    
elif guess > number :
    print("Incorrect. The number is lower than your guess.")
    
else : 
    print("Incorrect. The number is higher than your guess.")
    
print("Number was", number)