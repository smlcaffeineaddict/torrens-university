#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Apr 29 12:26:48 2023

@author: tiamegan
"""

def add_numbers(num1, num2):
    result = num1 + num2
    return result

result = add_numbers(3, 4)
print(result)

# Global variables and local variables
count = 0
def increment_count():
    global count
    count += 1
    
increment_count()
print(count)


#assigning function to variable
def say_hello():
    print("hello")
    
greeting = say_hello
greeting()

# -----------------------------

def apply_operation(func, x, y):
    return func(x,y)

def add(x, y):
    return x + y

result = apply_operation(add, 3, 4)
print(result)

# -----------------------------
# factorial, in mathematics, the product of all positive integers less than or
# equal to a given positive integer and denoted by that integer and an
# exclamation point. Thus, factorial seven is written 7!, 
# meaning 1 × 2 × 3 × 4 × 5 × 6 × 7. Factorial zero is defined as equal to 1.

def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)

result = factorial(5)
print(result)

# -----------------------------
# Passing by Reference
# passing an integer by value

def increment(x):
    x += 1
    print("Inside the function:", x)
    
num = 5
increment(num)
print("Outside the function", num)

# passing a list by reference
def add_element(lst, element):
    lst.append(element)
    print("Inside the function:", lst)
    
my_list = [1,2,3]
add_element(my_list,4)
print("Outside the function", my_list)

# -----------------------------
def apply_operation(operation, a, b):
    return operation(a, b)

def add(a,b):
    return a + b

def multiply(a,b):
    return a * b

result = apply_operation(add, 2, 3)
print(result)

result = apply_operation(multiply, 2, 3)
print(result)

# -----------------------------
def get_operation(op):
    if op == '+':
        def add(a,b):
            return a + b
        return add
    elif op == '*':
        def multiply(a,b):
            return a * b
        return multiply
    
operation = get_operation('+')
result = operation(2,3)
print(result)

operation = get_operation('*')
result = operation(2,3)
print(result)

# -----------------------------
# Anonymous Functions
square = lambda x : x**2  #lambda takes x and squares that number
result = square(2)
print (result)
    
numbers = [1,2,3,4,5]
squares = map(lambda x : x**2, numbers)
print(list(squares))

numbers = [1,2,3,4,5]
even_numbers = filter(lambda x: x % 2 == 0, numbers)
print(list(even_numbers))


# -----------------------------
# === QUIZ ===

# Q1
# Define a function called flatten that takes a list of nested lists as an 
# argument. The function should flatten the lested lists and return a new 
# list with the flattened elements.

def flatten(nested_list):
    """Flatten a list of nested lists."""
    flattened_list = []
    for item in nested_list:
        if isinstance(item, list):
            flattened_list.extend(flatten(item))
        else:
            flattened_list.append(item)
    return flattened_list

# This implementation uses recursion to traverse the nested lists and 
# flatten them. It checks if each item in the list is itself a list,
# and if so, it calls the flatten function recursively on that sublist. 
# If the item is not a list, it appends it directly to the flattened_list.

nested_list = [[1, 2], [3, [4, 5]], 6]
flattened_list = flatten(nested_list)
print(flattened_list) # Output: [1, 2, 3, 4, 5, 6]

# In this example, the input nested_list contains nested sublists. 
# The flatten function flattens these sublists into a new list flattened_list, 
# which contains all the elements of the original list in a flat structure.

# -----------------------------
# Closures and Decorators

# Closure
def outer_function(x):
    def inner_function(y):
        return x + y
    return inner_function

closure = outer_function(10)
result = closure(5)
print(result)

# Decorator
def my_decorator(func):
   def wrapper(*args, **kwargs):
        print("Before the function is called.")
        result = func(*args, **kwargs)
        print("After the function is called.")
        return result
   return wrapper

@my_decorator

def my_function(x,y):
    return x + y

result = my_function(10, 5)
print(result)