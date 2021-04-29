#include <iostream>
#include <thread>
#include <random>
#include <array>
#include "pokemonInfo.h"
using namespace std;

string place = "home";
void delay(int milli)
{
  using namespace std::chrono;
  this_thread::sleep_for(milliseconds(milli));
}
int to_int(string value)
{
	return stoi(value);
}
string supportedPokemon[] = {"Jigglypuff", "Gyarados", "Magikarp", "Pikachu", "Squirtle", "Litleo", "Charmander", "Charizard", "Blastoise", "Warturtle", "Latias", "Latios", "Ditto", "Mewtwo", "Mew", "Bulbasaur", "Venusaur", "Eevee", "Flareon", "Raichu", "Rowlet", "Vaporeon", "Pichu", "Espeon"};
//string rarity[][9] = {{"Litleo", "Rowlet", "Bulbasaur", "Pichu", "Magikarp", "Squirtle", "Charmander","Eevee"}, {"Warturtle", "Jigglypuff", "Ditto", "Flareon", "Vaporeon", "Pikachu", "Ivysaur", "Gyarados"}, {"Mew", "Mewtwo", "Charizard", "Raichu", "Venusaur", "Blastoise", "Latios", "Latias", "Espeon"}};
//1 = name, 2 = type, 3 = amount
string testMoves[][3] = {{"Pound", "Normal", "15"}, {"Tackle", "Normal", "20"}, {"Agility", "Psychic", "10"}, {"360 NoScope", "Fairy", "5"}, {"Bitch Slap", "Dark", "10"}};
//predefine functions
void cmdCheck();
void storage();
void trainer_battle();
void wild_battle();
void deposit();
void withdraw();
void walking();
//end
class Pokemon
{ 
  private:
    string type[2];
    string name;
    string weakness[3];
    string strength[3];
    int health;
  public:
   string moves[4];
    //easy way to make pokemon for storage
  Pokemon(string dname, string dtype1, string dtype2, int dhealth)
  {
    name = dname;
    health = dhealth;
    type[0] = dtype1;
    type[1] = dtype2;
  }
};
void trainer_battle()
{
  place = "battle";
  //23, [0] = [1]
  string trainerNames[24] = {"Felisha", "Tom", "Jerry", "Bob", "Tim", "Bill", "Emily", "Kevin", "Tamara", "Sophia", "Jon", "Erin", "Aaron", "Ava", "Ella", "James", "Jessie", "Mike", "Emma", "Isabelle", "Isabella", "Sabrina", "Joe", "Zoe"};
  //11, [0] = [1]
  string trainerTitles[11] = {"Trainer ", "Brother ", "Sister ", "Parent ", "Traveler ", "Leader ", "Child ", "Youngster ", "Wannabe ", "Wanderer ", "Jogger "};
  string trainer = trainerTitles[random(0, 10)] + trainerNames[random(0, 23)];
  cout << trainer << " has challenged you to a battle!" << endl;
  cout << "=====================================================";
}
void wild_battle()
{
  place = "battle";

}
void walking()
{
  place = "battle_searching";
  cout << "You start your adventure.\n";
  //30 locations, [0] = [1]
  string locations[] = {"Lumoise City", "Saffron City", "Lavender Town", "Celestic Town", "Littleroot Town", "Pallet Town", "Anville Town", "Ambrette Town", "Geosenge Town", "Mahogany Town", "Dewford Town", "Oldale Town", "Snowbelle City", "Casteilia City", "Fortree City", "Santalune City", "Paniola Town", "Slateport City", "Petalburg City", "Route 5", "Route 6", "Route 7", "Route 3", "Route 10", "Route 10", "Route 1", "Route 2", "Route 4", "Route 8", "Route 9"};
  string verbs[6] = {"Running ", "Biking ", "Jogging ", "Walking ", "Skating ", "Racing "};
  string whereLoca[3] = {"through ", "into ", "out of "};
  int Walked = 0;
  while (random(0, 10) != 10)
  {
    if (Walked <= 10)
    {
      delay(1000);
      cout << verbs[random(0, 5)] << whereLoca[random(0, 2)] << locations[random(0,29)] << "...\n";
      Walked++;
      delay(3000);
    }
    else
    {
      cout << "Do you want to continue searching for a battle?(y/n)\n";
      cmdCheck();
    }
  }
  trainer_battle();
  int which = random(1, 4);
  if (which == 1 || which == 3)
  {
    trainer_battle();
  }
  else if (which == 2 || which == 4)
  {
    wild_battle();
  }
}
void home()
{
  place = "home";
  delay(1000);
  cout << "\nWhat would you like to do? Type 'storage' to open up PokeStorage,  type 'home' to go back to this menu, or type 'battle' to go into battle.(COMMANDS ARE CASE SENSITIVE!)\n";
  cmdCheck();
}
void storage()
{
  place = "storage";
  cout << "Welcome to PokeStorage! To deposit pokemon, type 'deposit'. To withdraw pokemon, type 'withdraw.' To come back to this menu, type 'menu'. To go back to the home menu, type 'home'.\n";
  cmdCheck();
}
void cmdCheck()
{
  string command;
  cin >> command;
  if (place == "home")
  {
    if (command == "battle")
    {
      walking();
    }
    else if (command == "storage")
    {
      storage();
    }
    else if (command == "home")
    {
      cout << "You're already at home!\n";
      cmdCheck();
    }
    else
    {
      cout << "Invalid command.\n";
      cmdCheck();
    }
  }
  else if (place == "storage")
  {
    if (command == "home")
    {
      home();
    }
    else if (command == "battle")
    {
      cout << "You must be at home to battle! Type 'home' to go home.\n";
    }
    else if (command == "storage")
    {
      cout << "You're already in storage! Type 'home' to go home, 'deposit' to deposit pokemon, or 'withdraw' to withdraw pokemon.\n";
      cmdCheck();
    }
    else if (command == "withdraw")
    {
      //withdraw();
    }
    else if (command == "deposit")
    {
      //deposit();
    }
  }
  else if (place == "battle")
  {
    if (command == "home")
    {
      cout << "You must finish the battle to go home!\n";
      cmdCheck();
    }
    else if (command == "storage")
    {
      cout << "You must be at home to access storage! To go home, type 'home'.\n";
      cmdCheck();
    }
    else if (command == "battle")
    {
      cout << "You're already in battle!\n";
      cmdCheck();
    }
    else
    {
      cout << "Invalid command.\n";
      cmdCheck();
    }
  }
  else if (place == "battle_searching")
  {
    if (command == "y" || command == "yes")
    {
      walking();
    }
    else if (command == "n" || command == "no")
    {
      home();
    }
    else
    {
      cout << "Invalid command.\n";
      cmdCheck();
    }
  }
}
int main() {
  cout << "Booting up...\n";

  delay(1000);
  cout << "Welcome to PokeStorage! Here, you can manage pokemon by depositing and withdrawing them, forever! So far, PokeStorage includes...  ";
  for (int i = 0; i < size(supportedPokemon); i++)
  {
    if (i == size(supportedPokemon) - 1)
    {
      cout << "and " << supportedPokemon[i] << ".\n";
    }
    else
    {
      cout << supportedPokemon[i] << ", ";
    }
  }
  cout << "\n==================\n\nTime to choose your first pokemon!\n";
  delay(500);
  cout << "Choosing...\n";
  string starterName = getStarter();
  cout << "Your starter pokemon is... " + starterName + "!\n";
  Pokemon pokemon1(starterName, getInfo(starterName, "type1"), getInfo(starterName, "type2"), to_int(getInfo(starterName, "health")));
  //Pokemon starterPokemon(starterName, getInfo(starterName, "type"), getInfo(starterName, "health"),/*make moves function*/testMoves[][]); //make aut ogen moves when back!
  cout << "==================\n\nBooting up PokeStorage...\n";
  home();
}
