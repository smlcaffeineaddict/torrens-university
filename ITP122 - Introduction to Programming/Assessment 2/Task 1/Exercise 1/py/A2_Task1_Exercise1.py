#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 30 22:00:56 2023

@author: tiamegan
"""

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 30 21:25:20 2023

@author: tiamegan
"""
# TASK 1 - CODING FOR SIMPLE LOOPS

# EXERCISE 1:
# Complete the following:
 
num = 1;                                                # Defined Num or i
    
# A. Print first 10 numbers using while loop (e.g., 1, 2, 3, ...., 8, 9, 10) 
print("First 10 numbers using while loop")
while(num <= 10) :                                      # Using a while loop, num defined and lessthan or equal to 10
    print(num)                                          # Print current integer
    num += 1                                            # Add 1 to the current integer at end and loop until 10
    
    
# B. Print first 10 even numbers using for loop (e.g., 2, 4, 6, ...., 16, 18, 20)  
print("\nFirst 10 even numbers using for loop")
for num in range(1,11):                                 # For loop, count variable range which is greater 
    print(num*2)                                        # than or equal to 1 and less than 11. 
                                                        # Output num integer multiplied by 2 to keep numbers positive
                            
print("\nFirst 10 even numbers using for loop")
for num in range(1,10+1):                               # For loop, count variable range which is greater  
                                                        # than or equal to 1 and less than 11.
    if(num%2==0):                                       # If num can be divided into 2, is true./
         print(num)                                     # print even number
    num = num + 1                                       # add 1 to value and re-loop

# C. Print first 10 odd numbers using while loop (e.g., 1, 3, 5, ..., 15, 17, 19) 

num = 1                                                 # Defined Num or i

print("\nFirst 10 odd numbers using for loop")
while num <= 10 :
    if(num % 2 != 0):                                   # If num can be divided into 2, is false.
        print(num)                                      # Print odd number
    num = num + 1                                       # add 1 to value and re-loop
    
# D. Print sum of first 10 numbers using for loop (e.g., print the sum of 1+ 2 + 3 + ... + 8 + 9 + 10). 
print("\nPrint sum of first 10 numbers using for loop")
space = ""                                              # String Variable
sum = 0                                                 # Final Number Variable

for num in range(1, 11):                                # For loop, count variable range which is greater  
                                                        # than or equal to 1 and less than 11.
    space += str(num)                                   # Convert the integer to string
    if num < 10:                                        # If num is smaller than 10 then...
        space += " + "                                  # With num now space (string of num) add a + between each number
    sum += num                                          # Add all Num together to get Sum
print(space, "=", sum)                                  # Output space with a "=" and then sum
                                                        # Output should be in a single line