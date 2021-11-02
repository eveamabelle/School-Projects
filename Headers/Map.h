#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "battle.h"

#include "../Headers/Zone.h"
//#include "../Headers/Character.h"
//#include "../Headers/Enemy.h"
using namespace std;

class Game;

class Map
{
private:
	// position (x, y)
	int x;
	int y;
	int max_x;
	int max_y;

	// location indices
	int r_index;
	int z_index;

	// grid size
	int num_cols;
	int num_rows;
	int num_spaces = num_rows * num_cols;
	int num_lines = (num_rows * 2) + 1;

	// cell contents
	string empty;
	string filled;

	// grid vector
	vector<vector<string>> grid;

public:
	// CONSTRUCTOR / DESTRUCTOR
	Map();
	~Map();

	// MEMBER FUNCTIONS
	void build_grid();
	void draw(Zone& z);
	void curr_loc();
	void build_map(Zone& z);
	void move(Character& player, Enemy& enemy, Battle& battle, Inventory& inv_obj, Zone& z, Item& item, Interact& interact_obj);
	bool move_mechanics(Character& player, Enemy& enemy, Battle& battle, Inventory& inv_obj, Zone& z, Item& item, int choice, Interact& interact_obj);

	// ACCESSORS
	inline int get_x() const { return x; }
	inline int get_y() const { return y; }

	// debug
	inline int get_z_index() const { return z_index; }
	inline int get_r_index() const { return r_index; }

	// MODIFIERS
	inline void reset_xy() { x = 0; y = 0; }
};

