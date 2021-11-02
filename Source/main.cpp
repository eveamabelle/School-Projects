#include "../headers/game.h"
#include "../headers/Battle.h"
#include "../headers/Character.h"
#include "../headers/Enemy.h"
#include "../headers/Item.h"
#include "../headers/Map.h"
#include "../headers/Inventory.h"
#include "../headers/Interact.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// define local objects/variables
	// these objects are used with member functions 
	// and are passed into each function as needed.
	


	Character player;
	Save save;
	Inventory inv;
	Zone zone;
	Interact interact;
	Game game;

	// display the start menu
	game.start_menu(save, player, inv, zone);
	
	// runs the game until the player quits
	while(game.get_playing())
	{
		// displays main game menu
		interact.interact_menu(zone, inv, player, game, save);
	}

	return 0;
}
