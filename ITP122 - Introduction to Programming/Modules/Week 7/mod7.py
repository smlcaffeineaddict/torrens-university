#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr  4 17:10:22 2023

@author: tiamegan
"""

def add_numbers(x,y):
    result = x + y
    return result

sum = add_numbers(3,4)
print(sum)

#----------------------------------------------------------------------------
def say_hello(name = "world"):
    print ("Hello," + name + "!")
    
# you can call this function without providing a value for name and it will \
#use the default value

say_hello()

# you can also provide a value for name if you want to override the default value

say_hello("Shazi")

#----------------------------------------------------------------------------

def is_even(number):
    if number % 2 == 0:
        return True
    else :
        return 
    
    if is_even(4):
        print("The number is ewven")
    else:
        print("The number is odd.")
        
#----------------------------------------------------------------------------

# python pass statement
def my_function():
    pass

class Myclass:
    pass

#----------------------------------------------------------------------------
x = 1

if x > 5:
    pass
else:
    print("x is less than or equal to 5")
    
#----------------------------------------------------------------------------
# Python Built-In Functions

print("hello shazi!")  # Output text or variable to console

# len()
my_list = [1,2,3,4,5]
print(len(my_list))

# range()
for i in range(5):
    print(i)
    
#input()
name = input("What is your email?")
print("hello" + name + "!")

# type()
x = 5
print(type(x))

#min()
my_list = [1,2,5,7,3,9]
print(min(my_list))
      