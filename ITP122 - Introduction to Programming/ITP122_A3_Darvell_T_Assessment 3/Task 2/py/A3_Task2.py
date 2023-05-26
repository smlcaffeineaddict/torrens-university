#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Apr 29 14:49:02 2023

@author: tiamegan
"""

# Define a function to add a player to the players dictionary
def add_player(players): 
    # Loop until a valid player name is entered                                                                                           # add_player function takes a dictionary object, as input and prompts user to enter
    while True:
        # Get the player's name from the user                                                                                                     # player name and score while performing input validation checks.
        name = input("\nEnter player name: ")
        
        # Check if the name contains only alphabetic characters
        if not name.isalpha():                                                                                      # isalpha() is a method that returns true if input is all alphabetic characters.
            print("Invalid player name. Name should contain only alphabetic characters.")                           # If inputs are invalid, it displays an appropriate error message and allows the user to
            continue                                                                                                # repeat input process using continue.

        # Loop until a valid score is entered
        while True:
            # Get the player's score from the user
            score = input("Enter player score (0-100): ")
            
            # Check if the score is a digit between 0 and 100
            if not score.isdigit() or int(score) < 0 or int(score) > 100:                                           # isdigit() is a method that returns true if input is all numeric characters.
                print("[INVALID SCORE]. Score should be a digit between 0 and 100.")
                continue
            else:
                # Add the player and their score to the dictionary and break out of the loop
                players[name] = int(score)
                break
            
        # Ask the user if they want to add another player
        repeat = input("Do you want to add another player? (Y/N): ")
        if repeat.lower() in ['y', 'yes']:
            continue
        else:
            break


# Define a function to display all the players and their scores
def display_players(players):
    # Check if players dictionary is empty                                                                                       # display_players() take a dictionary object as input and displays the contents of
    if not players:                                                                                                 # dictionary in a tabular format.
        print("No players found.")
        return
        
    # Print the header for the table
    print("\n\tPlayer Name\t\tScore")
    print("-" * 30)
    
    # Loop through the players dictionary and print each player and their score
    for player, score in players.items():
        print(f"\t{player}\t\t\t{score}")
  
        
# Define the main function
def main(): 
    # Create an empty dictionary to store players and their scores                                                                                                        # main() function is the primary program that displays the menu options, reads  
    players = {}                                                                                                    # user choice and calls appropriate functions.
    
    # Loop until user chooses to quit
    while True:
        # Print the menu options for the user
        print("\n")
        print("=" * 40)
        print("** Welcome to Champions Soccer Club **")
        print("Please choose an option from the following:")
        print("\t1. Add player name and score\n\t2. Display all the player information and scores\n\t3. Quit")
        print("=" * 40)

        # Get the user's choice
        choice = input("\nEnter your choice: ")

        # Call the add_player function if the user chose option 1
        if choice == "1":                                                                                           # with the if-else loop the program continues until user selects to quit.
            add_player(players)  
            
        # Call the display_players function if the user chose option 2
        elif choice == "2":
            display_players(players)
        
        # Exit the program if the user chose option 3
        elif choice == "3":
            print("\nGoodBye..\tSee you again!*")
            print("\t\t\tExiting program...")
            break
        else:
            # Print an error message if the user enters an invalid option
            print("[Invalid Choice]. Please enter a valid option.")

# Call the main function if the script is run directly
if __name__ == "__main__":
    main()