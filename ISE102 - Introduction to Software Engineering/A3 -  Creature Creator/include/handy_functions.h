#ifndef __handy_functions__
#define __handy_functions__
// Get access to things in constants while coding on replit.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "ise102.h"
#include "constants.h"
using namespace std;
using std::string;

// Add any handy, reusable, utility functions here

// Converts US/Imperial inches to metric (Système Internationale) cms.
int inchesToCms(int inches)
{
// TODO: Check if this works. Fix it if it doesn't (google inches to cms)
  int cms = inches / 3.54f;
  return cms;
}


// Takes in a minimum number (int) and a maximum number (int), returns a random
// number between the min and max (inclusive)
int randomCreature(int min, int max){
  int difference = max - min;
  int rand_range = min + (rand() % (difference+1));
  // send back the result.
  return rand_range;
}

string menuOpen(string openMenuA, string openMenuB) {
  string openMenu = " ";
  bool success;

  do {
    cout << "\nEnter [" << openMenuA << "] to open menu or [" << openMenuB << "] to log out.\n";
    cout << " > ";
    cin >> openMenu;

    if (openMenu=="M" || openMenu=="m"){
      success=true;
    }
    else if (openMenu == "X" || openMenu=="x"){
      success=true;
      }
    else {
      cout << "Try again";
      success=false;
    }
  }while(!success);
  return openMenu;
};

string menuResume(string resumeMenuA, string resumeMenuB) {
  string resumeMenu = " ";
  bool success;

  do {
    cout << "\nEnter [" << resumeMenuA << "] to open menu or [" << resumeMenuB << "] to log out.\n";
    cout << " > ";
    cin >> resumeMenu;

    if (resumeMenu=="M" || resumeMenu=="m"){
      success=true;
    }
    else if (resumeMenu == "X" || resumeMenu=="x"){
      success=false;
      cout << "Thanks!\n";
      cout << "Logging Out\n\n";

      cout << "LOGGED OUT\n\n";
      }
    else {
      cout << "Try again";
      success=false;
    }
  }while(!success);
  return resumeMenu;
};

string backToMenu(string pressA) {
  string press = " ";
  bool success;

  do {
    cout << "\n\nPress [" << pressA << "] to go back to Menu\n";
    cout << " > ";
    cin >> press;
    cout << "\n";

    if (press=="X" || "x"){
      success=true;
    }

      else {
      cout << "Try again";
      success=false;
    }
  }while(!success);
  return press;
};

#endif