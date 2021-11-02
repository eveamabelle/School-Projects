#pragma once
#include "zone.h"
#include "Map.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

class Save;
class Game;
class Inventory;
class Character;

class Interact
{
	private:
		// variables
		string type;
		string name;
		string desc;
		
	public:
		Interact();
		Interact(string s1, string s2, string s3);
		~Interact();
		
		// containers
		vector<string> int_v;
		vector<string> str_v;
		map<int, Interact> int_m;
		
		//void interact_menu();
		void interact_menu(Zone& z, Inventory& inv, Character& player, Game& game, Save& save);
		void load_interact(int z_id, int r_id, int xcoord, int ycoord);
		Interact& get_interact(int index);
		void choose_interact(Inventory& inv, int z_id, int r_id, int xcoord, int ycoord);
		
		inline string get_type() const { return type; }
		inline string get_name() const { return name; }
		inline string get_desc() const { return desc; }
		
		// operator overload<<
		friend ostream& operator<<(ostream& os, const Interact& int_obj);		
};

