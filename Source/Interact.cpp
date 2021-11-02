#include "../headers/interact.h"
#include "../headers/Game.h"
#include "../headers/Battle.h"
#include "../headers/Enemy.h"
#include "../headers/Item.h"
#include "../headers/Map.h"
using namespace std;

Interact::Interact()
{
	
}

// parameterized constructor
Interact::Interact(string s1, string s2, string s3)
{
	type = s1;
	name = s2;
	desc = s3;
}
// destructor
Interact::~Interact()
{
	
}

ostream& operator<<(ostream& os, const Interact& int_obj)
{
	os << left << setw(10) << int_obj.name
	   << " (" << int_obj.type << ": "
	   << int_obj.desc << ")";
	   
	return os;
}

void Interact::interact_menu(Zone& z, Inventory& inv, Character& player, Game& game, Save& save)
{
	int choice = 0;
	Battle battle;
	Enemy enemy;
	Item item;
	Map game_map;
	string string_obj;

	do
	{
		cout << "What would you like to do?:\n";
		cout << "---------------------------\n";
		cout << "[1]: Interact\n";
		cout << "[2]: Look around\n";
		cout << "[3]: Move\n";
		cout << "[4]: Open game menu\n";
		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			{
				// load interactions
				int id = z.get_zone_id();
				int r = z.get_room_id();
				int mXcoor = game_map.get_x();
				int mYcoor = game_map.get_y();
				choose_interact(inv, id, r, mXcoor, mYcoor);
				inv.print();
			}
			break;
		case 2:
			// look around
			z.get_story(game_map.get_x(), game_map.get_y());
			break;
		case 3:
			// move
			game_map.move(player, enemy, battle, inv, z, item, *this);
				break;
		case 4:
			// load game menu
			game.game_menu(enemy, player, battle, inv, save, z, string_obj, game_map, item, *this);
			break;
		default:

			break;
		}

	} while (choice < 0 || choice > 4);
}

// loads interactions for a specific zone, room, & (x, y)
void Interact::load_interact(int z_id, int r_id, int xcoord, int ycoord)
{
	ifstream file;
	string file_loc = "../Txt/Interact/" + to_string(z_id) + ".txt";
	
	// string find variables
	string coord = "(" + to_string(xcoord) + ", " + to_string(ycoord) + ")";
	string tag = "<" + to_string(r_id) + ">";
	
	string str = "";
		
	file.open(file_loc);
	
	// finds room_id (tag)
	while(str.find(tag) == string::npos && file.peek() != EOF)
	{
		getline(file, str, '\n');
	}
	
	// finds coordinates
	do
	{
		getline(file, str, '\n');
	}while(str.find(coord) == string::npos && file.peek() != EOF);
	
	// find interaction line(s)
	// getline until: blank line, next room tag, next coordinates, or EOF
	// pushes each line into a vector
	do
	{
		getline(file, str, '\n');
		
		if(str.size() == 0 || str.find_first_of("(<") != string::npos)
		{
			break;
		}
		
		int_v.push_back(str);
	}while(file.peek() != EOF);
	
	if(int_v.size() == 0)
	{
		cout << "No items to interact with\n";
		return;
	}
	
	// debug vector contents
	/*for(int i = 0; i < int_v.size(); i++)
	{
		cout << "[" << i << "]: " << int_v[i] << endl;
	}*/
	
	// used for parsing each line
	string temp = "";
	int words = 3;
	
	// parse each line into different words
	// creates a map: iterates key with Interact instance as value
	for(int i = 0; i < int_v.size(); i++)
	{
		str_v.clear();
		
		str = int_v[i];
		
		for(int i = 0; i < words; i++)
		{
			temp = str.substr(0, str.find_first_of("\t\n"));
			str = str.substr(str.find_first_of("\t\n") + 1);
			str_v.push_back(temp);
		}
		
		// create a Temporary Inteact object
		Interact temp_obj(str_v[0], str_v[1], str_v[2]);
		
		// map insertion
		int_m.insert(make_pair(i, temp_obj));
		
		cout << "[" << i + 1 << "]: " << int_m.find(i)->second << endl;
	}
	
	file.close();
	
}

Interact& Interact::get_interact(int index)
{
	Interact& new_int = int_m.find(index - 1)->second;
	
	return new_int;
}

void Interact::choose_interact(Inventory& inv, int z_id, int r_id, int xcoord, int ycoord)
{
	int choice;

	cout << "Which would you like to pick up?\n";
	cout << "--------------------------------\n";
	load_interact(z_id, r_id, xcoord, ycoord);
	cout << "Choice: ";
	cin >> choice;

	Item new_item(get_interact(choice));

	inv.add_item(new_item);
}
