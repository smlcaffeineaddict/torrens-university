#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar  7 11:12:52 2023

@author: tiamegan
"""
# EXERCISE 1
twoway_ticket = 400                                                    # assign base ticket price
extra_charge = (15/100) * twoway_ticket                                # 15% extra charge
upgraded_price = extra_charge + twoway_ticket                          # Upgraded Price (extra + base)
discount = (20/100) * upgraded_price                                   # Discount from Upgrade (discount/100 * upgrade)
final_price = upgraded_price - discount                                # What Alice Paid. (upgrade - discount)
print ("The total amount Alice has to pay is : $%.2f" %final_price)    # Using the %f format to display final amount

# EXERCISE 2
import math as m

length = 15
breadth = 5
lb = length + breadth

p = 2 * breadth                                                  # Perimeter of a rectangle = 2 (length + breadth)
a = length * breadth                                             # Area of a rectangle = length * breadth
d = m.sqrt((m.pow(breadth,2)) + (m.pow(length,2)))               # Diagonal of a rectangle = sqrt(breadth2+length2)

print("The perimeter of  the rectangle is: %.4f" %p)             # Output values to 4 decimal places
print("The area of  the rectangle is: %.4f" %a)
print("The diagonal of  the rectangle is: %.4f" %d)



radius = 10                                                      # Radius as a variable
circle_area = 2*(m.pi)*radius                                    # Area of a circle = 2 * pi * radius
circle_cir = (m.pi)*(m.pow(radius,2))                            # Circumference of a circle = pi * radius2

print("The area of the circle is: %.4f" %circle_area)            # Output values to 4 decimal places
print("The circumference of the circle is: %.4f" %circle_cir)