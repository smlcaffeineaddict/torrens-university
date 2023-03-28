#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Card.h"
#include "include/handy_functions.h"
#include "include/ise102.h"

using namespace std;

void displayTitle();
void displayIntro();
bool playerSignIn();
bool signOut();
bool signInAgain();
bool savefile();

//--------Main Menu
bool openMenu();
bool showMenu();

//--------Creature List
bool showCreatureList();
bool selectCard();

//-------- Creature Card Template
void creatures(gameCard card);

//--------Creature Profiles
void creature1();
void creature2();
void creature3();
void creature4();
void creature5();
void creature6();
void creature7();
void creature8();
void creature9();
void creature10(); 

//-------- Random Draw
int draw();
bool randomDraw();

//-------- Find & Edit
bool findCard();
bool editCard();
void duplicateCard();

//-------- Create New
bool createCard();
bool newCard();
void newCardDupl();

int main(){
  displayTitle();
  playerSignIn();
  
} 


//-------- Introduction 
bool playerSignIn(){
  string username;
  string password;
  bool success;

 fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"== S I G N  I N ==\n\n");
do {
 fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender), "Username: ");
  cin >> username;

  fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender), "Password: ");
  cin >> password;

  fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"\n=================\n");

  if (username =="Tia" || username =="tia" && password == "ise102") {
    delay(500);
    cout << "\n  Welcome Back, Tia.\n";
    delay(500);
    cout << "\n  Logging In...\n\n";
    success=true;
    displayIntro();
    openMenu();
    
  }

  else if (username == "Shazi" || username =="shazi" && password == "ise102"){
    delay(500);
    cout << "\n  Hi, Shazi!\n";
    delay(500);
    cout << "\n  Logging In...\n\n";
    success=true;
    displayIntro();
    openMenu();
  }
  else if (username == "guest" || username =="Guest" && password == "guest"){
    delay(500);
    cout << "\n  Welcome, Guest.\n";
    delay(500);
    cout << "\n  Logging In...\n\n";
    success=true;
    displayIntro();
    openMenu();
  }

  else {
    delay(500);
    cout <<"\n\tYour login failed.\n\tPlease Try Again.\n";
    
  fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"\n=================\n");
    success=false;
  }
 } while (!success);
  return 0;
  }  
void displayTitle() {
fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"\n====== C R E A T U R E   C R E  A T O R ======\n\n");
  cout << "Welcome to the Creature Creator.\n\n";
}
void displayIntro(){
  delay(500);
  cout << "\t....INITIALISING\n\n";
  delay(1000);
  cout << "\t....SIGNING IN\n\n";
  delay(1000);
  cout << "\t....LOADING SPECS\n\n";
delay(1500);
  cout << "\tLOADING...\n";
  delay(1000);
   fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"\t\t\n\n== LOGGED IN!");
delay (1000);
  fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"\n=================\n");

  cout << "Welcome to the Creature Creator. \nLearn about created creatures or create your own.\n\n";

}

bool openMenu(){
  string select;
        do {
        
 fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender), "Enter [M] to open menu or [X] to log out.\n");
        cout << " > ";
    cin >> select;

        if (select=="M"||select=="m"){
          showMenu();
          return 0;
          }
        
    } while ((select != "X" && select != "x" ));
   signOut();
  return 0;
}
bool showMenu(){
  string choice;

  do {
      fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"\n==== [M] Menu ====\n");
     cout << "[L] List Creature Cards\t\t[D] Draw Creature Card\n[A] Add New Creature Card\t[E] Edit Existing Creature Card\n";
      fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"\t\t\t\t\t\t\t\t\t\t ==== [X] Exit ====\n");
    cout << " > ";
    cin >> choice;

     if (choice=="L"||choice=="l") {
        showCreatureList();
          } 
     else if (choice=="D"||choice=="d") { 
        randomDraw();
          }   
     else if (choice=="A"||choice=="a") {
       createCard();
          }   
   else if (choice=="E"||choice=="e") {
      cout << "-------------------\n";
      cout << "\nFind Creature Card \t\t\t\t\t\t ==== [X] Exit ====\n\n";
        findCard();
        } 
  } while ((choice != "X" && choice != "x" ));
  signOut();
  return 0;
}

bool saveFile(){
  string yesorno;
  
      fmt::print(fmt::emphasis::bold | fg(fmt::color::gainsboro),"\nDo you wish to save? [Y] or [N]\n\t> ");
  cin >> yesorno;
  
  if (yesorno=="y"||yesorno=="Y"){
    delay(500);
    cout << "\n\t...Saving...";
    delay (1500);
        fmt::print(fmt::emphasis::bold | fg(fmt::color::gainsboro),"\n\nSaved.\n");
    return 0;
    }
    else if (yesorno=="n"||yesorno=="N"){
     ofstream outFile("duplicate.txt");
     ifstream readFile("original.txt");
        outFile << readFile.rdbuf();

      ofstream fileOut("test.txt");
      ifstream fileRead("data.txt");
      fileOut << fileRead.rdbuf();
      
      return 0;
    }
  return 0;
    }
bool signInAgain(){
       string again;
      do {
        fmt::print(fmt::emphasis::bold | fg(fmt::color::gainsboro),"-----------------------------\n");
        fmt::print(fmt::emphasis::bold | fg(fmt::color::gainsboro), "| Sign In Again? [Y] or [N] | ");
        fmt::print(fmt::emphasis::bold | fg(fmt::color::gainsboro),"\n-----------------------------\n");
        // cout >> "\t> ";
        cin >> again;
        if (again=="Y"||again=="y"){
          system("clear");
          displayTitle();
          playerSignIn();         
        }
      } while((again=="N"&&again=="n"));
      cout << "\nEnd Program.\n";
      return 0;
}
bool signOut(){
  string yesorno;
      
  do {
    fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"\nDo You Want to Sign Out? [Y] or [N]\n"); 
    cout << " > ";
    cin >> yesorno;

    if (yesorno == "n" || yesorno=="N"){
      openMenu();
      } 
    } while ((yesorno=="Y"&&yesorno=="y"));
      saveFile();
  delay(1000);
      fmt::print(fmt::emphasis::bold, "\n\tLogging Out\n\n");
  delay(2000);
      fmt::print(fmt::emphasis::bold | fg(fmt::color::lavender),"\t==== L O G G E D  O U T ====\n\n");
       signInAgain();  
      return 0;
}

//-------- Creature Card Development
void creatures(gameCard card){
  fmt::print(fmt::emphasis::bold | fg(fmt::color::misty_rose),"\n------------------------------------------------\n");
  fmt::print(fmt::emphasis::bold,"\tID: {0}\n",card.id);
  fmt::print(fmt::emphasis::bold,"\tName: {0}\n",card.name); 
  fmt::print(fmt::emphasis::bold,"\tSpecies: {0} \n", card.species);
  print("\tDescription: {0} \n\n", card.desc);
  cout << "\t\tMP: " << card.mp << "\t| \t HP: " << card.hp << "\n\n";
  cout << "\tSTR : " << card.str << "\t| \tDEX : " << card.dex << "\t| \tCOM : " << card.com << "\n";
  cout << "\tINT : " << card.intel << "\t| \tWIS : " << card.wis << "\t| \tSTA : " << card.sta << "\n";
  cout << "\n\tATTACK: " << card.att << "\t| \tDEFENSE : " << card.def << "\n";
  cout << "\n\tRARITY: " << card.rar << "\n";
   fmt::print(fmt::emphasis::bold | fg(fmt::color::misty_rose),"------------------------------------------------\n");
}

//-------- Creature Card Information
void creature1(){
 
  // Creature 1
  gameCard cre_1;
    cre_1.id = "[1]";
    cre_1.name = "Sparkle";
    cre_1.species = "Fwooper";
    cre_1.desc = "A magical African bird with brightly-coloured feathers, which could include orange, pink, lime green and yellow. Listening to the Fwooper's high pitched, twittering song would drive the listener insane, so each bird must be sold with a Silencing Charm placed on it. The Charm had to be reinforced monthly, and a licence was required to own one of the birds.";
    cre_1.mp = 100;
    cre_1.hp = 100;
  
  //Specifications are out of 100 each.
    cre_1.str = 10; // strength
    cre_1.dex = 90; // dexterity
    cre_1.com = 20; // combat
    cre_1.intel = 90; // intelligence
    cre_1.wis = 50; // wisdom
    cre_1.sta = 50; // stamina

    cre_1.att = cre_1.str + cre_1.dex + cre_1.com + cre_1.sta + cre_1.intel; // Attack strongest is 500
    cre_1.def = cre_1.str + cre_1.com + cre_1.intel + cre_1.sta + cre_1.wis;
  // Defense strongest is 500

    if ((cre_1.att+cre_1.def)==1000) {
    cre_1.rar = "Mythic";
  }
    else if ((cre_1.att+cre_1.def)>=800) {
    cre_1.rar = "Legendary";
  }
    else if ((cre_1.att+cre_1.def)>=700) {
    cre_1.rar = "Epic";
  }
    else if ((cre_1.att+cre_1.def)>=600) {
    cre_1.rar = "Super Rare";
  }
    else if ((cre_1.att+cre_1.def)>=500) {
    cre_1.rar = "Rare";
  }
    else if ((cre_1.att+cre_1.def)<500) {
    cre_1.rar = "Common";
  }

  
   
// print
  creatures(cre_1);
  //
  } // Fwooper
void creature2(){
 
  // Creature 2
  gameCard cre_2;
    cre_2.id = "[2]";
    cre_2.name = "Snooze";
    cre_2.species = "Acromantula";
    cre_2.desc = "A giant magical species of spider native to the rainforests of Southeast Asia, particularly Borneo, where it inhabited dense jungles. Sporting eight black eyes (white if blind) and were typically covered in thick black hair, with a leg span that could reach up to fifteen feet.";
    cre_2.mp = 100;
    cre_2.hp = 100;
  
  //Specifications are out of 100 each.
    cre_2.str = 90; // strength
    cre_2.dex = 80; // dexterity
    cre_2.com = 75; // combat
    cre_2.intel = 82; // intelligence
    cre_2.wis = 90; // wisdom
    cre_2.sta = 20; // stamina

    cre_2.att = cre_2.str + cre_2.dex + cre_2.com + cre_2.sta + cre_2.intel; // Attack strongest is 500
    cre_2.def = cre_2.str + cre_2.com + cre_2.intel + cre_2.sta + cre_2.wis;
  // Defense strongest is 500

    if ((cre_2.att+cre_2.def)==1000) {
    cre_2.rar = "Mythic";
  }
    else if ((cre_2.att+cre_2.def)>=800) {
    cre_2.rar = "Legendary";
  }
    else if ((cre_2.att+cre_2.def)>=700) {
    cre_2.rar = "Epic";
  }
    else if ((cre_2.att+cre_2.def)>=600) {
    cre_2.rar = "Super Rare";
  }
    else if ((cre_2.att+cre_2.def)>=500) {
    cre_2.rar = "Rare";
  }
    else if ((cre_2.att+cre_2.def)<500) {
    cre_2.rar = "Common";
  }
 
// print
  creatures(cre_2);
  //
  } // Acromantula
void creature3(){
 
  // Creature 3
  gameCard cre_3;
    cre_3.id = "[3]";
    cre_3.name = "Birdie";
    cre_3.species = "Jobberknoll";
    cre_3.desc = "A small, magical, blue speckled bird. The Jobberknoll never made any noise until the moment before it dies. It would then release a long scream, which consisted of every sound it ever heard backwards. It lived in northern Europe and North America and fed mainly on small insects. Jobberknoll feathers were used as potion ingredients in Truth serums and Memory Potions.";
    cre_3.mp = 100;
    cre_3.hp = 100;
  
  //Specifications are out of 100 each.
    cre_3.str = 10; // strength
    cre_3.dex = 90; // dexterity
    cre_3.com = 20; // combat
    cre_3.intel = 95; // intelligence
    cre_3.wis = 80; // wisdom
    cre_3.sta = 50; // stamina

    cre_3.att = cre_3.str + cre_3.dex + cre_3.com + cre_3.sta + cre_3.intel; // Attack strongest is 500
    cre_3.def = cre_3.str + cre_3.com + cre_3.intel + cre_3.sta + cre_3.wis;
  // Defense strongest is 500

    if ((cre_3.att+cre_3.def)==1000) {
    cre_3.rar = "Mythic";
  }
    else if ((cre_3.att+cre_3.def)>=800) {
    cre_3.rar = "Legendary";
  }
    else if ((cre_3.att+cre_3.def)>=700) {
    cre_3.rar = "Epic";
  }
    else if ((cre_3.att+cre_3.def)>=600) {
    cre_3.rar = "Super Rare";
  }
    else if ((cre_3.att+cre_3.def)>=500) {
    cre_3.rar = "Rare";
  }
    else if ((cre_3.att+cre_3.def)<500) {
    cre_3.rar = "Common";
  }

  
   
// print
  creatures(cre_3);
  //
  } // Jobberknoll
void creature4(){
 
  // Creature 4
  gameCard cre_4;
    cre_4.id = "[4]";
    cre_4.name = "Darling";
    cre_4.species = "Nundu";
    cre_4.desc = "A large East African magical beast that resembled a leopard. It moved silently, despite its gigantic size and was considered by some to be the most dangerous creature alive. The breath of the Nundu was toxic and filled with disease so potent that it can wipe out entire villages of people.";
    cre_4.mp = 100;
    cre_4.hp = 100;
  
  //Specifications are out of 100 each.
    cre_4.str = 88; // strength
    cre_4.dex = 90; // dexterity
    cre_4.com = 70; // combat
    cre_4.intel = 85; // intelligence
    cre_4.wis = 68; // wisdom
    cre_4.sta = 80; // stamina

    cre_4.att = cre_4.str + cre_4.dex + cre_4.com + cre_4.sta + cre_4.intel; // Attack strongest is 500
    cre_4.def = cre_4.str + cre_4.com + cre_4.intel + cre_4.sta + cre_4.wis;
  // Defense strongest is 500

    if ((cre_4.att+cre_4.def)==1000) {
    cre_4.rar = "Mythic";
  }
    else if ((cre_4.att+cre_4.def)>=800) {
    cre_4.rar = "Legendary";
  }
    else if ((cre_4.att+cre_4.def)>=700) {
    cre_4.rar = "Epic";
  }
    else if ((cre_4.att+cre_4.def)>=600) {
    cre_4.rar = "Super Rare";
  }
    else if ((cre_4.att+cre_4.def)>=500) {
    cre_4.rar = "Rare";
  }
    else if ((cre_4.att+cre_4.def)<500) {
    cre_4.rar = "Common";
  }

  
   
// print
  creatures(cre_4);
  //
  } // Nundu
void creature5(){
 
  // Creature 5
  gameCard cre_5;
    cre_5.id = "[5]";
    cre_5.name = "Doe";
    cre_5.species = "Porlock";
    cre_5.desc = "A small creature, reaching a height of two feet on average when they were fully grown, and covered in a large amount of rough, shaggy hair. They had a large nose, small arms ending in four stubby fingers, and they walked on two cloven hooves.";
    cre_5.mp = 70;
    cre_5.hp = 100;
  
  //Specifications are out of 100 each.
    cre_5.str = 70; // strength
    cre_5.dex = 50; // dexterity
    cre_5.com = 60; // combat
    cre_5.intel = 80; // intelligence
    cre_5.wis = 80; // wisdom
    cre_5.sta = 90; // stamina

    cre_5.att = cre_5.str + cre_5.dex + cre_5.com + cre_5.sta + cre_5.intel; // Attack strongest is 500
    cre_5.def = cre_5.str + cre_5.com + cre_5.intel + cre_5.sta + cre_5.wis;
  // Defense strongest is 500

    if ((cre_5.att+cre_5.def)==1000) {
    cre_5.rar = "Mythic";
  }
    else if ((cre_5.att+cre_5.def)>=800) {
    cre_5.rar = "Legendary";
  }
    else if ((cre_5.att+cre_5.def)>=700) {
    cre_5.rar = "Epic";
  }
    else if ((cre_5.att+cre_5.def)>=600) {
    cre_5.rar = "Super Rare";
  }
    else if ((cre_5.att+cre_5.def)>=500) {
    cre_5.rar = "Rare";
  }
    else if ((cre_5.att+cre_5.def)<500) {
    cre_5.rar = "Common";
  }

  
   
// print
  creatures(cre_5);
  //
  } // Porlock
void creature6(){
 
  // Creature 6
  gameCard cre_6;
    cre_6.id = "[6]";
    cre_6.name = "Yuuki";
    cre_6.species = "Kappa";
    cre_6.desc = "A Japanese water demon that fed on human blood. They were known for strangling humans that invaded their shallow ponds.";
    cre_6.mp = 100;
    cre_6.hp = 100;
  
  //Specifications are out of 100 each.
    cre_6.str = 80; // strength
    cre_6.dex = 65; // dexterity
    cre_6.com = 80; // combat
    cre_6.intel = 75; // intelligence
    cre_6.wis = 55; // wisdom
    cre_6.sta = 50; // stamina

    cre_6.att = cre_6.str + cre_6.dex + cre_6.com + cre_6.sta + cre_6.intel; // Attack strongest is 500
    cre_6.def = cre_6.str + cre_6.com + cre_6.intel + cre_6.sta + cre_6.wis;
  // Defense strongest is 500

    if ((cre_6.att+cre_6.def)==1000) {
    cre_6.rar = "Mythic";
  }
    else if ((cre_6.att+cre_6.def)>=800) {
    cre_6.rar = "Legendary";
  }
    else if ((cre_6.att+cre_6.def)>=700) {
    cre_6.rar = "Epic";
  }
    else if ((cre_6.att+cre_6.def)>=600) {
    cre_6.rar = "Super Rare";
  }
    else if ((cre_6.att+cre_6.def)>=500) {
    cre_6.rar = "Rare";
  }
    else if ((cre_6.att+cre_6.def)<500) {
    cre_6.rar = "Common";
  }

  
   
// print
  creatures(cre_6);
  //
  } // Kappa
void creature7(){
 
  // Creature 7
  gameCard cre_7;
    cre_7.id = "[7]";
    cre_7.name = "Fish";
    cre_7.species = "Shrake";
    cre_7.desc = "A magically-created species of fish, found in the Atlantic Ocean. The creature was covered in spines.The spines of the Shrake could be used as a potion ingredient.";
    cre_7.mp = 100;
    cre_7.hp = 100;
  
  //Specifications are out of 100 each.
    cre_7.str = 50; // strength
    cre_7.dex = 50; // dexterity
    cre_7.com = 50; // combat
    cre_7.intel = 20; // intelligence
    cre_7.wis = 40; // wisdom
    cre_7.sta = 80; // stamina

    cre_7.att = cre_7.str + cre_7.dex + cre_7.com + cre_7.sta + cre_7.intel; // Attack strongest is 500
    cre_7.def = cre_7.str + cre_7.com + cre_7.intel + cre_7.sta + cre_7.wis;
  // Defense strongest is 500

    if ((cre_7.att+cre_7.def)==1000) {
    cre_7.rar = "Mythic";
  }
    else if ((cre_7.att+cre_7.def)>=800) {
    cre_7.rar = "Legendary";
  }
    else if ((cre_7.att+cre_7.def)>=700) {
    cre_7.rar = "Epic";
  }
    else if ((cre_7.att+cre_7.def)>=600) {
    cre_7.rar = "Super Rare";
  }
    else if ((cre_7.att+cre_7.def)>=500) {
    cre_7.rar = "Rare";
  }
    else if ((cre_7.att+cre_7.def)<500) {
    cre_7.rar = "Common";
  }

  
   
// print
  creatures(cre_7);
  //
  } // Shrake
void creature8(){
 
  // Creature 8
  gameCard cre_8;
    cre_8.id = "[8]";
    cre_8.name = "Ghost";
    cre_8.species = "Lethifold";
    cre_8.desc = "Also known as the Living Shroud, is a carnivorous and extremely dangerous magical beast. It is also considered a Dark creature because of its extremely aggressive and violent nature. The Lethifold resembled a black cloak roughly half an inch thick, and appeared slightly thicker if the creature had recently digested a victim. It glided along surfaces in an unknown form of locomotion in search of its prey, humans. It attacked at night, when the target was asleep, by suffocating and then digesting them.";
    cre_8.mp = 100;
    cre_8.hp = 100;
  
  //Specifications are out of 100 each.
    cre_8.str = 98; // strength
    cre_8.dex = 90; // dexterity
    cre_8.com = 88; // combat
    cre_8.intel = 80; // intelligence
    cre_8.wis = 95; // wisdom
    cre_8.sta = 91; // stamina

    cre_8.att = cre_8.str + cre_8.dex + cre_8.com + cre_8.sta + cre_8.intel; // Attack strongest is 500
    cre_8.def = cre_8.str + cre_8.com + cre_8.intel + cre_8.sta + cre_8.wis;
  // Defense strongest is 500

    if ((cre_8.att+cre_8.def)==1000) {
    cre_8.rar = "Mythic";
  }
    else if ((cre_8.att+cre_8.def)>=800) {
    cre_8.rar = "Legendary";
  }
    else if ((cre_8.att+cre_8.def)>=700) {
    cre_8.rar = "Epic";
  }
    else if ((cre_8.att+cre_8.def)>=600) {
    cre_8.rar = "Super Rare";
  }
    else if ((cre_8.att+cre_8.def)>=500) {
    cre_8.rar = "Rare";
  }
    else if ((cre_8.att+cre_8.def)<500) {
    cre_8.rar = "Common";
  }

// print
  creatures(cre_8);
  //
  } // Lethifold
void creature9(){
 
  // Creature 9
  gameCard cre_9;
    cre_9.id = "[9]";
    cre_9.name = "Wizzle";
    cre_9.species = "Jarvey";
    cre_9.desc = "A magical beast which resembled an overgrown ferret in appearance, and was commonly found in Great Britain, Ireland, and North America. Jarvey were particularly good at hunting Gnomes, and were sometimes employed to de-gnome a garden, although their methods were usually brutal.";
    cre_9.mp = 100;
    cre_9.hp = 100;
  
  //Specifications are out of 100 each.
    cre_9.str = 40; // strength
    cre_9.dex = 90; // dexterity
    cre_9.com = 20; // combat
    cre_9.intel = 90; // intelligence
    cre_9.wis = 50; // wisdom
    cre_9.sta = 50; // stamina

    cre_9.att = cre_9.str + cre_9.dex + cre_9.com + cre_9.sta + cre_9.intel; // Attack strongest is 500
    cre_9.def = cre_9.str + cre_9.com + cre_9.intel + cre_9.sta + cre_9.wis;
  // Defense strongest is 500

    if ((cre_9.att+cre_9.def)==1000) {
    cre_9.rar = "Mythic";
  }
    else if ((cre_9.att+cre_9.def)>=800) {
    cre_9.rar = "Legendary";
  }
    else if ((cre_9.att+cre_9.def)>=700) {
    cre_9.rar = "Epic";
  }
    else if ((cre_9.att+cre_9.def)>=600) {
    cre_9.rar = "Super Rare";
  }
    else if ((cre_9.att+cre_9.def)>=500) {
    cre_9.rar = "Rare";
  }
    else if ((cre_9.att+cre_9.def)<500) {
    cre_9.rar = "Common";
  }
   
// print
  creatures(cre_9);
  //
  } // Jarvey
void creature10(){
 
  // Creature 10
  gameCard cre_10;
    cre_10.id = "[10]";
    cre_10.name = "Goldie";
    cre_10.species = "Golden Snidget";
    cre_10.desc = "A small golden magical bird with fully rotational wings. Once common in northern Europe, but because of their aptitude at hiding and extreme speed that they used as their survival strategy to avoid predators.";
    cre_10.mp = 100;
    cre_10.hp = 100;
  
  //Specifications are out of 100 each.
    cre_10.str = 25; // strength
    cre_10.dex = 100; // dexterity
    cre_10.com = 35; // combat
    cre_10.intel = 90; // intelligence
    cre_10.wis = 90; // wisdom
    cre_10.sta = 95; // stamina

    cre_10.att = cre_10.str + cre_10.dex + cre_10.com + cre_10.sta + cre_10.intel; // Attack strongest is 500
    cre_10.def = cre_10.str + cre_10.com + cre_10.intel + cre_10.sta + cre_10.wis;
  // Defense strongest is 500

    if ((cre_10.att+cre_10.def)==1000) {
    cre_10.rar = "Mythic";
  }
    else if ((cre_10.att+cre_10.def)>=800) {
    cre_10.rar = "Legendary";
  }
    else if ((cre_10.att+cre_10.def)>=700) {
    cre_10.rar = "Epic";
  }
    else if ((cre_10.att+cre_10.def)>=600) {
    cre_10.rar = "Super Rare";
  }
    else if ((cre_10.att+cre_10.def)>=500) {
    cre_10.rar = "Rare";
  }
    else if ((cre_10.att+cre_10.def)<500) {
    cre_10.rar = "Common";
  }
   
// print
  creatures(cre_10);
  } // Golden Snidget
// ------------------

//-------- Links to Creature profiles from List
bool showCreatureList(){ 
  fmt::print(fmt::emphasis::bold | fg(fmt::color::misty_rose),"\n==== Creature List ====\n\n");
  fmt::print(fmt::emphasis::bold | fg(fmt::color::misty_rose),"  ID\tCreature Name\t\tSpecies\t\t\tRarity\t\t\tATT\tDEF\n");
fmt::print(fmt::emphasis::bold | fg(fmt::color::misty_rose),"-------------------------------------------------------------------\n");
    fstream creatures;
   creatures.open("duplicate.txt", ios::in);
    if (creatures.is_open()){
      string creaturesum;

      while(getline(creatures, creaturesum)){
        
        cout << creaturesum << "\n";
      }
      creatures.close();
    }
    selectCard();
    return 0;
} 
bool selectCard(){
  string select;
  do {
     fmt::print(fmt::emphasis::bold | fg(fmt::color::misty_rose),"\n\nSelect ID number [1-10] to view card or [X] to Exit List\n");
    cout << " > ";
    cin >> select;
    
    if (select=="1"){
      string back;
      do {
        creature1();
          cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0;  
      } 
    else if (select=="2"){
      string back;
      do {
        creature2();
          cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0;       
      }
    else if (select=="3"){
      string back;
      do {
        creature3();
          cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0;               
      }
    else if (select=="4"){
      string back;
      do {
        creature4();
          cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0;              
      }
    else if (select=="5"){
      string back;
      do {
        creature5();
          cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0;             
      }
    else if (select=="6"){
      string back;
      do {
        creature6();
          cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0;              
      }
    else if (select=="7"){
      string back;
      do {
        creature7();
            cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0;           
      }
    else if (select=="8"){
     string back;
      do {
        creature8();
            cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0; 
      }
    else if (select=="9"){
      string back;
      do {
        creature9();
           cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0;  
      }
    else if (select=="10"){
      string back;
      do {
        creature10();
            cout << "\n[B] Back to List or [X] Exit\n";
          cout << " > ";
          cin >> back;

          if (back=="B"||back=="b"){
           showCreatureList();
           }
        } while((back=="X"&&back=="x"));
          return 0;
      }
  } while((select=="X"&&select=="x"));
      return 0;
} 

//-------- Random Card Draw from Base Cards
int draw(){
  	srand( time(NULL) ); 
	int randNum = rand() % 10+1; // Generate a random number between 0 and 10

	//cout << randNum; 
      if (randNum==1){
          cout <<"\n";
          creature1();
        }
      else if (randNum==2){
          cout <<"\n";
          creature2();
        }
      else if (randNum==3){
          cout <<"\n";
          creature3();
        }
      else if (randNum==4){
          cout <<"\n";
          creature4();
        }
      else if (randNum==5){
          cout <<"\n";
          creature5();
        }
      else if (randNum==6){
          cout <<"\n";
          creature6();
        }
      else if (randNum==7){
          cout <<"\n";
          creature7();
        }
      else if (randNum==8){
          cout <<"\n";
          creature8();
        }
      else if (randNum==9){
          cout <<"\n";
          creature9();
        }
      else if (randNum==10){
          cout <<"\n";
          creature10();
        }
	return randNum; 
}
bool randomDraw(){
  string select;

  do {
    fmt::print(fmt::emphasis::bold | fg(fmt::color::medium_aquamarine),"\n=== Draw Creature Card ===\n\n");
    cout << "Welcome to the Random Draw.\nCards from System are used for random draw.\n";
    fmt::print(fmt::emphasis::bold | fg(fmt::color::medium_aquamarine),"Press [R] to Roll or [X] to Back To Menu\n");
    cout << "\t> ";
    cin >> select;

    if (select=="R"||select=="r"){
     
     // return randomDraw();
      draw();
      string select; 
      do {
      fmt::print(fmt::emphasis::bold | fg(fmt::color::medium_aquamarine),"\nReRoll? [R] or Exit [X]?\n");
        cout << "\t> ";
        cin >> select;

        if (select=="R" || select=="r"){
          draw();
            }
      } while ((select!="X"&&select!="x"));
        return randomDraw();
      }
    } while ((select=="X"&&select=="x"));
        return 0;
}

//--------  Enter & Save Data  
bool createCard(){
string ch; // indicator to move on

  do {
  fmt::print(fmt::emphasis::bold | fg(fmt::color::honey_dew),"\n=== Add New Creature Card ===\n\n");
     cout << "[C] Create Another Creature"; 
       fmt::print(fmt::emphasis::bold | fg(fmt::color::honey_dew),"\t\t\t\t ==== [X] Exit ====\n");
     cout << "\t> "; cin >> ch; 
    
    if (ch=="c"||ch=="C"){
      newCard();
      }
  
    } while ((ch!="X"&&ch!="x"));
    return 0;
}
bool newCard(){
  
  ofstream outFile("replaced.txt");
  ifstream readFile("test.txt");
  fmt::print(fmt::emphasis::bold | fg(fmt::color::honey_dew),"\nEnter New Creature Data\n");
  fmt::print(fmt::emphasis::bold | fg(fmt::color::medium_aquamarine), "-----------------------------------\n");
    cout << " **Enter ID number after 10. \n **Keep track of new ID numbers.\n"<< endl;

 struct CreatureCard inCard, replaceCard;
  cout << "\tID: "; cin >> replaceCard.id;
  cout << "\tCreature Name:  "; cin >> ws; getline(cin,replaceCard.name);
  cout << "\tSpecies: ";  getline(cin,replaceCard.species);
  cout << "\tEnter Description: "; getline(cin,replaceCard.description);
  cout << "\tMP (Magic Points): "; cin >> replaceCard.mp;
  cout << "\tHP (Health Points): ";  cin >> replaceCard.hp;
  cout << "\tStrength: "; cin >> replaceCard.str;
  cout << "\tDexterity: ";  cin >> replaceCard.dex;
  cout << "\tCombat: "; cin >> replaceCard.com;
  cout << "\tIntelligence: ";  cin >> replaceCard.intel;
  cout << "\tWisdom: "; cin >> replaceCard.wis;
  cout << "\tStamina: ";  cin >> replaceCard.sta;

  replaceCard.att = replaceCard.str + replaceCard.dex + replaceCard.com + replaceCard.sta + replaceCard.intel;
  replaceCard.def = replaceCard.str + replaceCard.com + replaceCard.intel + replaceCard.sta + replaceCard.wis;

  if ((replaceCard.att+replaceCard.def)==1000) {
            replaceCard.rar = "Mythic";
          }
  else if ((replaceCard.att+replaceCard.def)>=800) {
            replaceCard.rar = "Legendary";
          }
  else if ((replaceCard.att+replaceCard.def)>=700) {
            replaceCard.rar = "Epic";
          }
  else if ((replaceCard.att+replaceCard.def)>=600) {
           replaceCard.rar = "Super Rare";
          }
  else if ((replaceCard.att+replaceCard.def)>=500) {
            replaceCard.rar = "Rare";
          }
  else if ((replaceCard.att+replaceCard.def)<500) {
          replaceCard.rar = "Common";
          }

 while (readFile.good()) {
    readFile >> inCard;

    // the << operator writes the whole record
    if (readFile.good()) {
      outFile << inCard << endl;
    }
 }
  outFile << replaceCard;
    newCardDupl();
    remove("test.txt");
	  rename("replaced.txt", "test.txt");
  
     string ch; // Indicator
  
    fmt::print(fmt::emphasis::bold | fg(fmt::color::medium_aquamarine), "[V] View Creature Card \t\t\t\t\t\t ==== [X] Exit ====\n");
    cout << "\t> ";
    cin >> ch;

    if (ch=="x"||ch=="X"){
      return 0;
    }
    else if (ch=="V"||ch=="v"){
  fmt::print(fmt::emphasis::bold | fg(fmt::color::medium_aquamarine), "-----------------------------------\n");
      cout << "\n\tID: ["<<replaceCard.id<<"]";
      cout << "\n\tName: " << replaceCard.name;
      cout << "\n\tSpecies: " << replaceCard.species;
      cout << "\n\tDescription: " << replaceCard.description; 
      cout << "\n\t\tMP: " << replaceCard.mp << "\t|\tHP: " << replaceCard.hp; 
      cout << "\n\tSTR: " << replaceCard.str << "\t|\tDEX: " << replaceCard.dex << "\t|\tCOM: " << replaceCard.com; 
      cout << "\n\tINT: " << replaceCard.intel << "\t|\tWIS: " << replaceCard.wis << "\t|\tSTA: " << replaceCard.sta; 
      cout << "\n\tATTACK: " << replaceCard.att << "\t|\tDEFENSE: " << replaceCard.def;
      cout << "\n\tRARITY: " << replaceCard.rar;
  fmt::print(fmt::emphasis::bold | fg(fmt::color::medium_aquamarine), "-----------------------------------\n");
    }
  return 0;
  }
void newCardDupl(){
  ofstream outFile("duplicate.txt");
  ifstream readFile("replaced.txt");

  CreatureCardDupl inCard, replaceCard;
  while(readFile.good()){
    readFile >> inCard;

    if(readFile.good()){
      outFile << inCard;
    }
    
  }
  cout << "Data Update... Success!" << endl;
}

// -------- Find Card via Information
bool findCard(){
  fstream file;
  string srch;
  string line;

  do {
      file.open("duplicate.txt", ios::in);
      cout << "Search by Name, Species, Rarity or [ALL]\n";
      cout << " > ";
      cin.ignore();
      getline(cin,srch);

    if (file.is_open()){
      while(getline(file,line)){
        if (line.find(srch)!=string::npos){
          cout << line << endl;        
        } 
          else if (srch=="all"||"All"||"ALL"){
           fmt::print(fmt::emphasis::bold | fg(fmt::color::dark_salmon),"\n==== Creature List ====\n\n");
  fmt::print(fmt::emphasis::bold | fg(fmt::color::dark_salmon),"  ID\tCreature Name\t\tSpecies\t\t\tRarity\t\t\tATT\tDEF\n");
fmt::print(fmt::emphasis::bold | fg(fmt::color::dark_salmon),"-------------------------------------------------------------------\n");
    fstream creatures;
   creatures.open("duplicate.txt", ios::in);
    if (creatures.is_open()){
      string creaturesum;

      while(getline(creatures, creaturesum)){
        
        cout << creaturesum << "\n";
      }
      creatures.close();
    }
            break;
          }
        else {
          cout << "Try Again.\n";
          findCard();
        }
        }
      }
    else {
    cout << "\nSearch Failed.\n Information could not be found." << endl;
      }
    editCard();
  } while((srch=="X"&&srch=="x"));
    return 0; 
}

// -------- Edit Card Information 
bool editCard(){
  ofstream outFile("replaced.txt");
  ifstream readFile("test.txt");
   fmt::print(fmt::emphasis::bold | fg(fmt::color::dark_salmon),"\n Enter New Creature Data\n");
   fmt::print(fmt::emphasis::bold | fg(fmt::color::dark_salmon),  "-----------------------------------\n");
    cout << " **Enter ID number after 10. \n **Keep track of new ID numbers.\n"<< endl;
 struct EditCreature inRecord, replaceRecord;
  cout << "\tID: "; cin >> replaceRecord.id;
  cout << "\tCreature Name:  "; cin >> ws; getline(cin,replaceRecord.name);
  cout << "\tSpecies: ";  getline(cin,replaceRecord.species);
  cout << "\tEnter Description: "; getline(cin,replaceRecord.description);
  cout << "\tMP (Magic Points): "; cin >> replaceRecord.mp;
  cout << "\tHP (Health Points): ";  cin >> replaceRecord.hp;
  cout << "\tStrength: "; cin >> replaceRecord.str;
  cout << "\tDexterity: ";  cin >> replaceRecord.dex;
  cout << "\tCombat: "; cin >> replaceRecord.com;
  cout << "\tIntelligence: ";  cin >> replaceRecord.intel;
  cout << "\tWisdom: "; cin >> replaceRecord.wis;
  cout << "\tStamina: ";  cin >> replaceRecord.sta;

  replaceRecord.att = replaceRecord.str + replaceRecord.dex + replaceRecord.com + replaceRecord.sta + replaceRecord.intel;
  replaceRecord.def = replaceRecord.str + replaceRecord.com + replaceRecord.intel + replaceRecord.sta + replaceRecord.wis;

  if ((replaceRecord.att+replaceRecord.def)==1000) {
            replaceRecord.rar = "Mythic";
          }
          else if ((replaceRecord.att+replaceRecord.def)>=800) {
            replaceRecord.rar = "Legendary";
          }
          else if ((replaceRecord.att+replaceRecord.def)>=700) {
            replaceRecord.rar = "Epic";
          }
          else if ((replaceRecord.att+replaceRecord.def)>=600) {
           replaceRecord.rar = "Super Rare";
          }
          else if ((replaceRecord.att+replaceRecord.def)>=500) {
            replaceRecord.rar = "Rare";
          }
          else if ((replaceRecord.att+replaceRecord.def)<500) {
          replaceRecord.rar = "Common";
          }

   while (readFile.good()) {
    readFile >> inRecord;

    // the << operator writes the whole record
    if (inRecord.id == replaceRecord.id) {
      outFile << replaceRecord;
    }
    else {
      outFile << inRecord;
    }
  }
  cout << "\nData Change... Success!\n";
      duplicateCard();
      remove("test.txt");
	    rename("replaced.txt", "test.txt");
 string ch; // Indicator
  fmt::print(fmt::emphasis::bold | fg(fmt::color::dark_salmon),"[V] View Creature Card\t\t\t\t\t\t ==== [X] Exit ====\n");
  cout << "\t> ";
  cin >> ch;

  if (ch=="x"||ch=="X"){
    createCard();
  }
  else if (ch=="V"||ch=="v"){
    fmt::print(fmt::emphasis::bold | fg(fmt::color::dark_salmon),"\n-----------------------------------\n");
    cout << "\n\tID: ["<<replaceRecord.id<<"]";
    cout << "\n\tName: " << replaceRecord.name;
    cout << "\n\tSpecies: " << replaceRecord.species;
    cout << "\n\tDescription: " << replaceRecord.description; 
    cout << "\n\t\tMP: " << replaceRecord.mp << "\t|\tHP: " << replaceRecord.hp; 
    cout << "\n\tSTR: " << replaceRecord.str << "\t|\tDEX: " << replaceRecord.dex << "\t|\tCOM: " << replaceRecord.com; 
    cout << "\n\tINT: " << replaceRecord.intel << "\t|\tWIS: " << replaceRecord.wis << "\t|\tSTA: " << replaceRecord.sta; 
    cout << "\n\tATTACK: " << replaceRecord.att << "\t|\tDEFENSE: " << replaceRecord.def;
    cout << "\n\tRARITY: " << replaceRecord.rar;
    fmt::print(fmt::emphasis::bold | fg(fmt::color::dark_salmon),"\n-----------------------------------\n");
    }
  return 0;
 }
void duplicateCard(){
  ofstream outFile("duplicate.txt");
  ifstream readFile("replaced.txt");

  EditCreatureDupl inCard, replaceCard;
  while(readFile.good()){
    readFile >> inCard;

    if(readFile.good()){
      outFile << inCard;
    }
    
  }
}
