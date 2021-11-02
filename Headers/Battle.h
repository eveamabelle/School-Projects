#pragma once

#include "save.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>
#include <limits>

class Battle
{
	private:

	public:
		Battle();
		~Battle();

		void start_battle(Character& c, Enemy& e, Inventory& i, Item& item);
		void draw(Enemy& e);
		void draw(Character& c, Enemy& e, bool& b);
		bool player_turn(Character& c, Enemy& e, Inventory& i, int& x, bool& b, Item& item);
		void enemy_turn(Character& c, Enemy& e, bool& b);
		void end_turn(bool& b);
 };



