#include "../headers/game.h"
#include <limits>
using namespace std;

// game constructor
Game::Game()
{
	this-> option = 0;
	this-> playing = true;
}

// game destructor
Game::~Game()
{
	
}


// member function which displays the start menu
// [1]: complete
// [2]: complete
// [3]: complete
// GOAL: IMPORT ALL TEXT FROM FILE
void Game::start_menu(Save& save_obj, Character& player, Inventory& inv, Zone& zone_obj)
{	
	do
	{
		cout << "WELCOME TO THE GAME! \n";
		cout << "--------------------- \n";
		cout << "Select an option: \n";
		cout << "[1] New Game! \n";
		cout << "[2] Continue! \n";
		cout << "[3] Quit! \n";
		cout << "Your choice: ";
		cin >> this -> option;
		
		switch(this -> option)
		{
			case 1:
				// start new game
				init_game(player, zone_obj);
				//start_game(zone_obj);
				break;
			case 2:
				cout << "\n";
				if (save_obj.load_game(player) == 1)
				{
					this -> option = 0;
					cout << "\n";
					break;
				}
				else
				{
					break;	
				}
			case 3:
				quit_game();
				break;
			default:
				Game::valid_input();
				break;
		}	
	} while ((this -> option < 1) || (this -> option > 3));
}


// member function to initalize and create a new character
void Game::init_game(Character& player, Zone& z)
{
	string name;
	
	cout << "\n";	
	cout << "Please enter a name for your character: \n";
	cout << "Your name: ";
	getline(cin.ignore(1000, '\n'), name);
	cout << "\n";
	
	cout << "Character created! \n\n";
	player.init_char(name);
	
	game_instructions();
}


void Game::game_instructions()
{
	string s;
	ifstream f;
	f.open("../Txt/Zone/Instructions.txt");
	
	while(!f.eof())
	{
		getline(f, s, '\n');
		cout << s << endl;
	}
	
	cout << "Press any key to continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
}

// GAMEPLAY MENU
// [1]: complete.
// [2]: not functional
// [3]: complete
// [4]: complete.
// GOAL: IMPORT TEXT FROM FILE
void Game::game_menu(Enemy& enemy, Character& player, Battle& battle, Inventory& inv_obj, Save& save_obj, Zone& zone_obj, string& string_obj, Map& game_map_obj, Item& item_obj, Interact& interact_obj)
{	
	do
	{
		cout << "GAME MENU \n";
		cout << "-------------- \n";
		cout << "[1]: View Character Sheet \n";
		cout << "[2]: View Inventory Sheet \n";
		cout << "[3]: View instructions \n";
		cout << "[4]: Save Game \n";
		cout << "[5]: Quit Game \n";;
		cout << "[6]: Continue Game \n";
		cout << "-------------- \n";
		cout << "Your choice: ";
		cin >> this -> option;
		
		switch(this -> option)
		{
			case 1:
				player.print_stats();
				break;
			case 2:
				cout << "\n";
				cout << "Viewing Inventory Sheet: \n\n";
				inv_obj.print();
				break;
			case 3:
				cout << "Call instructions function: STUB \n\n";
				break;
			case 4:
				save_menu(player, save_obj, string_obj);
				break;
			case 5:
				quit_game();
				break;
			case 6:
				game_map_obj.move(player, enemy, battle, inv_obj, zone_obj, item_obj, interact_obj);
				break;
			default:
				Game::valid_input();
				break;
		}
	} while((option < 1) || (option > 5));
}

// member function to quit the game
void Game::quit_game()
{
	cout << "\n";
	cout << "\n";
	cout << "Quitting game \n\n";
	playing = false;
}


// SAVE MENU
// [1]: complete
// [2]: complete
// GOAL: MIGRATE TO SAVE.CPP
// GOAL: IMPORT TEXT FROM FILE
void Game::save_menu(Character& player, Save& save_obj, string& string_obj)
{	
	do
	{
	
		cout << "SAVE MENU \n";
		cout << "--------- \n";
		cout << "Select an option: \n";
		cout << "[1] Save game \n";
		cout << "[2] Go back \n";
		cout << "Your choice: ";
		cin >> this -> option;
		
		switch(this -> option)
		{
			case 1:
				overwrite_menu(player, save_obj);
				break;
			case 2:
				cout << "\n";
				break;
			default:
				Game::valid_input();
				break;
		}
	} while((this -> option < 1) || (this -> option > 2));	
}

// [1]: complete
// [2]: complete
// GOAL: MIGRATE TO SAVE.CPP
// GOAL: IMPORT TEXT FROM FILE
void Game::overwrite_menu(Character& player, Save& save_obj)
{
	do 
	{
		cout << "\n";
		cout << "OVERWRITE MENU \n";
		cout << "-------------- \n";
		cout << "Would you like to overwrite your previous save file? \n";
		cout << "WARNING: THIS ACTION CANNOT BE UNDONE! \n";
		cout << "Select an option: \n";
		cout << "[1]: Yes. \n";
		cout << "[2]: No. \n";
		cout << "Your choice: ";
		cin >> this -> option;
		
		switch(this -> option)
		{
			case 1:
				cout << "\n";
				save_obj.save_game(player);
				cout << "\n";
				break;
			case 2:
				cout << "\n";
				break;
			default:
				Game::valid_input();
				break;
		}
	} while((this -> option < 1) || (this -> option > 2));	

}

// member function for input validation
void Game::valid_input()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "\n" << "Invalid! please choose a vaild option: \n\n";
}

// Reads the file that tells the story before a player starts fighting monsters.
/*void Game::start_game(Zone& zone_obj) {
	string story;
	ifstream f;
	int story_start_zone = 100;
	int story_start_room_id = 101;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	// Opening the Beginning story file
	f.open("../Txt/StoryStart.txt");
	//Reading each line of the file and printing out the story.
	while (!f.eof())
	{
		getline(f, story, '\n');
		cout << story << endl;
	}

	//Setting the zone ID to 100 and room ID to 101 as that is the
	// location of the barn (player's house during the game) as that 
	// is where the player will start
	//the game before venturing to other locations.
	zone_obj.set_zone_id(story_start_zone);
	zone_obj.set_room_id(story_start_room_id);

	cout << "Press any key to continue..\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	
}*/
