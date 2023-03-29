#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 14 13:45:01 2023

@author: tiamegan
"""

# EXERCISE 1 : DICTIONARIES
# Create a dictionary of the following lists:
    #my_list1 =[1,2,3]
    #my_list2 =['a','b']
    
#Create a dictionary called my_dictionary_of_lists and use the keys and values mentioned above
my_dictionary_of_lists = {}

# Adding the lists of keys and values mentioned above
my_dictionary_of_lists['my_list1'] = [1,2,3]
my_dictionary_of_lists['my_list2']=['a', 'b']

# Display original list
print(my_dictionary_of_lists)

# Append 4 into key 'my_list1' such that it's values are [1,2,3,4]
my_dictionary_of_lists['my_list1'].append(4)

# Display new list
print(my_dictionary_of_lists)

# EXERCISE 2 : MODIFYING DICTIONARIES
# Create Student Dictionary. Fill it with three student's names and ID numbers.
student_dictionary = {"name": ['Louis', 'Tia', 'Luka'], "id": [1, 2, 3]}
    
# Choose your variables and dictionary keys wisely so that they can be understood from their names
    # 1. Output the second student's name
print(student_dictionary["name"][1])
    # 2. Print the second student's ID number.
print(student_dictionary["id"][1])
    # 3. Add a new student element in it
student_dictionary["name"].append("Sara")
student_dictionary["id"].append(4)
print(student_dictionary)
    # 4. Check if a student with ID=123 exists in the dictionary created
if 123 in student_dictionary["id"]:
    print(True)
else:
    print(False)
    