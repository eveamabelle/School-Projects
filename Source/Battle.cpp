#include "../Headers/Battle.h"
using namespace std;

Battle::Battle()
{

}

Battle::~Battle()
{

}

void Battle::start_battle(Character& c, Enemy& e, Inventory& i, Item& item)
{
	e.random_enemy(c);
	
	int choice;
	bool is_turn = true;
	
	draw(e);
	
	while(e.get_curr_hp() > 0 || c.get_curr_hp() > 0)
	{
		draw(c, e, is_turn);
		if (player_turn(c, e, i, choice, is_turn, item)) {
			break;
		}
		enemy_turn(c, e, is_turn);
		end_turn(is_turn);
		
		// pauses the 
		cout << "Press any key to continue..\n";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
	}

	if ((c.get_curr_hp() > 0) && (e.get_curr_hp() < 0)) {
		++c.monster_counter;
	}
}

void Battle::draw(Enemy& e)
{
	string s;
	s = "A random " + e.get_name() + " appears!";
	
	cout << "+" << setfill('-') << setw(s.size() + 4) << "+\n";
	cout << "| " << s << " |\n";
	cout << "+" << setfill('-') << setw(s.size() + 4) << "+\n";
}

void Battle::draw(Character& c, Enemy& e, bool& b)
{
	stringstream ss;
	string s1 = "BATTLE SCREEN";
	string s2;
	
	if(b)
	{
		s2 = "Your turn!";
	}
	else
	{
		s2 = e.get_name() + "'s turn!";
	}
	
	// battle banner
	ss << "+" << setfill('-') << setw(s1.size() + 5) << "+\t+" << setfill('-') << setw(s2.size() + 4) << "+\n";
	cout << ss.str();
	cout << "| " << s1 << " |\t| " << s2 << " |\n";
	cout << ss.str() << endl;
	
	// display enemy stats
	cout << setfill(' ');
	cout << setw(40) << "" << e.get_name() << endl;
	cout << setw(40) << "" << "Level: " << e.get_level() << endl;
	cout << setw(40) << "" << e.get_curr_hp() << " / " << e.get_max_hp() << endl;
	cout << "\n\n\n";
	
	// display character stats
	cout << c.get_name() << endl;
	cout << "Level: " << c.get_level() << endl;
	cout << c.get_curr_hp() << " / " << c.get_max_hp() << endl << endl;
}

bool Battle::player_turn(Character& c, Enemy& e, Inventory& i, int& x, bool& b, Item& item)
{
	std::vector<Item> battle_inv_vector;
	int y = 1;
	if(b)
	{
		do
		{
			cout << "What would you like to do?\n";
			cout << "--------------------------\n";
			cout << "[1]: Attack!\n";
			cout << "[2]: Defend!\n";
			cout << "[3]: Use item!\n";
			cout << "[4]: Run away!\n";
			cout << "--------------\n";
			cout << "Option: ";
			cin >> x;
			
			cout << endl;
			
			switch(x)
			{
				case 1:
					cout << "Attack!\n";	
					c.attack(e);
					break;
				case 2:
					cout << "Defend!\n";
					c.defend(e);
					break;
				case 3:
					cout << "Use item!\n";
					i.print();
					cout << "Choose an item![Type 1, 2, 3, or 4, and etc]" << endl;
					cin >> y;

					battle_inv_vector = i.get_vector();

					if (y > 0 && y < battle_inv_vector.size()) {
						//int add_stat = i.use_item(y, item);
						//c.battle_use_item(add_stat);				////////////////////////////////////

						i.remove_item(y);
					}

					break;
				case 4:
					cout << "Run away!\n";
					break;
				default:
					y = 1;
					// VALID INPUT
			}
			if (x == 4) {
				return true;
			}
		}while((x < 1) || (x > 4));
	}
	return false;
}

void Battle::enemy_turn(Character& c, Enemy& e, bool& b)
{
	if(!b)
	{
		// enemy makes a move
		cout << "Enemy attack" << endl;
		e.attack(c);
	}
}

void Battle::end_turn(bool& b)
{
	if(b)
	{
		b = false;
	}
	else
	{
		b = true;
	}
}
