#pragma once

#include "character.h"
#include <ctime>
#include <cstdlib>

class Enemy : public Character
{
protected:
	//Protected methods to determine whether the victim of the attack is an enemy or a player
	bool is_enemy() const override { return true; }

private:
		string type;
		string status;
	  
public:
	   Enemy();
	   ~Enemy();
	   
	   void random_enemy(Character& c);      
		  
	// accessors
	   string get_type() const { return type; }
	   
	// modifiers 
	   
	// debug
	   void print_enemy_stats();
	   
 };



