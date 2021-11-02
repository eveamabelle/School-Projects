#include "../Headers/character.h"
using namespace std;

// constructor used to create a new character
// GOAL: ADD MORE STATS
Character::Character()
{
	// basic stats
	this -> name = "";
	this -> level = 0;
	this -> curr_hp = 500;
	this -> max_hp = 500;
	this -> exp = 0;
	this -> exp_next = 10;
	
	// battle stats
	this -> strength = 5;
	//this -> defense = 3;
	//this -> magic = 0;
}

// destructor
Character::~Character()
{
	
}

// member function to initialize a character with a name
void Character::init_char(const string name)
{
	this -> name = name;
	this -> level = 1;
}

// member function to display the character sheet
// GOAL: ADD MORE STATS
void Character::print_stats()
{
	// basic stats
	cout << endl;
	cout << "Character Sheet \n" << endl;
	cout << "Name: " << this -> name << "\n";
	cout << "Level: " << this -> level << "\n";
	cout << "HP: " << this -> curr_hp << " / " << this -> max_hp << "\n";
	cout << "Exp: " << this -> exp << "\n";
	cout << "Next level: " << this -> exp_next << "\n";
	cout << endl;
	
	// battle stats
	cout << "Strength: " << this -> strength << "\n";
	//cout << "Magic: " << this -> magic << "\n\n";
}

void Character::attack(Character& victim) {
	int current_hp = victim.get_curr_hp();
	int new_hp = current_hp - (current_hp / 10);

	victim.set_curr_hp(new_hp);

	if (is_enemy()) {
		cout << "Enemy has taken a hit of " << new_hp << " HP points!";
	}
	else {
		cout << "You have taken a hit of " << new_hp << " HP points!";
		int strength = get_strength();
		int new_strength = strength - 5;
		set_strength(new_strength);
	}

}

void Character::defend(Character& enemy) {
	int current_hp = enemy.get_curr_hp();
	int added_hp = current_hp - (current_hp / 10);
	int new_hp = get_curr_hp() + added_hp;

	set_curr_hp(new_hp);
	

	cout << "You're defense worked!" << added_hp << " HP points restored!" << endl;
}

void Character::battle_use_item(int adding_stat) {
	int current_strength = get_strength();
	int new_strength = current_strength + adding_stat;

	set_strength(new_strength);
	cout << "Inventory Item now in use." << endl;

}
