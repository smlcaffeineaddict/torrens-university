// Get access to things in constants while coding on replit.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "constants.h"
#include "ise102.h"
using namespace std;

using std::string;
// Takes in a minimum number (int) and a maximum number (int), returns a random
// number between the min and max (inclusive)
int randomInRange(int min, int max)
{
  int difference = max - min;
  int rand_in_range = min + (rand() % (difference+1));
  // send back the result.
  return rand_in_range;
}

// Prompts player to go with one of the available options
string getPlayerChoice(string choiceA, string choiceB)
{
    string choice = " ";
  
  bool success;
 do {
   // TODO: Add a loop here so the player is asked for their choice until they
// enter one of the two. If they don't, they see an error and have to input again.
  cout << "Enter your choice, " << choiceA << " or " << choiceB << "\n";
  cout << " > ";
  // print("Enter your choice, {0} or {1}\n", choiceA, choiceB);
      cin >> choice;
  if (choice == "MINE" || choice == "mine"){
    success=true;
  }
   else if (choice == "SPIT" || choice == "spit"){
     break;
    }
   else {
     success=false;
   }
   } while(!success);
     return choice;
    }

// Prompts player to go with one of the available options
string mineWalls(string choiceA, string choiceB)
{
    string choice = " ";
  bool success;
 do {
    cout << "Which one are you picking, " << choiceA << " or " << choiceB << "\n";
  cout << " > ";
        cin >> choice;

if (choice=="LEFT" || choice=="left"){
    success=true;
  }
   else if (choice=="RIGHT" || choice=="right"){
     break;
}
   else {
     success=false;
   }
   } while(!success);
     return choice;
    }

// ------------------------------------------------------------------------//
// String Function to Reuse when having a YES OR NO option.
string continuePlaying2(string choice2A, string choice2B)
{
    string choice2 = " ";
  bool success;
 do {
    cout << "Enter your choice, " << choice2A << " or " << choice2B << "\n";
  cout << " > ";
        cin >> choice2;

if (choice2=="YES" || choice2=="yes"){
    success=true;
  }
   else if (choice2=="NO" || choice2=="no"){
     break;
}
   else {
     success=false;
   }
   } while(!success);
     return choice2;
    }

string continuePlaying(string choiceA, string choiceB)
{
    string choice = " ";
  bool success;
 do {
    cout << "Enter your choice, " << choiceA << " or " << choiceB << "\n";
  cout << " > ";
        cin >> choice;

if (choice=="YES" || choice=="yes"){
    success=true;
  }
   else if (choice=="NO" || choice=="no"){
     break;
}
   else {
     success=false;
   }
   } while(!success);
     return choice;
    }

// ------------------------------------------------------------------------//
// Blacksmith Meeting to Determine Wanting to Forge Silver Key and Having Silver Ore.
string forgeKey(string answerA, string answerB)
{
    string answer = " ";
  bool success;
 do {
    cout << "To forge a silver " << answerA << " or have " << answerB << "\n";
  cout << " > ";
        cin >> answer;

if (answer=="KEY" || answer=="key"){
  break;
    success=true;
  }
   else if (answer=="FUN" || answer=="fun"){
      cout << "\n Why are you here then? Go back.\n\n";
     success=false;
}
   else {
     success=false;
   }
   } while(!success);
     return answer;
    }

// ------------------------------------------------------------------------//
 string twentyCharacters(){       // 3 Words 20 Characters Game Blacksmith
    string word1, word2, word3;
    bool success;
do {
   cout << "Please three(3) words that total 20 characters including spaces. \n";
   cout << " > ";
   
   bool threeWords = (word1.size() > 0) && (word2.size() > 0) && (word3.size() > 0);
  cin >> word1 >> word2 >> word3;
  int countLetters = word1.size() + word2.size() + word3.size();

if (countLetters <= 17) {   
  cout << "Not Enough Characters\n";
  success=false;
}
  else if (countLetters >= 19) {
    cout << "Too Many Charachters\n";
    success=false;
  }
  else if (countLetters == 18) { // 18 characters counted as spaces aren't included in this if-else, 20 - 2 spaces
    success = true;
  }
  } while (!success);
   return word1, word2, word3;
   }

// ------------------------------------------------------------------------//
// Converts US/Imperial inches to metric (Système Internationale) cms.
int inchesToCms(int inches)
{
  // TODO: Check if this works. Fix it if it doesn't (google inches to cms)
  int cms = inches *2.54f;
  return cms;
}
// -------------------------------------------------- //
// Fairy's Gambit

string fairyChoice(string fairyAnswerA, string fairyAnswerB, string fairyAnswerC)
{
    string fairyAnswer = " ";
    bool success;
 do {
  cout << "Where do you want to look first " << fairyAnswerA << " or " << fairyAnswerB << " or say " << fairyAnswerC << "?\n";
  cout << " > ";
      cin >> fairyAnswer;
   
  if (fairyAnswer == "TULIP-PATCH" || fairyAnswer == "tulip-patch" || fairyAnswer == "tulip" || fairyAnswer=="TULIP"){
    success=true;
  }
   else if (fairyAnswer== "VEGETABLE-GARDEN" || fairyAnswer == "vegetable-garden"||fairyAnswer== "VEGETABLE" ||fairyAnswer == "vegetable"){
     cout << "From the entrance, you follow the cobblestone path towards the gardens. \nOpposite to the bright tulip patch futher down the cobblestone path you find yourself in the VEGETABLE-GARDEN. \nYou keep your eyes pealed throughout the journey to make sure you either find the FAIRY CHILD or a CLUE./n/n";
        cout << "No Luck."; 
     success=false;
    }
     else if (fairyAnswer == "NO-THANKS" || fairyAnswer == "no-thanks"){
       break;
     }
   else {
     success=false;
   }
   } while(!success);
     return fairyAnswer;
  }

string fairyChoicE(string fairyAnsweRA, string fairyAnsweRB)
{
    string fairyAnsweR = " ";
    bool success;
 do {
  cout << "Go to the " << fairyAnsweRA << " or say " << fairyAnsweRB << "?\n";
  cout << " > ";
      cin >> fairyAnsweR;
 
   if (fairyAnsweR== "VEGETABLE-GARDEN" || fairyAnsweR == "vegetable-garden"|| fairyAnsweR== "VEGETABLE" || fairyAnsweR == "vegetable"){
     success=true;
    }
     else if (fairyAnsweR == "NO-THANKS" || fairyAnsweR == "no-thanks"|| fairyAnsweR == "no" || fairyAnsweR == "NO"){
       break;
     }
   else {
     success=false;
   }
   } while(!success);
     return fairyAnsweR;
  }

string toThePond(string keepGoingA, string keepGoingB)
{
    string keepGoing = " ";
  bool success;
 do {
    cout << "Enter your choice, " << keepGoingA << " or " << keepGoingB << "\n";
  cout << " > ";
        cin >> keepGoing;

if (keepGoing=="YES" || keepGoing=="yes"){
    success=true;
  }
   else if (keepGoing=="NO" || keepGoing=="no"){
     break;
}
   else {
     success=false;
   }
   } while(!success);
     return keepGoing;
    }

string giveName(string nameA, string nameB)
{
    string name = " ";
    bool success;
 do {
  cout << nameA << " or " << nameB << "?\n";
  cout << " > ";
      cin >> name;
 
   if (name=="YES" || name=="yes"){
     
     cout << "\nYou're doomed.\n";
     cout << "Your knowledge of mythics hasn't paid off. You never give a fairy your real name. \nYour name holds power, and by giving it to the FAIRY you're giving them power over you.\n\n";

     cout << "Answer again\n\n";
     success=false;
     
  }
   else if (name=="NO" || name=="no"){
     success=true;
     break;
}
   else {
     success=false;
   }
   } while(!success);
     return name;
    }

string farewellFairies(string responseA, string responseB)
{
    string response = " ";
  bool success;
 do {
    cout <<  responseA << " Thank you! or " << responseB << " You're much too kind?\n";
  cout << " > ";
        cin >> response;

if (response=="2"){
    success=true;
  }
   else if (response=="1"){
     cout << "YOU: \n";
     cout << " > Thank You!\n";
     cout << "";  cout << "\nBLASPHEMY! You're doomed.\n";
     cout << "Your knowledge of mythics hasn't paid off. You've insulted the FAIRY for their gesture. \nYou've insinuated at you'll forget everything here, including the gift of the RUBY.\n\n";
     cout << "Answer again\n\n";
     success=false;
}
   else {
     success=false;
   }
   } while(!success);
     return response;
    }
// ------------------------------------------------------------------------//
// Blacksmith ROCK PAPER SCISSORS //
  enum weapon {
ROCK = 10,
PAPER,
SCISSORS=30
};

  const int maxGames = 1;

  string show(weapon h){
    if (h == ROCK) return "ROCK";
    if (h == SCISSORS) return "SCISSORS";
    if (h == PAPER) return "PAPER";
  }

  string displayWinner(weapon h, weapon c){
    if (h == ROCK && c == SCISSORS) return "\nHUMAN wins...\nROCK smashes SCISSORS!";
    if (h == ROCK && c == PAPER) return "\nPAPER covers ROCK!\n BLACKSMITH wins!";
    if (h == SCISSORS && c == PAPER) return "\nHUMAN wins...\nSCISSORS cuts PAPER!";
    if (h == SCISSORS && c == ROCK) return "\nROCK smashes SCISSORS!\nBLACKSMITH wins!";
    if (h == PAPER && c == ROCK) return "\nHUMAN wins...\nPAPER covers ROCK!";
    if (h == PAPER && c == SCISSORS) return "\nSCISSORS cuts PAPER! \nBLACKSMITH wins!";
    if (h==c) return "\nIt's a Draw.";
  }


// ------------------------------------------------------------------------//

// Identifies a red gem's type given values for mohs_hardness and specific_gravity.
// Returns a constant from the enum `RedGem` in constants.h
// Data source: https://www.mymathtables.com/calculator/others/precise-gemstone-carat-weight-calculator.html
RedGem getRedGemKind(float mohs_hardness, float specific_gravity)
{
  // TODO: check if the provided values match known values/ranges in  
  // https://www.mymathtables.com/calculator/others/precise-gemstone-carat-weight-calculator.html to identify the type.
  // For now, here's a dummy return value so the program compiles.
  return RedGem::UNIDENTIFIED_RED_GEM;
}
