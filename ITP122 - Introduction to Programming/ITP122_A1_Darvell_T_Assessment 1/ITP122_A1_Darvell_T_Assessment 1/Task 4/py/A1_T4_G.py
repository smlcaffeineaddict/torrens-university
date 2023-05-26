#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Mar 12 13:16:28 2023

@author: tiamegan
"""
# Task 4
print("BMI Calculator")
print("Use this simple tool to calculate your body mass index (BMI). \nBMI is a widely used measure to find out whether you’re a healthy weight for your height. ")
print("BMI is calculated using your weight and height (your weight divided by your height squared).\n")
print("Enter your information below:")

fname = input ("\tEnter First Name: ")                                                      # Recieve input for First Name
lname = input ("\tEnter Last Name: ")                                                       # Recieve input for Last Name
age = int(input("\tEnter Age: "))                                                           # Recieve input for Age
bweight = float(input("\tEnter Body Weight (kgs): "))                                       # Recieve input for Body Weight
bheight = float(input("\tEnter Height (cms): "))                                            # Recieve input for Height

bmi = (bweight / bheight / bheight) * 10000                                                 # Calculate BMI ((Weight / Height / Height) * 10 000)

print("\nWelcome" , fname , lname + ". Your age is", age , "and your BMI is %.1f." %bmi)    # Output results like : 
                                                                                            # “Welcome Adam Smith. You are 19 years old 
                                                                                            # and your BMI is 22.5” 