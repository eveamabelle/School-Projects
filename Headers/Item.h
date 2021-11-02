#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Interact;

class Item
{
	private:
		string name;
		string type;
		string desc;
		
		int buy;
		int sell;
		
	public:
		Item();
		Item(Interact& int_obj);
		virtual ~Item();
	
	// FUNCTIONS
		// 	NONE RIGHT NOW
	
	// GETTERS / SETTERS
		inline string getName() const { return name; }
		inline string getType() const { return type; }
	
	// DEBUG FUNCTIONS
	 void debug_print() const;
};

#endif
