#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 21 11:56:59 2023

@author: tiamegan
"""

x = 12
y = 12.0

if x < y :
    print('x is less than y')
    
elif x > y :
    print('x is greater than y')

else :
    print('x and y are equal')
    
print('All done.')

# -----------------------------

choice = 'b'

if choice == 'a' :
    print('Bad Guess')
    
elif choice == 'b' :
    print('Good guesss')
    
elif choice == 'c' :
    print('Close, but not correct.')
    
# -----------------------------

x = 3
y = 5
z = 2

if x < y and x < z :
    print('a')
    
elif y < x and y < z :
    print('b')
    
else:
    print('c')
    
# -----------------------------

score = 93
if score >= 90:
    grade  = "A"
    
elif score >=  80:
    grade = "B"
    
elif score >= 70:
    grade = "C"
    
elif score >= 60:
    grade = "D"
    
else:
    grade = "E"
    
print(grade)

# -----------------------------
x = 10
y = 10

if x < y :
    print( x,'is less than',y)
    
elif x > y :
    print( x,'is greater than', y)

else :
    print(x, 'and', y, 'are equal')
    
print('All done.')

# -----------------------------

day = 30
month = 2
year = 2023

if month < 1 or month > 12 :
    print("Invalid Month")
    
elif day < 1 or day > 31 :
    print("Invalid day")
    
elif month in [4,6,9,11] and day > 30:
    print("Invalid day for this month")
    
elif month == 2 and (day > 29 or (day == 29 and not year % 4 == 0)):
    print("Invalid day for this month and year")
    
else:
    print("Date is Valid")