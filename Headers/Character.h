#pragma once

#include "inventory.h"
#include <iostream>
#include <string>
using namespace std;

class Character
{
	protected:
	// BASIC STATS
		std::string name;
		int level;
		int curr_hp;
		int max_hp;
		int exp;
		int exp_next;
		
	// BATTLE STATS
		// STATUS: WILL ADD MORE
		int strength;
		//int defense;
		//int magic;
		
		
	//Virtual Functions
		virtual bool is_enemy() const { return false; }
			
	public:
		Character();
		~Character();
		
	// FUNCTIONS
		void init_char(const std::string name);
		void print_stats();

		void attack(Character& victim);
		void defend(Character& enemy);
		void battle_use_item(int stat_to_add);
		int monster_counter = 0;
	
	// GETTERS / SETTERS	
		// GETTERS
		inline std::string get_name() { return this -> name; }
		inline int get_level() const { return this -> level; }
		inline int get_curr_hp() const { return this -> curr_hp; }
		inline int get_max_hp() const { return this -> max_hp; }
		inline int get_exp() const { return this -> exp; }
		inline int get_exp_next() const { return this -> exp_next; }
		inline int get_strength() const { return this -> strength; }
		//inline int get_defense() const { return this -> defense; }
		//inline int get_magic() const { return this -> magic; }
		
		// SETTERS
		inline void set_name(std::string str) { this -> name = str; }
		inline void set_level(int value) { this -> level = value; }
		inline void set_curr_hp(int value) { this -> curr_hp = value; }
		inline void set_max_hp(int value) { this -> max_hp = value; }
		inline void set_exp(int value) { this -> exp = value; }
		inline void set_exp_next(int value) { this -> exp_next = value; }
		inline void set_strength(int value) { this -> strength = value; }
		//inline void set_defense(int value) { this -> defense = value; }
		//inline void set_magic(int value) { this -> magic = value; }
		
	// DEBUG FUNCTIONS
		// NONE RIGHT NOW
};


