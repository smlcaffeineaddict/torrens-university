#ifndef __CARD__
#define __CARD__
#include <string>
using namespace std;

// A basic example of a collectible or record card with 
// some generic properties. "name" and "weight" could be
// applied to people, monsters, cars, famous gold nuggets, 
// magic swords, birds (where name could mean name of 
// species/type) etc.
#include <string>

using namespace std;

class gameCard
{
private:

public:
    string id;
    string name;  
    string species;
    string desc;

    float mp = 0.0f;
    float hp = 0.0f;

// Creature Specs
    float str = 0.0f; // strength
    float dex = 0.0f; // dexterity
    float com = 0.0f; // combat
    float intel = 0.0f;  // intelligence
    float wis = 0.0f; //wisdom
    float sta = 0.0f; // stamina

// Rarity
    string rar; //rarity

// Overall
 float att; // Attack Capabilities
 float def; // Defense Capabilities

void getInfo(){
  cout << "Name: "; cin >> name;
  cout << "Species: "; cin >> species;
  cout << "Description: "; cin >> desc;
  cout << "Magic Points: "; cin >> mp;
  cout << "Health Points: "; cin >> hp;

  cout << "Strength: "; cin >> str;
  cout << "Dexerity: "; cin >> dex;
  cout << "Combat: "; cin >> com;
  cout << "Intelligence: "; cin >> intel;
  cout << "Wisdom: "; cin >> wis;
  cout << "Stamina: "; cin >> sta;
}

void showCard(){
  cout << name;
  cout << "Species: " << species;
  cout << "Description: ";
  cout << "\t\tMP: " << mp << "\t| \t HP: " << hp << "\n\n";
  cout << "\tSTR : " << str << "\t| \tDEX : " << dex << "\t| \tCOM : " << com << "\n";
  cout << "\tINT : " << intel << "\t| \tWIS : " << wis << "\t| \tSTA : " << sta << "\n";
  cout << "\n\tATTACK: " << att << "\t| \tDEFENSE : " <<  def << "\n";
  cout << "\n\tRARITY: " << rar << "\n";

  att = str + dex + com + sta + intel; // Attack
  def = str + com + intel + sta + wis; // Defense
  
    if ((att+def)==1000) {
    rar = "Mythic";
  }
    else if ((att+def)>=800) {
    rar = "Legendary";
  }
    else if ((att+def)>=700) {
    rar = "Epic";
  }
    else if ((att+def)>=600) {
    rar = "Super Rare";
  }
    else if ((att+def)>=500) {
    rar = "Rare";
  }
    else if ((att+def)<500) {
    rar = "Common";
  }
  
}

};

struct EditCreature {
    int id;
    string name;  
    string species;
    string description;

    int mp;
    int hp;

    int str;
    int dex;
    int com;
    //--
    int intel;
    int wis;
    int sta;
    // --
    int att;
    int def;

    string rar;

  friend ofstream& operator<<(ofstream &os, const EditCreature &src);
  friend ifstream& operator>>(ifstream &is, EditCreature &dst);
};
ofstream& operator <<(ofstream &os, const EditCreature &src) {
  os << src.id << endl << src.name << endl << src.species << endl << src.description << endl << src.mp << '\t' << src.hp<< endl << src.str << '\t' << src.dex << '\t' << src.com << endl << src.intel << '\t' << src.wis << '\t' << src.sta << endl << src.att << '\t' << src.def << endl << src.rar << endl;
  return os;
}
ifstream& operator >>(ifstream &is, EditCreature &dst) {
  // may need to have more code to ignore whitespace, I'm not sure
 if (is.good ()) {
    is >> dst.id;
  }
  if (is.good ()) {
    is >> dst.name;
  }
  if (is.good ()) {
    is >> dst.species;
  }
  if (is.good ()) {
    is >> dst.description;
  }
      if (is.good ()) {
    is >> dst.mp;
  }
      if (is.good ()) {
    is >> dst.hp;
  }
  if (is.good ()) {
    is >> dst.str;
  }
  if (is.good ()) {
    is >> dst.dex;
  }
  if (is.good ()) {
    is >> dst.com;
  }
  if (is.good ()) {
    is >> dst.intel;
  }
      if (is.good ()) {
    is >> dst.wis;
  }
      if (is.good ()) {
    is >> dst.sta;
  }
    if (is.good ()) {
    is >> dst.att;
  }
      if (is.good ()) {
    is >> dst.def;
  }
      if (is.good ()) {
    is >> dst.rar;
  }
  return is;
}

struct EditCreatureDupl {
    int id;
    string name;  
    string species;
    string description;

    int mp;
    int hp;

    int str;
    int dex;
    int com;
    //--
    int intel;
    int wis;
    int sta;
    // --
    int att;
    int def;

    string rar;

  friend ofstream& operator<<(ofstream &os, const EditCreatureDupl &src);
  friend ifstream& operator>>(ifstream &is, EditCreatureDupl &dst);
};
ofstream& operator <<(ofstream &os, const EditCreatureDupl &src) {
  os << '\t' << '[' << src.id << ']' << '\t' << src.name << '\t' << '\t' << src.species << '\t' << '\t' << src.rar << '\t' << '\t' << src.att << '\t' << src.def << endl;
  return os;
}
ifstream& operator >>(ifstream &is, EditCreatureDupl &dst) {
  // may need to have more code to ignore whitespace, I'm not sure
if (is.good ()) {
    is >> dst.id;
  }
  if (is.good ()) {
    is >> dst.name;
  }
  if (is.good ()) {
    is >> dst.species;
  }
  if (is.good ()) {
    is >> dst.description;
  }
      if (is.good ()) {
    is >> dst.mp;
  }
      if (is.good ()) {
    is >> dst.hp;
  }
  if (is.good ()) {
    is >> dst.str;
  }
  if (is.good ()) {
    is >> dst.dex;
  }
  if (is.good ()) {
    is >> dst.com;
  }
  if (is.good ()) {
    is >> dst.intel;
  }
      if (is.good ()) {
    is >> dst.wis;
  }
      if (is.good ()) {
    is >> dst.sta;
  }
    if (is.good ()) {
    is >> dst.att;
  }
      if (is.good ()) {
    is >> dst.def;
  }
      if (is.good ()) {
    is >> dst.rar;
  }
  return is;
}

struct CreatureCard {
    int id;
    string name;  
    string species;
    string description;

    int mp;
    int hp;

    int str;
    int dex;
    int com;
    //--
    int intel;
    int wis;
    int sta;
    // --
    int att;
    int def;

    string rar;

  friend ofstream& operator<<(ofstream &os, const CreatureCard &src);
  friend ifstream& operator>>(ifstream &is, CreatureCard &dst);
};
ofstream& operator <<(ofstream &os, const CreatureCard &src) {
  os << src.id << endl << src.name << endl << src.species << endl << src.description << endl << src.mp << '\t' << src.hp<< endl << src.str << '\t' << src.dex << '\t' << src.com << endl << src.intel << '\t' << src.wis << '\t' << src.sta << endl << src.att << '\t' << src.def << endl << src.rar << endl;
  return os;
}
ifstream& operator >>(ifstream &is, CreatureCard &dst) {
  // may need to have more code to ignore whitespace, I'm not sure
 if (is.good ()) {
    is >> dst.id;
  }
  if (is.good ()) {
    is >> dst.name;
  }
  if (is.good ()) {
    is >> dst.species;
  }
  if (is.good ()) {
    is >> dst.description;
  }
      if (is.good ()) {
    is >> dst.mp;
  }
      if (is.good ()) {
    is >> dst.hp;
  }
  if (is.good ()) {
    is >> dst.str;
  }
  if (is.good ()) {
    is >> dst.dex;
  }
  if (is.good ()) {
    is >> dst.com;
  }
  if (is.good ()) {
    is >> dst.intel;
  }
      if (is.good ()) {
    is >> dst.wis;
  }
      if (is.good ()) {
    is >> dst.sta;
  }
    if (is.good ()) {
    is >> dst.att;
  }
      if (is.good ()) {
    is >> dst.def;
  }
      if (is.good ()) {
    is >> dst.rar;
  }
  return is;
}

struct CreatureCardDupl {
    int id;
    string name;  
    string species;
    string description;

    int mp;
    int hp;

    int str;
    int dex;
    int com;
    //--
    int intel;
    int wis;
    int sta;
    // --
    int att;
    int def;

    string rar;

  friend ofstream& operator<<(ofstream &os, const CreatureCardDupl &src);
  friend ifstream& operator>>(ifstream &is, CreatureCardDupl &dst);
};
ofstream& operator <<(ofstream &os, const CreatureCardDupl &src) {
   os << '\t' << '[' << src.id << ']' << '\t' << src.name << '\t' << '\t' << src.species << '\t' << '\t' << src.rar << '\t' << '\t' << src.att << '\t' << src.def << endl;
  return os;
}
ifstream& operator >>(ifstream &is, CreatureCardDupl &dst) {
  // may need to have more code to ignore whitespace, I'm not sure
if (is.good ()) {
    is >> dst.id;
  }
  if (is.good ()) {
    is >> dst.name;
  }
  if (is.good ()) {
    is >> dst.species;
  }
  if (is.good ()) {
    is >> dst.description;
  }
      if (is.good ()) {
    is >> dst.mp;
  }
      if (is.good ()) {
    is >> dst.hp;
  }
  if (is.good ()) {
    is >> dst.str;
  }
  if (is.good ()) {
    is >> dst.dex;
  }
  if (is.good ()) {
    is >> dst.com;
  }
  if (is.good ()) {
    is >> dst.intel;
  }
      if (is.good ()) {
    is >> dst.wis;
  }
      if (is.good ()) {
    is >> dst.sta;
  }
    if (is.good ()) {
    is >> dst.att;
  }
      if (is.good ()) {
    is >> dst.def;
  }
      if (is.good ()) {
    is >> dst.rar;
  }
  return is;
}
#endif // __CARD__