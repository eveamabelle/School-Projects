#pragma once

#include "map.h"

class Game
{
	private:
		int option;
		bool playing;
				
	
	public:
		Game();
		~Game();
		
	//FUNCTIONS
		void init_game(Character& player, Zone& z);
		void quit_game();
		void valid_input();
		//void start_game(Zone& z);
		
	// MENUS
		void start_menu(Save& save_obj, Character& player, Inventory& inv, Zone& zone_obj);
		void game_instructions();
		void game_menu(Enemy& enemy, Character& player, Battle& battle, Inventory& inv_obj, Save& save_obj, Zone& zone_obj, std::string& string_obj, Map& game_map_obj, Item& item_obj, Interact& interact_obj);
		
	// SAVE-RELATED MENUS
		// GOAL: migrate these menus to 
		//		 the Save.h header file
		void save_menu(Character& player, Save& save_obj, std::string& string_obj);
		void overwrite_menu(Character& player, Save& save_obj);		
	
	// GETTERS / SETTERS		
		// GETTERS
		inline bool get_playing() const { return this -> playing; }
		
		// SETTERS
		inline void set_playing(bool value) { this -> playing = value; }
		
	// DEBUG FUNCTIONS
		// NONE RIGHT NOW
};


