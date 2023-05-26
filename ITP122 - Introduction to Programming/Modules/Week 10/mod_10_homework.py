#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Apr 29 13:49:00 2023

@author: tiamegan
"""
# === WEEK 10 - HOMEWORK ===

# Define a recursive function called fib that calculates the nth 
# Fibonacci number. The Fibonacci sequence is a series of numbers where 
# each number is the sum of the two preceding ones.
# The sequence starts with 0 and 1, and the nth Fibonacci number is the sum
# of the (n-1)th and (n-2)th numbers
# For example, the first 10 Fibonacci numbers are: 
#                                              0, 1, 1, 2, 3, 5, 8, 13, 21, 34

def fib(n):
    """Calculate the nth Fibonacci number."""
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)

# This implementation defines a function fib that takes an integer n as its 
# argument. If n is 0, the function returns 0, and if n is 1, the function 
# returns 1. In all other cases, the function recursively calls itself with 
# arguments (n-1) and (n-2), adds the results together, and returns the sum.

print(fib(0))  # Output: 0
print(fib(1))  # Output: 1
print(fib(10))  # Output: 55

# In this example, we call the fib function with different input values to 
# compute the corresponding Fibonacci numbers.