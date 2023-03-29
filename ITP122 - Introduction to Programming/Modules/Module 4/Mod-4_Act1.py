#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 14 12:47:06 2023

@author: tiamegan
"""

# Exercie 1 : Lists and Tuples
user_input = input("Enter values of your choice separated by commas: ")
print(user_input)

temp1 = user_input.split(",")        # To Eliminate commas
conv_list = list(temp1)
print(conv_list)

temp2 = user_input.split(",")         # To eliminate commas
conv_tuple = tuple(temp2)
print(conv_tuple)


# Excerise 2 : Dictionaries
party = {
    'money' : 1000,
    'cake': ["cheesecake", "sponge cake", "flourless cake", "biscut cake"],
    'guests': ["Bob", "Alicia", "Eve", "Tom", "Harry"],
    'venue' : ["outdoor", "indoor"]
    }

#To add a key 'gifts' with the given string values
party['gifts'] = ['phone', 'laptop', 'camera', 'DIY Card', 'chocolates']

#To add $500 more to 'money'
party['money'] = party['money'] + 500

#To remove Bob from Guests list
party['guests'].remove('Bob')

# To check all updates
print(party)