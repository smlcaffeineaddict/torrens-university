#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar  7 12:42:14 2023

@author: tiamegan
"""

# Each year, nearly everyone with an income faces the unpleasant task of computing their income tax return. 
# Assume you are working as software developer in a medium-sized business, and your manager has asked you to 
# implement an income tax calculator program with the following requirements.

print("Income Tax Calculator")
print ("Enter value to 2 decimal places.")
dependent = int(input("Enter Number of Dependants : "))
gross_income = float(input("Enter Gross Income : $"))          # Gross income must be entered to the smallest penny.
flat_tax = (25/100) * gross_income                             # All taxpayers are charged a flat tax rate of 25%.
stand_deduc = 18500                                            # All taxpayers are allowed a $18,500 standard deduction.
add_deduc = (1200) * dependent                                 # For each dependent, a taxpayer is allowed an additional $1,200 deduction.

income = gross_income - flat_tax
taxable_income = income - (stand_deduc + add_deduc)

print("\nIncome after Base Tax : $%.3f" %income)               # Income tax is expressed as a decimal number with three decimal places.

if taxable_income < 18500 :                                                             
    print("Taxable Income below $18,500 : $%.3f" %taxable_income)                        # From ATO, income below $18,500 is not taxed.
    tax_remaining = (0 * 1) * taxable_income     
    
elif taxable_income > 18500 and taxable_income < 45000 :                                 
    print("Taxable Income above $18,500 and below $45,000 : $%.3f" %taxable_income)      # From ATO, income above $18,500 is taxed 19 
    tax_remaining = (0.19 * 1) * taxable_income                                          # cents per $1 until total taxable income is 
                                                                                         # above $45,001
  
    
elif taxable_income > 45001 and taxable_income < 120000 : 
    print("Taxable Income above $45,001 and below $120,000: $%.3f" %taxable_income)      # From ATO, income above $45,001 is taxed $5092 
    tax_remaining = (0.325 * 1) * taxable_income + 5092                                  # plus 32.5 cents per $1 until total taxable 
                                                                                         # income is above $120,000
    
elif taxable_income > 120001 and taxable_income < 180000 :
     print("Taxable Income above $120,001 and below $180,000: $%.3f" %taxable_income)    # From ATO, income above $120,001 is taxed 
     tax_remaining = (0.37 * 1) * taxable_income + 29467                                 # $29,467 plus 37 cents per $1 until total 
                                                                                         # taxable income is above $180,000
elif taxable_income > 180001  :
     print("Taxable Income is $180,001 and above: $%.3f" %taxable_income)                # From ATO, income above $180,001 is taxed 
     tax_remaining = (0.45 * 1) * taxable_income + 51667                                 # $51,667 plus 45 cents per $1
     
print("Tax Implemented : $%.3f" %tax_remaining)

tax = tax_remaining + flat_tax
net = gross_income - tax
print ("\nSummary : ")
print ("Dependent/s  : ", dependent)
print ("Gross Income :  $%.3f" %gross_income) 
print ("Total Tax    :  $%.3f" %tax)
print ("Net Income   :  $%.3f" %net)

#In this case, the user inputs are gross income and the number of dependents. The program calculates the income tax based on the 
#inputs and tax law, and then displays the income tax.
