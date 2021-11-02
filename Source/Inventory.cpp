#include "../headers/inventory.h"

// inventory constructor
Inventory::Inventory()
{
	
}


// member function to add a new item to the inventory
void Inventory::add_item(const Item& item)
{
	mItem_vector.push_back(item);
}

// member function to remove an item from the inventory
void Inventory::remove_item(int index)
{
	mItem_vector.erase(mItem_vector.begin() + index);
}

//Function to print inventory
void Inventory::print() const 
{
	for (std::size_t i = 0; i < mItem_vector.size(); ++i)
	{
		mItem_vector[i].debug_print();
	}
}
