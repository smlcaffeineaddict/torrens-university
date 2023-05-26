#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 11 11:43:33 2023

@author: tiamegan
"""

for i in range (10):
    if i==5:
        break
    print(i)
    

i = 0
while i < 10:
    if i == 5:
        break
    print(i)
    i += 1
    
for i in range(10):
    if i == 5:
        continue
    print(i)
    
i = 0
while i < 10:
    i += 1
    if i % 2 == 0:
        continue
    print(i)
    
    
# Pass Statement
#using pass with a for loop to iterate over a list

my_list = [1,2,3,4,5,6,7,8,9,10]
for item in my_list:
    if item % 2 == 0:
        pass
    else:
        print(item)
        
my_list = [1,2,3,4,5,6,7,8,9,10]
i = 0
while i < len(my_list):
    if my_list[i] % 2 == 0:
        pass
    else:
        my_list[i] = my_list[i] ** 2
        i += 1
        
print(my_list)



i = 0
while i < 5:
    print(i)
    i += 1
else:
    print("The loop has finished exucuting")
    
    
showroom = {'Ford':10, 'Toyota':5, 'Honda': 7, 'BMW': 3}

while True:
    car_brand = input("Enter a car brand name to check avaliablity(or 'exit' to quit")
    if car_brand =='exit':
        break
    for brand,quantity in showroom():
        if brand == car_brand:
            print(f"{brand} is avaliable ub showroom with a quantity of {quantity}")
            break
    else:
        print(f"sorry, {car_brand} is not avlaivble in the show;pp[")
    
    
#infinte loops

while True:
    print("this is an infinite loop")