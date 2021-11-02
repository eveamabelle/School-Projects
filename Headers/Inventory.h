#pragma once

#include "../Headers/Item.h"
#include "../Headers/weapon.h"
#include <vector>

class Inventory
{
private:
	int mCapacity = 10;
	std::vector<Item> mItem_vector;


public:
	Inventory();

	// FUNCTIONS
	void add_item(const Item& item);
	void remove_item(int index);
	void print() const;
	//void print_battle_inventory();
	//int use_item(int index, Item& item);

	//Vector Getter
	const std::vector<Item>& get_vector() { return mItem_vector; }

	// DEBUG FUNCTIONS
	void debug_print() const
	{
		for (int i = 0; i < mCapacity; i++)
		{
			std::cout << mItem_vector.at(i).getName() << std::endl;
		}

		std::cout << std::endl;
	}
};
