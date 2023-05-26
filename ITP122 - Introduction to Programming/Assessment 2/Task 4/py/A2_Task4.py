#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Apr 16 15:53:17 2023

@author: tiamegan
"""


print("====== MOVIE4US ======")
print("Welcome to Movie4Us.")

print("\n200 Tickets Avaliable for XXXXXXXX Movie.")

# Initialize the number of tickets and the user counter
num_tickets = 200
user_count = 1


# Give user option to start the loop with a Y / N question
purchase = input("Do You Wish to Purchase a Ticket? ( Y / N ) > ")
    
# Start the ticket issuance loop
while user_count <= num_tickets:
    
    if purchase == "n" or purchase == "N":
        # Using break to end the loop.
        break

    elif purchase == "y" or purchase == "Y":
        # Print a welcome message to the user and display the number of remaining tickets
        print (f"\nYou are the {user_count}th user.\nThe number of remaining tickets is now {num_tickets - user_count}.")
        # Increment the user counter
        user_count += 1
    
        # Ask the user if they want to continue or stop issuing tickets
        user_input = input("Do you want to continue? ( Y / N ) > ")
    
        if user_input.lower() == "n" and user_input.upper() == "N":
        # Exit the loop if the user chooses to stop issuing tickets
            print("\nNo more Tickets will be issued.\nEnjoy the Movie.")
            break

    # Print a message for the 201th user if all tickets have been issued
    if user_count > num_tickets:                                                    
        print("\nThere are no more tickets.")
     
# Text viewed at end of program.
print("Exit Program.")