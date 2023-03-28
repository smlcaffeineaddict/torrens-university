/****************************************************************
 * Assessment 2: Adventure!
 ****************************************************************
 *
 * You've fallen into a strange underground lair and want out. 
 * A first encounter tells you what you must do: make a key
 * that will open an ancient stone door.
 *
 * More info available in the README.md
 * -------------------------------------------------------------
 * What To Do
 * 
 * - Fix the broken functions
 * - Look for the todos in main for remaining encounters/features
 *   that are needed
 * - Look for other todos for functions that need to be created
 *   or completed
 * - Format the creature dialogue using fmt's prints' styles
 * - Use colour/style elsewhere to communicate the player's situation,
 *   their choices.
 * 
 ***************************************************************/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std; 
#include "include/ise102.h"
#include "include/constants.h"
#include "include/handy_functions.h"
#include "include/fmt/format.h"
#include "include/fmt/color.h"

// Show a pretty box surrounding the name of this game and maybe a blurb
// or subtitle. 
void displayTitleAndIntro(){
  const int TROLL_HEIGHT_INCHES = 30;
  // TODO: Replace the game name with something of your own choosing. Improve the look of the Title here, don't leave it as the ### mess I created.

  string title = "\n\n====== M Y T H I C S - & - M O R T A L S ======\n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::pale_turquoise), title);
  string creature = "RED TROLL";
  cout << "  Chapter 84 of the chronicles of Gorlanda \n";
  string line = "==============================================\n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::pale_turquoise), line);
  cout << "You wake up in a stone corridor, clearly underground and no longer in the forest you were so recently \nstrolling through. A few feet away stands what appears to be - if cartoons are accurate - a thigh-high RED TROLL, \nmaybe ";
  // TODO: This was made for U.S. audiences. Update it to metric (cms) by calling
  // one of the functions in handy_functions.h
  cout << inchesToCms(TROLL_HEIGHT_INCHES) << " centimetres tall.\n\n"; // UPDATE TO CM USING HANDY_FUNCTIONS.H???
}

// ---- THE MINES ---------------------------------------------------------------//
// The troll directs the player to the mines to retrieve ore.
// Introductory text is used if .
bool surviveTrollEncounter(bool already_met)
{
  string troll = "MINE TROLL: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::salmon), troll);
  // If first encounter, troll introduces self, gives quest
  if (already_met == false)
  {
    cout << "G'day human.You need to make a SILVER KEY to escape. Take this EXCELLENT PICKAXE and head to the mines. \nCome back when you have some ORE OF SILVER.\n\n";
  } else
  {
    cout << "What are you doing back out here? No silver, no key!\n\n";
  }
    // Give the player a choice..
  cout << "Do you SPIT on the disgusting troll, or take the pickaxe and go to the MINE?\n";
  string choice = getPlayerChoice("SPIT", "MINE");
  
  // end the function and return true if they mine
  if (choice == "MINE" || choice == "mine") return true;
  // if it hasn't ended, you spat.. uh oh
  cout << "\nThe troll, you discover, is awfully savage for her height.\n\n";
  return false;
}

// The player has a 1 in 3 chance of mining ore. The progress returned
// is either HAVE_ORE or NO_PROGRESS
Progress getSilverMiningOutcome()
{
  const int SHINEY_YELLOW = 1;
  const int COAL = 2;
  const int SILVER = 3;

  // Randomly mine one of the 3 materials above
  Progress silver_progress = Progress::NO_PROGRESS;
  int found = randomInRange(1,3);
  // Tell the player how they did, return their progress
  if ( found == SILVER)
  {
    cout << "Hooray, you found SILVER ORE.\n";
    silver_progress = Progress::HAVE_SILVER_ORE;
  } 
  else if (found == COAL)
  {
    cout << "You found COAL. Worried by the smoke and sparks from your strikes, you LEAVE THE MINE.\n\n";
    string subtitle ="--------------------------------------- \n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::pink), subtitle);
    delay (1000);
    silver_progress = Progress::NO_PROGRESS;
  } 
  else if (found == SHINEY_YELLOW)
  {
    cout << "You find a metal that, on closer inspection, is too YELLOWY GOLDEN to be Silver. \nFrustrated, you toss the nugget aside and stomp BACK INTO THE CORRIDOR.\n\n";
    string subtitle ="--------------------------------------- \n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::pink), subtitle);
    delay (1000);
    silver_progress = Progress::NO_PROGRESS;
  }
  return silver_progress;
}

// Enter the mines looking for silver ore.
Progress mineForSilver()
{
  // TODO: Add a choice here, which area would they prefer to mine? You'll need
  // to describe the area and come up with choices.
  string subtitle ="\n--- THE MINES ------------------------- \n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::pink), subtitle);
  print ("Entering the mine, you see two promising looking walls to your LEFT and RIGHT.\n\n");
  string choice = mineWalls("LEFT", "RIGHT");

   if (choice == "LEFT" || choice == "left"){
    cout << "\nPicking the LEFT wall, you start swinging.\n\n";
    }
  else{
    cout << "\nPicking the RIGHT wall, you start swinging.\n\n";
  }
  
  delay(2000);   // Mining takes time..
  print("**CHANK!!** You knock loose a chunk of something that isn't regular rock..\n\n");
  delay(1500);
 
  Progress silver_progress = getSilverMiningOutcome();
  return silver_progress;
}

// ----- THE BLACKSMITH ------------------------------------------------------------//
// Forge Silver Key with Blacksmith
Progress blacksmithName(){
  delay(1000);
  string blackSmith = "\nBLACKSMITH: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSmith);
  print("Before I forge the SILVER KEY, I require a funny name.\n");
  print ("I want a name made up of 3 words and EXACTLY 20 characters.\n\n");
  twentyCharacters();
   string character;
   Progress silver_progress = Progress::HAVE_SILVER_ORE;
  
  if (character.size() == 20)
  {
   silver_progress = Progress::HAVE_FORGED_KEY;
  } 
  else
  {
    silver_progress = Progress::NO_PROGRESS;
  }
  return silver_progress;

  }
// ---- End Game WIN -----------------------------------------------------------------------//
string endGame() {
   string title = "\n\n====== T H E - E N D ======\n\n";
   fmt::print(fmt::emphasis::bold | fg(fmt::color::pale_turquoise), title);
}
// ------ GAME OVER FUNCTION ----------------------------------------------------------//
// TODO: Create a displayGameOver function that tells you what
// horrible fate ended your short, underground vacation.
void displayGameOver(){
  string gameOver = "\n--- GAME OVER -------------------------";
  fmt::print(fmt::emphasis::bold | bg(fmt::color::red), gameOver);
  cout << "\n\nWrong Decision.\n\nDecisions in the underground tunnel are what keep you alive. You however just made the wrong one, \nwhich ended your short, underground vacation in death.\n\n";
  string playAgain = "Do you Wish to Play Again?\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::red), playAgain);
  string choice = continuePlaying("YES", "NO");
  if (choice == "NO"||choice == "no") {
    cout << "Thanks for Playing!";
 }
  else if (choice == "YES"|| choice =="yes"){
    cout << "Please Re-Start Game";
    }
  return 0;
  }


void fairyGAMEOVER(){
  cout << "You Die.";
     string gameOver = "\n--- GAME OVER -------------------------";
  fmt::print(fmt::emphasis::bold | bg(fmt::color::red), gameOver);
     cout << "\n\nYou didn't pay attention in mythology class, you just abused the kindness of a FAIRY. \n You asked indirectly if they needed help then didn't offer.\n You've realised that Faires aren't always kind.\n\n";
      string playAgain = "Do you Wish to Play Again?\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::red), playAgain);
  string choice = continuePlaying("YES", "NO");
  if (choice == "NO"||choice == "no") {
        cout << "Thanks for Playing!\n\n";
    displayGameOver();
  delay(1500);
  endGame(); 
 }
  else if (choice == "YES"|| choice =="yes"){
    cout << "Please Re-Start Game";
    }
  return 0;
  }


// ----- TO CONTINUE FUNCTION -----------------------------------------------------------//
void toContinue(){
  string pauseLine = "\n----------------------------";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::blue), pauseLine);
  string continueTxt ="\nDo You Wish To Continue?\n";
  fmt::print(fmt::emphasis::bold, continueTxt);
  string choice = continuePlaying("YES", "NO");
  string endLine = "----------------------------";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::blue), endLine);
  if (choice == "NO"||choice == "no") {
    cout << "Thanks for Playing!\n\n";
    displayGameOver();
  delay(1500);
  endGame(); 
    }
  
  }

// ----- FAIRY'S GAMBIT FUNCTION -----------------------------------------------------------//
bool guessFlower()
{
  const int GUESSES_ALLOWED = 3;

  int flower = 2;
  int playerGuess = -1;
  int guessesRemaining = GUESSES_ALLOWED;

    while (flower !=playerGuess&& guessesRemaining > 0){
     cout << " > ";

    cin >> playerGuess;
    guessesRemaining -= 1;

    if (playerGuess == flower){
      cout << "Correct. FAIRY CHILD's favourite flower is a TULIP. That was what she was planning on painting earlier today.\n\n";
    }
    else {
      if (guessesRemaining > 0){
        cout << "wrong. You have " << guessesRemaining << " guesses remaining.\n";
      }
      else {
        cout << "Wrong. Thatt Was your Last Try.\n\n";
    }
    }
  }
 return;
}

int main() {
  srand(time(0));
	// TODO: Students - add game save option? Would have to be able to choose 
  // to continue or start over on load.
  
  Progress game_progress = Progress::NO_PROGRESS;
	clearScreen();
  displayTitleAndIntro();
  
  // As long as the player hasn't found silver ore,
  // keep meeting troll, who sends you to mine for silver
  bool met_troll = false;
  while (game_progress != Progress::HAVE_SILVER_ORE)
  {
    if (surviveTrollEncounter(met_troll))
    {
      met_troll = true;
      // If you're successful, you'll pass the `while` condition!
      game_progress = mineForSilver();
    } else
    {
      //displayGameOver(a message about troll attack);
      displayGameOver();
      return 0;
    }
  }

  // Continue Game Option
  toContinue();


  // ----- TRANSITION PHASE ---------------------------------------------------//
  // TODO: encounter another creature, who tells you were to get
  // your silver forged into a key
  // while game_progress != have forged key, maybe?
  delay(1500);
  string areatitle = "\n\n--- Next Stage -------------------------\n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::pink), areatitle);
   cout << "Wandering from THE MINES you're mildly confused as to the layout of the system inside the corridor.\nYou're hopeful you'll come accross where you need to go but after a while you're not too sure.\nYou've seen many different kinds of TROLLS since you enetered but they are all ignoring your\nexistance for the most part.\n\n";
  delay(1500);
  cout << "Further into the gave you start seeing different kinds of creatures, one in which walks straight\nup to you. It's frame is much larger than you however it's even got a curve in it's back as it's \nhunched over.It's got huge hands that resemble claws and it's feet resemble paws. It's legs up to the knee \nand it's arms from wrist to elbow have thick fur. It's face has a close resemblance to a lycanathrope, \ngathered eyebrows that are bushy, glowy yellow eyes, ashen skin. It's mouth would be filled with razor \nsharp teeth you'd assume judging by the upper caine teeth being exposed over the lower lip. \n\n";
  delay(1500);
  cout<<"This creature would for sure give you trouble should it decide to attack due to it's excessive muscular frame.\nYou can tell it's male, due to the dark red cloth wrapped only around it's waist, held together with \nwhat appears to be a human skull.\n\n";
  delay(1500);
  string beastMan = "BEASTMAN: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::brown), beastMan);
  cout << "Human. Try to escape?\n";
  cout << "You take the SILVER ORE to BLACKSMITH to make SIVLER KEY.\n\n";
  cout << "It's voice would be gruff and thankfully it's English would be broken but still audible.\n\n";
  delay(1500);
  print ("YOU: \n");
  print (" > Where is the BLACKSMITH? \n\n");
  delay(1500);
   string manBeast = "BEASTMAN: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::brown), manBeast);
  print("Follow corridor on left, opposite to mines.\n\n");
  delay(1500);
  print ("YOU: \n");
  print (" > Thanks.\n\n");
  cout << "Your encounter with the BEASTMAN would be thankfully quite short. \nHe walks away from you and back down the corridor in which he came from.\n\n";
  delay(2000);
  print ("Heading OPPOSITE to the mines, where the corridor is you follow it.\n");
  print ("Popping out into a clearing within the cave there is a hut with steam surrounding it.\n");

  // ------- THE FORGE - MEETING THE BLACKSMITH ------------------------------//
   // TODO: Send the player to the forge, where they must tell the blacksmith a
  // funny name. the blacksmith is very particular though: she only wants a name made up   // of three words, and it has to be exactly 20 characters long, including spaces.
  // "Jasmine Bee Flettles" would work, but "Bonno Bingoparaloop" wouldn't, nor would
  // "Minh Gyu Lee" because it's too short.
  delay(2500);
  string blackTitle = "\n\n--- THE FORGE ------------------------- \n\n"; 
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackTitle);
cout << "As if a hut in the middle of a clearing within a cave-like area wasn't weird enough, the building itself \ncould probably do with help.";
  delay(500);
  cout <<"It's a split level building with the bottom having the most to look at. \n\nUnder the cover of two walls and rickety roof with broken or missing shingles would be where the fire place \nwould be in the back corner closest to the building on the upper level. In the centree of the space, \njust outside of the roof would be the iron block. There would be wooden tables along the side where the \nsplit-level has the wall of the building. Loose weaponry and sheilds would cover the area of the lower level.\n\n";
  delay(500);
    cout << "The upper level, though only upper level by stone steps would be the living quaters presumably. \nA window overlooks the working area and a door is present on the upper level. Like the roof of the \nworking area, there are missing and broken shingles. It's a quaint living area if it weren't for the fact \nthat it's in the middle of nowhere.\n";
  delay(500);
  cout << "The closer you get to the working area the hotter it would be, the smell of smoke and soot would coat \nyour lungs but nevertheless you need help from the BLACKSMITH who is working away in the working area.\n\n";
  delay(500);
    cout << "The BLACKSMITH is relatively human in appearance. Though you'd presume he'd be a GIANT judging by his \nlarge frame. His attire would be black, his sleeves pushed up to his elbows. Evident scaring from \nburns would be evident as you watch him work. Mallet in hand, sparks would fly as the BLACKSMITH \nbashes away at his current work.\n\n";
  delay(1000);
  string blackSmith = "BLACKSMITH: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSmith);
  print("Human. What brings you here?\n\n");
  print ("YOU: \n");

  string answer = forgeKey("KEY", "FUN");

   if (answer == "FUN" || answer == "fun"){
       cout << "\n Why are you here then? Go back.\n\n";
      return mineForSilver();
        }
        else if (answer == "KEY" || answer == "key"){
          string blackSmith = "\nBLACKSMITH: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSmith);
          cout << "Do you have SILVER ORE?\n\n";
          string choice = continuePlaying("YES", "NO");
        if (choice == "YES" || choice == "yes") {
              delay(500);
          string blackSmith = "\nBLACKSMITH: ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSmith);
              cout << "\nLet's begin.\n\n";
          }
          else if (choice=="NO" || choice=="no"){
            cout << "\n Why are you here then? Go back.\n\n";
            return 0;
          }
          }

  blacksmithName();

  // --------------------------------------//
  // Game Progress - Have Forged Key
  while (game_progress != Progress::HAVE_SILVER_ORE){
    if (blacksmithName()){
        return true;
     Progress game_progress = Progress::HAVE_FORGED_KEY;
      }
    }
  
  delay(1000); 
  string blackSMith = "\nBLACKSMITH: ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSMith);
  print ("\nWell done Human. You Passed my challenge.\n");
  print ("\nThe Blacksmith would take the SILVER ORE from you to take back to their workshop. \n Taking a seat where one could be found you sit listening to the clanging of metal, \n feeling the heat from the fire and enjoying a break in what seems a very long time.\n");
  delay(1000);
  print ("\nIn only a few hours the Blacksmith would return to you with a shiny SILVER KEY in hand \n along with a rolled up piece of parchment.\n");
  string blackSMIth = "\nBLACKSMITH: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSMIth);
  print("Thanks for waiting Human. Here is your finished silver key and an old map. \n I have a feeling the Ancient Door will want something without giving directions.\n\n");
  delay(1000);
    print (" > Recieve SILVER KEY from Blacksmith\n");
    print (" > Recieve MAP from Blacksmith as well\n");
  delay(500);
  toContinue();


  // ----------- ANCIENT STONE DOOR ----------------------------------------//
  // TODO: leaving the forge, you see an enormous, ANCIENT STONE DOOR. A sculpted face in
  // the surface speaks and tells you he prefers keys with rubys in. He sends you to..  
  delay(1000); 
  string ancientDoor = "\n\n--- ANCIENT STONE DOOR ------------------------- \n\n"; 
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_yellow), ancientDoor);
  delay(500);
  print("Leaving the forge with your new silver key. You'd be heading further down the stone corridor towards the exit.\n\n");
   delay(500);
  print("To your amazement you see an enormous, stone door that has aged significantly.\n");
   delay(500);
  print("To your shock there is a sulpted face on the surface.\n\n");
 delay(1000);
  string smlAncientDoor = "ANCIENT STONE DOOR: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_yellow), smlAncientDoor);
cout <<"Welcome human. Have you mined the ORE OF SILVER and refined it into a SILVER KEY? \n\n";
  
   string choice = continuePlaying("YES", "NO");
  
if (choice == "YES" || choice == "yes") {
          delay(500);
        string minorAncientDoor  = "\nANCIENT STONE DOOR: \n";
        fmt::print(fmt::emphasis::bold | fg(fmt::color::light_yellow), minorAncientDoor);
        cout <<"That's too bad human. I prefer keys with RUBIES in them\n";
  }
  else if (choice == "NO" || choice == "no"){
     delay(500);
    cout << "\n Why are you here then? Go back.\n\n";
    return 0;
    }

  delay(1000);
  cout << "\nYOU: \n";
  cout << " > Where would I find RUBIES in this place?\n\n";
delay(1000);
        string smallAncientDoor  = "ANCIENT STONE DOOR: \n";
        fmt::print(fmt::emphasis::bold | fg(fmt::color::light_yellow), smallAncientDoor);
  cout << "RUBIES are won in THE FAIRIES GAMBIT. Go play with the faires for the RUBIES. \n\n ";
delay(500);
  cout << "YOU: \n";
  cout << " > Fine.\n";


  // ------------- TRANSITION PHASE ------------------------------------------//
 delay(1000);
  string areaSubtitle = "\n--- Next Stage -------------------------\n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::pink), areaSubtitle);
  print("Leaving the stone door with the face sculpted on it, dejected that your exit has been delayed \nyou check your MAP.\n\n");
  delay(1000);
  print("You set out to find THE FAIRIES GAMBIT. An area for faries, peculuar indeed. \nFirst Trolls, Beastmen, a Blacksmith, a talking door now faries. What even is this place?\n\n");
  delay(500);
  print("Pondering over what has happened, you finally reach the entrance of THE FAIRIES GAMBIT.\n\n");
  delay(1000);
  print("Unlike the rest of the corridor you've travelled, the entrance to THE FAIRIES GAMBIT is with an iron gate \n fit with many different gems and stones throughout the curves and spirals.\n\n");
  delay(500);
  print("With determination you push open the gate, it CREAKING loud and clear, only to be met with the \nmost lush garden. It becomes immediately obvious that fairies do indeed live here.\n");
  delay(1000);
  toContinue();

  // ------------ THE FAIRY'S GAMBIT --------------------------------------------------//
    // TODO: The Fairy's Gambit. Here you can engage in a challenge to get a red gem.
  // If it turns out to be a ruby (look at handy_functions) and not some other red gem, 
  // you can set it in the key. If not, you must stay and try again. (The challenge is up to 
  // you - it could be a game with a random draw like the silver mining, but something 
  // different would be worth more marks!)
   delay(1000);
   string fairyTitle = "\n\n--- THE FAIRY'S GAMBIT ------------------------- \n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), fairyTitle);
  delay(1000);
  cout << "Welcomed with the sweet scent of flowers, nature and the sort - you are confused as to how it is maintained.\n";
  cout << "With no time to ponder you're met with a gust of wind to the face, causing to you cover your face.\n\n";
   delay(500);
  string bigFairy  = "FAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), bigFairy);
  cout << "What brings you here, human?\n\n";
  cout << "A determined, sharp yet tinkling sort of voice demands quite close to your face. \nRemoving your arms you are met with the etherial figure of what you'd presume is a Fairy. \nIt's stature is quite small, 15 centremeters at most.\n\n";
   delay(500);
cout << "YOU: \n";
  cout << "I was told by THE ANCIENT DOOR to obtain a Ruby by 'playing with the fairies'.\n\n";
   delay(500);
  string bigFAiry  = "FAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), bigFAiry);
  cout << "Useless Door. We can't play yet, I am much too busy.\n\n";
 delay(500);
  cout << "Do you wish to ask FAIRY why they cannot play?\n";
  string choice2 = continuePlaying2("YES", "NO");
  if (choice2 == "NO"||choice2 == "no") {
    delay(500);
    string gameOver = "\n--- GAME OVER -------------------------";
  fmt::print(fmt::emphasis::bold | bg(fmt::color::red), gameOver);
    cout << "\nYou leave the Gambit. Unsuccessful.\n";
    cout << "Although leaving the FAIRY'S GAMBIT alive, you soon met your demise in the corridor filled with all sorts of creatures.\n\n";
      string playAgain = "Do you Wish to Play Again?\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::red), playAgain);
  string choice = continuePlaying("YES", "NO");
  if (choice == "NO"||choice == "no") {
    cout << "Thanks for Playing!";
    return 0;
    }
  else if (choice=="YES"||choice=="yes"){
    cout << "Please Re-Run program.";
    return 0;
  }
    return 0;
    }
    
  else if (choice2=="YES"||choice2=="yes"){
    delay(500);
    cout << "\nYOU: \n";
    cout << "Why can't you play?\n\n";
    delay(1000);
    string bigFairy  = "FAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), bigFairy);
  cout << "A child, fairy child to be exact, has gone missing. They didn't check in at tea time.\n\n";
  cout << "You watch as the FAIRY's eyes begin to light up with an idea.\nThey look to you, and in that moment you realise you've dug yourself a hole that you might not return from.\n\n";
    delay(1000);
  string bigFAiry  = "FAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), bigFAiry);
  cout << "Can you go look for the FAIRY CHILD?\nI'll put it down as Part 1 of our game.\n\n";
    delay (500);
  cout << "The gleeful look on the FAIRY's face makes you shudder, but it's either accept or not right?\n\n";
  
  string choice = continuePlaying("YES", "NO");
  if (choice == "NO"||choice == "no") {
   fairyGAMEOVER();
    }
    }

    delay(500);
  string bigFAIry  = "\nFAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), bigFAIry);
  cout << "The FAIRY CHILD was last seen in either the TULIP-PATCH or the VEGETABLE-GARDEN. \n Good Luck.\n";
  
toContinue();
  
    delay(1000);
   string fairyBar = "\n\n--------------------------------------------------\n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), fairyBar);
  cout << "Having accepted the task from the FAIRY. You begin to ponder where to go first\n";
  string fairyAnswer = fairyChoice("TULIP-PATCH", "VEGETABLE-GARDEN","NO-THANKS");
      if (fairyAnswer== "VEGETABLE-GARDEN" || fairyAnswer == "vegetable-garden"|| fairyAnswer== "VEGETABLE" || fairyAnswer == "vegetable"){
         
        return 0;
        }
       else if (fairyAnswer == "TULIP-PATCH" || fairyAnswer == "tulip-patch"|| fairyAnswer == "TULIP" || fairyAnswer == "tulip"){
         delay(1000);
          cout << "\nFrom the entrance, you follow the cobblestone path towards the gardens. \nIt's not hard to find where they are given the brightness of the tulips on the ground .\nEntering the TULIP-PATCH you keep your eyes pealed throughout the journey to make sure you \neither find the FAIRY CHILD or a CLUE.\n\n";
         delay(1000);
         cout << "Digging through some tulips you finally stumble over some tiny ART SUPPLIES. \nThinking this is a win you look at what art supplies are there and what are missing. \nYou notice INK is missing, as are the POTS that they'd be in.\n\n";
         delay(500);
         cout << "Recalling the FAIRY mentioning that the FAIRY CHILD was also last seen in the VEGETABLE GARDEN, \ndo you take the chance and go have a look?\n\n";
delay(500);
             string fairyAnsweR = fairyChoicE ("VEGETABLE-GARDEN","NO-THANKS");
               if (fairyAnsweR== "VEGETABLE-GARDEN" || fairyAnsweR == "vegetable-garden"|| fairyAnsweR== "VEGETABLE" || fairyAnsweR == "vegetable"){  
                 delay(500);
                 cout << "\nOpposite to the bright tulip patch futher down the cobblestone path you find yourself in the VEGETABLE-GARDEN. \nYou keep your eyes pealed throughout the journey to make sure you either find the FAIRY CHILD or a CLUE.\n";
                 delay(500);
                    cout << "Near where the RASPBERRY bushes are you find some tiny little POTS on the ground with a few CLEAR JARS.\nAssuming that the CLEAR JARS are for water, and how there are not enough tiny JARS per ink POT, \nyou believe the FAIRY CHILD has gone to the NEARBY POND.\n\n";
           }
                  else if (fairyAnsweR == "NO-THANKS" || fairyAnsweR == "no-thanks"|| fairyAnsweR == "no" || fairyAnsweR == "NO"){
                   fairyGAMEOVER();
        }
         }
        else if (fairyAnswer == "NO-THANKS" || fairyAnswer == "no-thanks" ||fairyAnswer == "NO" || fairyAnswer == "no"){
         fairyGAMEOVER();
        }
delay(500);
  cout << "With the knowledge that there is evidence in both locations pinpointing the end location being the pond. \nDo you go to the pond?\n\n"; 
  string keepGoing = toThePond("YES", "NO");
  if (keepGoing=="YES"|| keepGoing=="yes"){
    delay(500);
    cout << "\nWaking further down the cobbstone path past the TULIP-PATCH towards what you'd assume is the pond judging \nby how large the body of water is. You begin searching.\n\n";

    delay(2000);
    cout << "You've found the lost FAIRY CHILD.\n\n";
  }
  else if (keepGoing=="NO"|| keepGoing=="no"){
    fairyGAMEOVER();
  }
  delay(2000);
  cout << "The FAIRY CHILD was found floating aimlessly on a large lily pad.\nThe pond was so vast that spotting the fairy was time consuming.\nThe FAIRY CHILD on appearance looks to be damp, and her wings look too wet. \nThat must have been why she was unable to return.\n\n";
delay (1000);
  cout << "Approaching the FAIRY CHILD you kneel down as to not appear too big before speaking.\n\n";
delay (1000);
  cout << "YOU: \n";
  cout << " > Hello. Do you wish for aid to return to the FAIRY?\n\n";

  cout << "The young fairy looks up at you with a sad expression before nodding. \nYou wait a moment to obtain verbal confirmation.\n\n";
delay (1500);
  string childFairy  = "FAIRY CHILD: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), childFairy);
  cout << "Yes please.\n\n";
delay(1000);
  cout << "Holding a hand out to the lilypad as it float closer to you, the FAIRY CHILD would climb onto your hand.\nTaking this chance to stand up you ensure that the FAIRY CHILD is as comfortable as they can be as you \nhead backupwards the cobblestone path.\n\n";
delay (2500);
  string fairyBar2 = "--------------------------------------------------\n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), fairyBar2);

  cout << "Back near the entrance, the FAIRY flys to greet you.\n\n";
delay (1000);
  string bigFAIRy  = "FAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), bigFAIRy);
  cout << "You found her! I'm very grateful to you, Human.\n\n";
  delay(500);
  cout << "The FAIRY helps the FAIRY CHILD from your hand, aiding in the drying of her wings. \nYou watch between the two hopeful that they are willing to play with you so that you can obtain your ruby.\n\n";
delay(1000);
  string biGFairy  = "FAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), biGFairy);
  cout << "Oh right. Part 2 of our game.\n\n";
  delay(500);
  cout << "The FAIRY remembers as they look at you and back at the FAIRY CHILD, they grin.\n\n";
  delay(1000);
  //--- GUESS THE FAVOURITE FLOWER ----------//
  string biGFAiry  = "FAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), biGFAiry);
  cout << "Guess the FAIRY CHILD's favoruite flower.\n";
  delay(500);
  cout << "FAIRY CHILD's favoruite flower is in this garden. You have 3 guesses.\n\n";
   cout << "The Choices include:\n";
    cout << "[1] PETUNIA | [2] TULIP | [3] COSMOS | [4] SNAPDRAGON\n";
  guessFlower();
  delay(1000);
  string biGFaIRy  = "FAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), biGFaIRy);
  cout << "I commend you on your success. Last challenge on the list is....\n";
  cout << "Give me your name.\n\n";
delay(500);
  cout << "Give the FAIRY your name?\n";
    string name = giveName("YES", "NO");
  if (name == "NO"||name == "no") {
    delay(1000);
    cout << "\nYou give the FAIRY a false name.\nYour knowledge of mythics have paid off. You never give a fairy your real name. \nYour name holds power, and by giving it to the FAIRY you're giving them power over you.\n\n";
    }
  //return HAVE_RUBY;
   
delay (1000);
  cout << "The FAIRY flys off for a moment leaving the FAIRY CHILD to watch you. \nThey'd return with a huge shiny red crystal.\n\n";
  string biGFAIry  = "FAIRY: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_pink), biGFAIry);
  cout << "Here. As per our agreement.\n\n";
  cout << "The FAIRY hands you the crystal, at closer inspection you've recieved a RUBY. \n\n";

   cout << "How do you bid the Fairies farewell? \n\n";
  string response = farewellFairies("[1]", "[2]");
  if (response=="2"){
    cout << "\nYOU: \n";
    cout << " > You are much too kind.\n\n";
  }
delay(1500);
  cout << "The FAIRY and the FAIRY CHILD both give you a nod before turning away. \nUsing this chance to leave THE FAIRY'S GAMBIT alive, you make your way back to the IRON GATE.\nIt makes sense to you now that this gate is what is stopping the faries from wrecking havoc. \nGood thing too.\n";
 
  // --------------------------------------//
toContinue();
 // --------------------------------------//
delay(1000);
  cout << "\n\nYou decide to head back to THE FORGE to get BLACKSMITH to put the RUBY into the key.\n Using the map that they had given you back when they forged the key, you bypass THE ANCIENT DOOR.\nBy this time you're exhausted and hope that you'll be able to leave this place soon.";

  delay(1500);
  string blacksmithTitle = "\n\n--- THE FORGE ------------------------- \n\n"; 
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blacksmithTitle);
delay(1000);
  cout << "Entering the forge once again, you're met with the scalding hot air from the fire, the air that's coated \nwith soot. The moment you enter you hear the groaning of the BLACKSMITH. BLACKSMITH is not happy with you \nback in their space.\n\n";
  delay(1000);
  string blackSmiTH = "BLACKSMITH: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSmiTH);
  cout << "Human. What are you doing back here?\n\n";
delay(500);
  cout << "YOU: \n";
  cout << " > The Door sent me to FAIRY'S GAMBIT for a ruby to have on the key.\n\n";
  cout << "You explain what THE ANCIENT STONE DOOR had done to send you to the faries, the Blacksmith groans.\n\n";
  delay(1000);
  string blackSmiTh = "BLACKSMITH: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSmiTh);
  cout << "That darn door, causing mischief.\nAlright, so you're wantn' the RUBY on the KEY?\n\n";
delay(500);
  cout << "YOU: \n";
  cout << " > Yes.\n\n";
  // BLACKSMITH ROCK PAPER SCISSORS //

  int games_played = 0;
  srand(time(NULL)); // random

  int human_choice;
  weapon blacksmith_weapon;
  weapon human_weapon;

  string blackSmITH = "BLACKSMITH: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSmITH);
  cout << "Let's play a single game of Rock Paper Scissors, Human.\nIt don't matter who wins, this is just for fun.";
  cout << "You agree and you both line up to play.\n\n";

  cout << "Rock.\n";
   cout << "Paper.\n";
  cout << "Scissors.\n\n";
  
  while (games_played < maxGames) {
    cout << "What do you choose?\n(1) ROCK | (2) PAPER | (3) SCISSORS?\n";
    cout << " > ";
    cin >> human_choice;

    if (human_choice== 1) human_weapon = ROCK;
    else if (human_choice== 2) human_weapon = PAPER;
    else if (human_choice== 3) human_weapon = SCISSORS;
    else human_weapon = ROCK;

    int x = rand()%3;
    if (x == 0) blacksmith_weapon = ROCK;
    else if (x == 0) blacksmith_weapon = PAPER;
    else if (x == 0) blacksmith_weapon = SCISSORS;

    cout << "\nBLACKSMITH chooses " << show(blacksmith_weapon) << endl;
    cout << displayWinner(human_weapon, blacksmith_weapon) << endl; 
    games_played++;

    
    delay(1500);
    string blackSmItH = "\nBLACKSMITH: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSmItH);
    cout << "Good Game Human.\n";
  }
delay(500);
   cout << "Alright. Let me go fix this key up.\n\n";
delay(1000);
  cout << "The BLACKSMITH takes both the FORGED KEY and the RUBY from you after your match.\nYou're glad that this game didn't involve heaps of thinking or if it ended badly.\n\n";
  cout << "The BLACKSMITH comes back with your key not too long after, which is great news. \nIt's time to get out of here!\n\n";

  string blackSMITH = "BLACKSMITH: \n ";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::orange), blackSMITH);
  cout << "Didn't take me too long this time, Human. Hopefully that darn door lets you out this time.\n\n";
delay(1000);
  cout << "YOU: \n";
  cout << " > Thanks a bunch BLACKSMITH.\n\n";
delay(500);
  cout << "> Recieved RUBY ORDAINED SILVER KEY\n\n";
delay(500);
  cout <<"BLACKSMITH waves you off as they turn to go back to what they were doing prior to your second visit. You take this as a goodbye and leave the FORGE. Strolling  back down the corridor towards THE ANCIENT DOOR.";

  delay(2500);
string theAncientDoor = "\n\n--- ANCIENT STONE DOOR ------------------------- \n\n"; 
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_yellow), theAncientDoor);
  print("Returning back to the huge door with the face sculpted on it, with the ruby now set in the key. \n You're hopeful that you can leave.\n\n");
  delay(1000);
  string theAncientDOor  = "ANCIENT STONE DOOR: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_yellow), theAncientDOor);
  cout << "You're back human.\n\n";
  delay(1000);
  cout << "YOU: \n";
  cout << " > I am, with the key in hand.\n\n";
    delay(500);;
  print("Lifting the key to show to the door, you're amused when the ANCIENT DOOR all but sighs in response.\n\n");
  delay(1000);
   string theANcientDoor  = "ANCIENT STONE DOOR: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_yellow), theANcientDoor);
  cout << "Great Job \n\n";
  delay(1000);
  print("Despite his words, the ANCIENT DOOR is definitly not meaning it.\n\n");
  print ("The ANCIENT DOOR opens himself up, without the key that is still in your hand.\n As he opens the forrest that you were strolling around before all this is before you.\n\n");
  delay(1000);
  cout << "YOU: \n";
  cout << " > What about the key?\n\n";
  print("You ask baffled by the whole delimea that you had to go through to obtain this key.\n\n");
  delay(1000);
  string theANCientDoor  = "ANCIENT STONE DOOR: \n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::light_yellow), theANCientDoor);
  cout << "Keep it as a souviner.\n\n";
  print("The ANCIENT DOOR all but grins with malice with your bafflement.\n\n");

  delay(1500);
   print("Regardless of the ANCIENT DOOR's response you don't hesitate to leave the hell that you were just thrown \ninto for no reason.\n");
  delay(3000);
string line = "\n==============================================\n\n";
 string title = "\n\n====== T H E - E N D ======\n\n";
  fmt::print(fmt::emphasis::bold | fg(fmt::color::pale_turquoise), line);
  fmt::print(fmt::emphasis::bold | fg(fmt::color::pale_turquoise), title);
  print("After successfully passing all the trails, you finally exited the endless corridor.\n\n");
  print(" > You've obtained a RUBY ORDAINED SILVER KEY.\n\n");
  print("Thanks for Playing!");

    return 0;
  }
