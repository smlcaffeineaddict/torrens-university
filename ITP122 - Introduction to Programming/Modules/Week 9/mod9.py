#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 18 11:58:30 2023

@author: tiamegan
"""



## Rewatch first 30 minutes
i = 1
while i<=5:
    for j in range(1, i+1):
        print(j,end='')
    print()
    #Add new line
    i += 1
    
print('-------------------------------')

for i in range(1,4):
    for j in range(1,4):
        print( i + j )
        if i * j > 4:
            break
        j+= 1
    i += 1
        
print('-------------------------------')
    
# we want to show breaking multiple nested loops
for i in range (1,4):
    for j in range(1,4):
        for k in range(1,4):
            print (i * j * k)
            if i * j * k > 10:
                break
            
        else:
            continue
        break
        
print('-------------------------------')

# We want to go through nested loops and list
numbers = ([1,2,3], [4,5,6], [7,8,9])

for i in range(len(numbers)):
    for j in range(len(numbers[i])):
        if numbers[i][j] % 2 == 0:
            numbers[i][j] = "even"
        else:
            numbers[i][j] = "odd"
print(numbers)

print('-------------------------------')
numbers = ([1,2,3], [4,5,6], [7,8,9])
squares = []

for row in numbers:
    row_squares = []
    for col in row:
        square = col ** 2
        row_squares.append(square)
    squares.append(row_squares)

print(square)

print('-------------------------------')

# *
# **
# ***
# ****
# *****

for i in range(5):
    for j in range (i + 1):
        print("*", end = "")
    print()
    
print('-------------------------------')

# Write a program to print all the prime numbers 
# between 1 and 100 using nested loops

for i in range(2, 101):
    for j in range (2, i):
        if i % j == 0:
            break
    else:
        print(i)
        
print('-------------------------------')
# write a program to print hte multiplication 
# table of a given number using nexted loops

num = int(input("Enter a number : "))
for i in range (1,13):
    print(num, "*", i, "=", num*i)
    
print('-------------------------------')
# Write a program to find the sum of all 
# the elements in a nested list using nested loops.

list = ([1,2,3], [4,5,6], [7,8,9])
sum = 0

for i in range(len(list)):
    for j in range(len(list[i])):
        sum+= list[i][j]
    print(sum)
    
print('-------------------------------')
