#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;

class Zone
{
	private:
		ifstream file;
		int zone_id;
		int room_id;
		string room_name;
		
		// file locations
		string zone_file;
		string room_file;
		string story_file;
		string instructions;
		string manual;
		string end_game;
		
		
		// vector contains all zone_ids
		vector<int> zones_v;
		
	// PRIVATE MEMEBR FUNCTIONS
		void load_zones();
				
	public:
		Zone();
		~Zone();
	   
		vector<int> zone_data;				// vector contains all room_ids pertaining to a zone
		vector<int> room_data;				// vector contains all data peratining to a room_id
		map<pair<int, int>, string> story;	// story map w/ key-pair and string-values
	   
	// MEMBER FUNCTIONS
		void get_story(int xcoor, int ycoord);
		
		void load_zone_data(int = 100, int = 101);
		void load_room_data();
		void load_story(int xcoord, int ycoord);
		
	// ACCESSORS
		inline string get_r_name() const { return room_name; }
		inline int get_room_id() const { return room_id; }
		inline int get_zone_id() const { return zone_id; }
			
	// MODIFIERS
		inline void new_room(int index) { room_id = room_data[index]; }
		inline void new_zone(int index) { zone_id = zones_v[index]; }
		
	// DEBUG
		void print_story();
};


