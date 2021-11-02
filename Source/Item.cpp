#include "../headers/interact.h"
#include "../headers/item.h"

// item constuctor
Item::Item()
{
	name = "NONE";
	type = "Item";
	desc = "NONE";
	buy = 0;
	sell = 0;
	
}

Item::Item(Interact& int_obj) 
{
	name = int_obj.get_name();
	type = int_obj.get_type();
	desc = int_obj.get_desc();
}

// item destructor
Item::~Item()
{
	
}

void Item::debug_print() const
{
	cout << "Name: " << getName() << endl;
	cout << "Type: " << getType() << endl;
}
