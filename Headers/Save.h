#pragma once

#include "enemy.h"
//#include "enemy.h"
//#include "interact.h"
#include <fstream>

class Save
{
	private:
		std::ofstream save_file;
		std::ifstream load_file;
		
	public:
		Save();
		~Save();
		
	// MENU FUNCTIONS
	// GOAL: migrate save menu functions here,
	// 		 from Game.h header file.
		// NONE RIGHT NOW
		
	// FUNCTIONS
		void save_game(Character& player);
		int load_game(Character& player);
		
	// GETTERS / SETTERS
		// GETTERS
		
		// SETTERS
		
	// DEBUG FUNCTIONS
		void debug_new_save();
};



