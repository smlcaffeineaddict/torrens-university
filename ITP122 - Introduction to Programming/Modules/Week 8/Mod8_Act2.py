#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 11 12:46:58 2023

@author: tiamegan
"""

print ("-"*40)
print("\t Welcome to Torrens Cafe")
print ("-"*40)

print("\nMeals ------------------------")
print("1. Small Breaky\t\t$10.00")
print("2. Regular Breaky\t$15.00")
print("3. Big Breaky\t\t$20.00")
print("\nIndividual Food Items --------")
print("4. Eggs\t\t\t\t$0.99")
print("5. Toast\t\t\t$0.79")
print("\nHot Drinks -------------------")
print("6. Espresso\t\t\t$1.09")
print("7. Cappuccino\t\t$1.50")
print("8. Flat White\t\t$1.30")
print("9. Cafe Latte\t\t$1.99")
print("10. Mocha\t\t\t$2.50")
print("\nMilk -------------------------")
print("11. Full Cream\t12.Skim Milk")
print("\nAlternate Milk [ALL $.30] ----")
print("13. Almond Milk\t 14. Coconut Milk\n15. Soy Milk\t16.Oat Milk" )

print ("-"*10)
print("\nEnter 000 to exit and 111 to finalise payment")
print ("-"*10)

total=0
while True:
    itemChoice=input("\nChoose your item: > ")
    
    # Main Meals -------------------------------
    if int(itemChoice)==1 :       # Small Breaky
        print("[SELECTED] Small Breaky\t$10.00")
        quant=int(input("\tQuantity: "))
        total=total+10*quant 
    elif int(itemChoice) == 2:    # Regular Breaky
        print("[SELECTED] Regular Breaky\t$15.00")
        quant=int(input("\tQuantity: "))
        total=total+15*quant
    elif int(itemChoice) == 3:    # Big Breaky
        print("[SELECTED] Big Breaky\t$20.00")
        quant=int(input("\tQuantity: "))
        total=total+25*quant
        
    # Individual Food --------------------------
    elif int(itemChoice) == 4:    # Eggs
        print("[SELECTED] Eggs t$0.99")
        quant=int(input("\tQuantity: "))
        total=total+0.99*quant
    elif int(itemChoice) == 5:    # Toast
        print("[SELECTED] Toast\t$0.79")
        quant=int(input("\tQuantity: "))
        total=total+0.79*quant
        
   # Hot Drinks --------------------------------
    elif int(itemChoice) == 6:    # Espresso
        quant=int(input("\tQuantity: "))
        print("[SELECTED] Espresso\t$1.09")
        total=total+1.09*quant
        
    elif int(itemChoice) == 7:    # Capuccino
        print("[SELECTED] Capuccino\t$1.50")
        # Milk Options -----------------------
        milk = input("\tChoose Your milk: ")
        if int(milk)==11 and 12:
            milk = 0
        elif int(milk)== 13 and 14 and 15 and 16:
            milk = 0.30
            print("[SELECTED] Alternate Milk\t$0.30")
        # -----------------------
        quant=int(input("\tQuantity: "))
        total=total+(1.50+milk)*quant
        
    elif int(itemChoice) == 8:    # Flat White
        print("[SELECTED] Flat White\t$1.30")
        # Milk Options -----------------------
        milk = input("\tChoose Your milk: ")
        if int(milk)==11 and 12:
            milk = 0
        elif int(milk)== 13 and 14 and 15 and 16:
            milk = 0.30
            print("[SELECTED] Alternate Milk\t$0.30")
        # -----------------------
        quant=int(input("\tQuantity: "))
        total=total+1.30*quant
        
    elif int(itemChoice) == 9:    # Latte
        print("[SELECTED] Cafe Latte\t$1.99")
        # Milk Options -----------------------
        milk = input("\tChoose Your milk: ")
        if int(milk)==11 and 12:
              milk = 0
        elif int(milk)== 13 and 14 and 15 and 16:
             milk = 0.30
             print("[SELECTED] Alternate Milk\t$0.30")
    # -----------------------
        quant=int(input("\tQuantity: "))
        total=total+1.99*quant
        
    elif int(itemChoice) == 10:    # Mocha
        print("[SELECTED] Mocha\t\t\t$2.50")
        # Milk Options -----------------------
        milk = input("\tChoose Your milk: ")
        if int(milk)==11 and 12:
              milk = 0
        elif int(milk)== 13 and 14 and 15 and 16:
             milk = 0.30
             print("[SELECTED] Alternate Milk\t$0.30")
    # -----------------------
        quant=int(input("\tQuantity: "))
        total=total+1.99*quant
    
    
    elif int(itemChoice) == 000:
        break
    elif int(itemChoice) == 111:
        print("TOTAL\t${:.2f}".format(total))
        break
    else:
        print("Invalid Entry. Please Try Again.")
        