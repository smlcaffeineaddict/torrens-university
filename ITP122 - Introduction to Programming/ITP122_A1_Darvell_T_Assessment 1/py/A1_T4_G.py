#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Mar 12 13:16:28 2023

@author: tiamegan
"""
# You are hired as a software coder for LoseWeightNow Pty Ltd located in Redfern, NSW, Australia. 
#Your task is to build a simple software program that receives input from the patients including 
#their first name, last name, age, body weight, and body height; your software program is to calculate 
#the body mass index (BMI) of the patient, and display the output as 

# “Welcome + First Name + Last Name. Your age is Age and your BMI is BMI Value”. 

# For example, if Adam Smith, 19 years old having BMI of 22.5 will display 
# “Welcome Adam Smith. You are 19 years old and your BMI is 22.5” 

# Write software program to accomplish the above given task. 

print("BMI Calculator")
print("Use this simple tool to calculate your body mass index (BMI). \nBMI is a widely used measure to find out whether you’re a healthy weight for your height. ")
print("BMI is calculated using your weight and height (your weight divided by your height squared).\n")
print("Enter your information below:")

fname = input ("\tEnter First Name: ")
lname = input ("\tEnter Last Name: ")
age = int(input("\tEnter Age: "))
bweight = float(input("\tEnter Body Weight (kgs): "))
bheight = float(input("\tEnter Height (cms): "))

bmi = (bweight / bheight / bheight) * 10000

print("\nWelcome" , fname , lname + ". Your age is", age , "and your BMI is %.1f." %bmi)