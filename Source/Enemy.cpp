#include "../Headers/Enemy.h"
using namespace std;

Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{
	
}

void Enemy::random_enemy(Character& c)
{
	int x;
	
	srand((unsigned) time(0));
	x = (rand() % 5) + 1;
	
	switch(x)
	{
		case 1:
			name = "Wyrm";
			type = "Dragon";
			break;
		case 2:
			name = "Skeleton";
			type = "Undead";
			break;
		case 3:
			name = "Zombie";
			type = "Undead";
			break;
		case 4:
			name = "Bat";
			type = "Flying";
			break;
		case 5:
			name = "Wolf";
			type = "Creature";
			break;
		case 6:
			name = "Dark Knight";
			type = "Human";
			break;
	}
	
	max_hp = (c.get_max_hp() + ((rand() % 100) * 1.25));
	curr_hp = max_hp;
	level = (c.get_level() + ((rand() % 5)));
	strength = (c.get_strength() + ((rand() % 3)));
	//defense =  (c.get_defense() + ((rand() % 3 )));
}

void Enemy::print_enemy_stats()
{
	// basic stats
	cout << endl;
	cout << "Enemy Sheet \n" << endl;
	cout << "Name: " << name << "\n";
	cout << "HP: " << curr_hp << " / " << max_hp << "\n";
	cout << "Level: " << level << "\n";
	cout << "Strength: " << strength << '\n';
	//cout << "Defense : " << defense << '\n';
	cout << "Type: " << type << endl;
	cout << endl;
}
