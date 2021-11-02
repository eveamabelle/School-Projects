#include "../Headers/save.h"
#include <iostream>
using namespace std;


Save::Save()
{
	
}

Save::~Save()
{
	
}

// member function to save character data
// GOAL: SAVE STORY PROGRESS & INVENTORY
void Save::save_game(Character& player)
{
	string str;
	int val[7];
	
	str = player.get_name();
	val[0] = player.get_level();
	val[1] = player.get_curr_hp();
	val[2] = player.get_max_hp();
	val[3] = player.get_exp();
	val[4] = player.get_exp_next();
	val[5] = player.get_strength();
	//val[6] = player.get_magic();
	
	
	save_file.open("../Save/SAVE_FILE.txt");
	save_file << str << endl;
	
	for (int i = 0; i < 7; i++)
	{
		save_file << val[i] << endl;
	}
	
	save_file.close();
	
	cout << "Game saved successfully \n";
}

// member function to load previously saved character data
// GOAL: LOAD STORY & INVENTORY
int Save::load_game(Character& player)
{
	string str[8];
	
	load_file.open("../Save/SAVE_FILE.TXT");
	
	for (int i = 0; i < 8; i++)
	{
		getline(load_file, str[i]);
		
		if (str[0] == "RAW_SAVE_FILE")
		{
			cout << "ERORR: No save file to load \n";
			return 1;
		}
	}
	
	player.set_name(str[0]);
	player.set_level(stoi(str[1]));
	player.set_curr_hp(stoi(str[2]));
	player.set_max_hp(stoi(str[3]));
	player.set_exp(stoi(str[4]));
	player.set_exp_next(stoi(str[5]));
	player.set_strength(stoi(str[6]));
	//player.set_magic(stoi(str[7]));
		
	cout << "Loaded successfully! \n";
	cout << "Continuing game \n\n";
	
	return 0;
}

// debug member function to clear the save file
void Save::debug_new_save()
{
	save_file.open("../Save/SAVE_FILE.TXT", ofstream::out | ofstream::trunc);
	
	save_file << "RAW_SAVE_FILE";
	save_file.close();
}
