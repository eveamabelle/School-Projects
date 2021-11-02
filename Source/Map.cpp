//#include "../Headers/Game.h"
#include "../Headers/Map.h"
//#include "../Headers/Battle.h"
using namespace std;
// constructor
Map::Map()
{
	// (x, y) coordinates
	x = 0;
	y = 0;
	max_x = num_cols - 1;
	max_y = num_rows - 1;

	// index variables for use with vectors
	r_index = 0;
	z_index = 0;

	// grid/map metrics
	num_cols = 3;
	num_rows = 3;
	num_spaces = num_rows * num_cols;
	num_lines = (num_rows * 2) + 1;

	// map space status
	empty = "   ";
	filled = " x ";

}
// destructor
Map::~Map()
{

}

void Map::build_grid()
{
	grid.clear();

	grid.resize(num_cols, vector<string>(num_rows, empty));
	grid[y].at(x) = filled;
}

void Map::draw(Zone& z)
{
	string banner = "| Game Map |";

	cout << "+" << setfill('-') << setw(banner.size()) << "+\n";
	cout << banner << endl;
	cout << "+" << setfill('-') << setw(banner.size()) << "+\n";

	int col = 0;
	int row = 0;
	int num = 0;
	char up = 24;
	char right = 26;

	if (z.get_room_id() == 101)
	{
		for (int a = 0; a < num_lines; a++)
		{
			// draw grid line
			if (a % 2 == 0)
			{
				cout << "  ";

				for (int b = 0; b < num_cols; b++)
				{
					cout << "+" << setfill('-') << setw(3) << "";
				}

				if (a == num_lines - 3 || a == num_lines - 1)
				{
					cout << setw(0) << "+---+\n";
				}
				else
				{
					cout << setw(0) << "+\n";
				}
			}
			// draw row
			else
			{

				cout << num << " ";

				for (int b = 0; b < num_cols; b++)
				{
					cout << "|" << grid[b][row];
					col++;
				}

				if (a == num_lines - 2)
				{
					cout << setw(0) << "| " << right << " |\n";
				}
				else
				{
					cout << setw(0) << "|\n";
				}

				row++;
				num++;
			}
		}

		cout << " ";

		for (int i = 0; i < num_cols; i++)
		{
			cout << "   " << i;
		}

		col++;
	}
	else
	{
		cout << "  +---+\n";
		cout << "  | " << up << " |\n";

		for (int a = 0; a < num_lines; a++)
		{
			// draw grid line
			if (a % 2 == 0)
			{
				cout << "  ";

				for (int b = 0; b < num_cols; b++)
				{
					cout << "+" << setfill('-') << setw(3) << "";
				}

				if (a == num_lines - 3 || a == num_lines - 1)
				{
					cout << setw(0) << "+---+\n";
				}
				else
				{
					cout << setw(0) << "+\n";
				}
			}
			// draw row
			else
			{

				cout << num << " ";

				for (int b = 0; b < num_cols; b++)
				{
					cout << "|" << grid[b][row];
					col++;
				}

				if (a == num_lines - 2)
				{
					cout << setw(0) << "| " << right << " |\n";
				}
				else
				{
					cout << setw(0) << "|\n";
				}

				row++;
				num++;
			}
		}

		cout << " ";

		for (int i = 0; i < num_cols; i++)
		{
			cout << "   " << i;
		}

		col++;
	}

	cout << endl;
}

void Map::build_map(Zone& z)
{
	build_grid();
	draw(z);
	curr_loc();
}

void Map::curr_loc()
{
	cout << "Your current location is: ";
	cout << "(" << x << ", " << y << ")\n";
}

void Map::move(Character& player, Enemy& enemy, Battle& battle, Inventory& inv_obj, Zone& z, Item& item, Interact& interact_obj)
{
	int choice = 0;

	build_grid();
	z.get_story(x, y);


	while (true)
	{
		draw(z);
		curr_loc();

		// pause for input
		cout << "\n\n";
		cout << "Press enter to continue..";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n\n";

		// move menu
		cout << "Where do you want to go?: \n";
		cout << "[1]: North\n";
		cout << "[2]: South\n";
		cout << "[3]: East\n";
		cout << "[4]: West\n";
		cout << "[5]: exit\n";
		cout << "Option: ";
		cin >> choice;
		cin.ignore();
		cout << endl;

		if (!move_mechanics(player, enemy, battle, inv_obj, z, item, choice, interact_obj)) {
			build_grid();
		}
		else {
			break;
		}
	}
}

bool Map::move_mechanics(Character& player, Enemy& enemy, Battle& battle, Inventory& inv_obj, Zone& z, Item& item, int choice, Interact& interact_obj)
{
	static int last_battle_room_num = 0;
	switch (choice)
	{
		// north
	case 1:
		// if (0, 0) 
		if (x == 0 && y == 0) // and monsters defeated >= 5
		{
			// if in room 101 (first room in game)
			if (z.get_room_id() == 101)
			{
				cout << "Cannot move north\n\n";
				break;
			}
			// any other room in game
			else
			{
				// if in first room in current zone
				if (r_index == 0)
				{
					// previous zone
					z_index--;
					// set zone_id
					z.new_zone(z_index);
					// load room_data vector
					z.load_room_data();

					// last room in previous zone
					// set r_index to the size of room_data vector
					r_index = z.room_data.size() - 1;
					// set room
					z.new_room(r_index);

					// set x and y to (max, max)
					x = 2;
					y = 2;
				}
				// any other room in curent zone
				else
				{
					// previous room in current zone
					r_index--;
					z.new_room(r_index);

					// set (x, y) coordinates to max value
					x = 2;
					y = 2;
				}

				// load next zone & story
				z.load_zone_data(z.get_zone_id(), z.get_room_id());
				z.load_story(x, y);
			}
		}
		// not in (0, 0)
		else
		{
			if (x == 0)
			{
				cout << "Cannot move north\n\n";
				break;
			}

			// next space on map (current room and zone)
			x--;
		}

		break;
		// south
	case 2:
		if (x == 2)
		{
			cout << "Cannot move south\n\n";
			break;
		}

		x++;
		break;
		// east
	case 3:
		// if (2, 2)	
		if (x == 2 && y == 2) // and monsters defeated >= 5
		{
			// if in room 303 (final room in game)
			if (z.get_room_id() == 303 && player.monster_counter >= 10) // and monsters defeated == 75
			{
				// game complete
				// load completition text from file
				ifstream f;
				f.open("StoryEnd.txt");
				string str1 = "";

				while (f.peek() != EOF)
				{
					getline(f, str1, '\n');
				}

				f.close();
				cout << "press any key to exit!\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				exit(0);
			}
			// any other room in game
			else
			{
				// if leaving last room in current zone
				if (r_index + 1 == z.zone_data.size() - 1)
				{
					// next zone
					z_index++;
					z.new_zone(z_index);
					z.load_room_data();

					// first room in next zone
					r_index = 0;
					z.new_room(r_index);
				}
				// any other room in current zone
				else
				{
					// next room in current zone
					r_index++;
					z.new_room(r_index);
					last_battle_room_num = 0;
				}

				// reset x & y to (0,0)
				reset_xy();
				// load next zone & story
				z.load_zone_data(z.get_zone_id(), z.get_room_id());

				z.load_story(x, y);
			}
		}
		// not in (2, 2)
		else
		{
			if (y == 2)
			{
				cout << "Cannot move east\n\n";
				break;
			}

			//next space on map
			y++;
		}

		break;
	case 4:
		// west
		if (y == 0)
		{
			cout << "Cannot move west\n\n";
			break;
		}

		y--;
		break;
	case 5:
		// exit
		cout << "Exiting...";
		return true;
		break;
	default:
		// all else
		break;
	}

	z.get_story(x, y);

	int curr_room_id = z.get_room_id();

	if ((curr_room_id % 2 == 0) && (curr_room_id != last_battle_room_num)) {
		Battle battle;
		cout << "Battle instance created" << endl;
		battle.start_battle(player, enemy, inv_obj, item);
		last_battle_room_num = curr_room_id;
	}
	return false;
}

