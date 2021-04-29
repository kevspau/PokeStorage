#include <iostream>
#include <array>
#include <string>
using namespace std;
enum trait { weakness, strength, type };
int random(int min, int max)
{
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<> dist(min, max);
  return dist(mt);
}
string pokeDesc[3][9][4] = {{{"Charmander", "Fire", "100"}, {"Squirtle", "Water", "100"}, {"Pichu", "Electric", "80"}, {"Rowlet", "Grass", "Flying", "100"}, {"Litleo", "Fire", "100"}, {"Magikarp", "Water", "50"}, {"Eevee", "Normal", "80"}, {"Bulbasaur", "Grass", "Poison", "100"}}, {{"Jigglypuff", "Psychic", "250"}, {"Espeon", "Psychic", "200"}, {"Pikachu", "Electric", "130"}, {"Warturtle", "Water", "180"}, {"Ivysaur", "Grass", "Poison", "200"}, {"Gyarados", "Water", "Flying", "240"}, {"Ditto", "Normal", "230"}, {"Flareon", "Fire", "185"}, {"Vaporeon", "Water", "185"}}, {{"Raichu", "Electric", "210"}, {"Blastoise", "Water", "265"}, {"Venusaur", "Grass", "Poison", "260"}, {"Charizard", "Fire", "Flying", "275"}, {"Latios", "Psychic", "Dragon", "310"}, {"Latias", "Psychic", "Dragon", "315"}, {"Mewtwo", "Psychic", "320"}, {"Mew", "Psychic", "305"}}};
  //////////common//////////
  //////////rare/////////////
	string typeWeakDesc[][8] = {{"Fire", "Water", "Ground", "Rock"}, {"Water", "Water", "Grass", "Dragon"}, {"Grass", "Flying", "Poison", "Bug", "Steel", "Fire", "Grass", "Dragon"}, {"Ground", "Grass", "Electric", "Dragon"}, {"Psychic", "Steel", "Psychic", "Dark"}};
	string typeStrongDesc[][4] = {{"Water", "Ground", "Rock", "Fire"}, {"Grass", "Ground", "Rock", "Water"}, {"Electric", "Flying", "Water"}, {"Psychic", "Fighting", "Poison"}};
string getInfo(string pokemon, string trait)
{
  for (int i1 = 0; i1 < size(pokeDesc); i1++)
  {
    for (int i2 = 0; i2 < size(pokeDesc[i1]); i2++)
    {
      if (pokeDesc[i1][i2][0] == pokemon)
      {
        if (pokeDesc[i1][i2][3] == "")
        {
          if (trait == "name")
          {
            return pokeDesc[i1][i2][0];
          }
          else if (trait == "health")
          {
            return pokeDesc[i1][i2][2];
          }
          else if (trait == "type")
          {
            return pokeDesc[i1][i2][1];
          }
        }
        else if (pokeDesc[i1][i2][3] != "")
        {
          if (trait == "name")
          {
            return pokeDesc[i1][i2][0];
          }
          else if (trait == "health")
          { 
            return pokeDesc[i1][i2][3];
          }
          else if (trait == "type1")
          {
            return pokeDesc[i1][i2][1];
          }
          else if (trait == "type 2")
          {
            return pokeDesc[i1][i2][2];
          }
        }
      }
    }
  }
return "Error";
}
string getStarter()
{
  return pokeDesc[0][random(0, size(pokeDesc[0]) - 1)][0];
}
string getTypeInfo(string pokemon, trait trait)
{
	for (int i1 = 0; i1 < size(pokeDesc); i1++)
	{
		for (int i2 = 0; i2 < size(pokeDesc[i1]); i2++)
		{
			if (pokeDesc[i1][i2][0] == pokemon)
			{
				if (pokeDesc[i1][i2][3] == "")
				{
					if (trait == trait.weakness)
					{
						string pokeType = pokeDesc[i1][i2][2];
						for (int tI = 0; tI < size(typeWeakDesc); tI++)
						{
							if (typeWeakDesc[tI][0] == pokeType)
							{
								string typeList[8];
								for (int tII = 1; tII < size(typeWeakDesc[tI]); tII++)
								{
									int index = 0;
									typeList[index] = typeWeakDesc[tI];
									index++;
								}
								return typeList;
							}
						}
					}
					else if (trait == trait.strength)
					{
						
					}
				}
			}
		}
	}
}
