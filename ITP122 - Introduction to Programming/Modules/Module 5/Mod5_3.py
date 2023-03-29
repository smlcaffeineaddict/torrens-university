#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 21 12:56:56 2023

@author: tiamegan
"""

x = -10

if x >= 0:
    if(x == 0):
        print('x is zero')
    else:
        print("x is positive")
else :
    print("x is negative")
    
# -----------------------------

card_number = "1234567987651"

if len(card_number)!= 16:
    print("Invalid card number")
else :
    first_digit = int(card_number[0])
    second_digit = int(card_number[1])
    if first_digit == 4:
        print("Visa")
    elif first_digit == 5 and second_digit in [1,2,3,4,5]:
        print("Mastercard")
    elif first_digit == 3 and second_digit in[4,7]:
        print("American Express")
    else: 
        print("Unknown Card Type")