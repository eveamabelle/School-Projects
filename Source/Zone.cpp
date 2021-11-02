#include "../headers/zone.h"

// constructor
Zone::Zone()
{
	zone_id = 100;
	room_id = 101;
	room_name = "House";
	zone_file = "../Txt/Zone/Zone.txt";
	room_file = "../Txt/Rooms/Rooms.txt";
	story_file = "../Txt/Story/" + to_string(zone_id) + ".txt";
	
	instructions = "instructions.txt";
	string manual = "User-Manual.txt";
	string end_game = "StoryEnd.txt";
	
	load_zones();
	load_zone_data();
	load_room_data();
	load_story(0, 0);
}

// destructor
Zone::~Zone()
{
	
}

// pushes all zone IDs into zone_v vector
// called once when constructor called, doesn't
// need to be called again
void Zone::load_zones()
{
	// clear zones_v in order to load new data
	zones_v.clear();
	
	string str = "";

	//open zone.txt file
	file.open(zone_file);
	
	while(!file.eof())
	{
		getline(file, str, '\n');
		
		if(str.find("<") != string::npos)
		{
			str = str.substr(1, str.find('>') - 1);
			zones_v.push_back(stoi(str));
		}
	}
	
	// debug print vector
	/*for(int i = 0; i < zones_v.size(); i++)
	{
		cout << zones_v[i] << endl;
	}*/
	
	file.close();
}

// loads all data IDs pertaining to a zone
// these IDs will be used with other functions
// get whatever data we need
void Zone::load_zone_data(int z_id, int r_id)
{
	// clear zone_vector in order to load new data
	zone_data.clear();
	
	string str = "";

	//open zone.txt file
	file.open(zone_file);
	
	// find zone_id
	do
	{
		getline(file, str, '\n');
	}while(str.find(to_string(z_id)) == string::npos && !file.eof());
	
	// get line after zone ID tag <xxx>
	getline(file, str, '\n');
			
	// isolate room_id and remove \t from string
	int id_pos = str.find(to_string(r_id));
	
	// find all IDs pertaining to specific room
	while(str.find('<') == string::npos && !file.eof())
	{
		if(str.find("{") == string::npos)
		{
			str = str.substr(id_pos, str.find('\t') - 1);
			str.erase(remove(str.begin(), str.end(), '\t'), str.end());
			zone_data.push_back(stoi(str));
		}
		// set room_name
		else
		{		
			str = str.substr(id_pos);
			str = str.substr(str.find_first_not_of('\t'));
			room_name = str.substr(0, str.find('\t'));
		}
		
		getline(file, str, '\n');
	}
	
	// debug print vector
	/*for(int i = 0; i < zone_data.size(); i++)
	{
		cout <<  zone_data[i] << endl;
	}
	
	cout << room_name << endl;*/
	
	file.close();
}

// pushes all rooms in a specific zone
// into room_data vector
void Zone::load_room_data()
{
	room_data.clear();
	
	string str = "";
	
	file.open(room_file);
	
	do
	{
		getline(file, str, '\n');
	}while(str.find(to_string(zone_id)) == string::npos && !file.eof());
	
	getline(file, str, '\n');
	
	while(str.find('<') == string::npos && !file.eof())
	{
		room_data.push_back(stoi(str));
		getline(file, str, '\n');
	}
	
	// debug print vector
	/*for(int i = 0; i < room_data.size(); i++)
	{
		cout << room_data[i] << endl;
	}*/
	
	file.close();
}

void Zone::load_story(int xcoord, int ycoord)
{
	story.clear();
	
	string str = "";
	string tag = "<" + to_string(room_id) + ">";
	string story_file = "../Txt/Story/" + to_string(zone_id) + ".txt";
	
	file.open(story_file);
	
	// find appropriate data by finding the data tag <xxx>
	do
	{
		getline(file, str, '\n');
	}while(str.find(tag) == string::npos && !file.eof());
	
	
	// skip any empty lines and get line with coordinates
	do
	{
		getline(file, str, '\n');
	}while(str.size() == 0);
	
	// add data to map
	do
	{
		// remove parenthesis from coordinate string
		str = str.substr(str.find("(") + 1, str.find(")") - 1);
		
		// remove spaces from coordinate string
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		
		// assign coordinate data to temp variables
		int x = str.at(0) - '0';
		int y = str.at(2) - '0';
		
		// temp variable for string concatenation
		string temp = "";
		
		do
		{
			getline(file, str, '\n');
			
			if(str.find_first_of("(<") != string::npos || file.eof())
				break;
				
			temp = temp + '\n' + str;
			//add temp to map value
						
		}while(str.find_first_of("(<") == string::npos);
		
		// insert into map
		story.insert({{x, y}, temp});	
	}while(str.find("<") == string::npos && !file.eof());
	
	file.close();
}

// prints the story text relative to current location
// as well as the story and location banner
// (need to fix location banner)
void Zone::get_story(int xcoord, int ycoord)
{
	string banner = "| Story |";
	
	cout << "+" << setfill('-') << setw(banner.size() - 1) << "+";
	cout << setfill('-') << setw(room_name.size() + 4) << "+\n";
	cout << banner << " " << room_name << " |\n";
	cout << "+" << setfill('-') << setw(banner.size() - 1) << "+";
	cout << setfill('-') << setw(room_name.size() + 4) << "+\n";
	
	cout << story[make_pair(xcoord, ycoord)] << endl;
}

// debug
// prints every key-pair and value from the story map
void Zone::print_story()
{
	for(auto e : story)
	{
		cout << "(" << e.first.first << "," << e.first.second << ")\n";
		cout << "Value: " << e.second << endl;
	}
}
