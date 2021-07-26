#pragma once
#ifndef NEW_MONTH_YT_H
#define NEW_MONTH_YT_H

// Preprocessors
#include <string>
using namespace std;

class NEW_MONTH_YT
{
private:
	// Core Content
	string final_month;																					// Holds current month 
	int num_d1 = 0;																						// Holds the number of days in the month for day 1
	int num_d2 = 0;																						// Holds the number of days in the month for day 2
	int num_d3 = 0;																						// Holds the number of days in the month for day 3
	string d1_name[5] = { "0", "0", "0", "0", "0" };													// Holds the name of the day in the month for day 1
	string d2_name[5] = { "0", "0", "0", "0", "0" };													// Holds the name of the day in the month for day 2
	string d3_name[5] = { "0", "0", "0", "0", "0" };													// Holds the name of the day in the month for day 3
	string sub_folders[3] = { "Completed Content", "Working Directory", "Socials and YT Documents" };	// Holds the subfolders that go into every assigned folder
	string month_select[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };	// Holds all months in a year

	// Gaming Content
	string Gaming_days[2] = { "Saturdays", "Sundays" };								// Holds days to publish gaming content
	int Gaming_days_size = (sizeof(Gaming_days) / sizeof(Gaming_days[0]));			// Holds the size of the days for gaming content
	int Gaming_sub_folders_size = (sizeof(sub_folders) / sizeof(sub_folders[0]));	// Holds the size of the subfolders for the gaming content
	string game_concate = " - [Game Type]";											// Holds the ending of the folder name for gaming content
public:
	// Auxillary Functions
	void set_month(void);			// Sets the current month
	string get_month(void);			// Gets the current month
	void set_num_d1(int);			// Sets the number of days in the month for Day 1
	void set_num_d2(int);			// Sets the number of days in the month for Day 2
	void set_num_d3(int);			// Sets the number of days in the month for Day 3
	int get_num_d1(void);			// Gets the number of days in the month for Day 1
	int get_num_d2(void);			// Gets the number of days in the month for Day 2
	int get_num_d3(void);			// Gets the number of days in the month for Day 3
	void set_d1_name(int);			// Sets the name of the day in the month for Day 1
	void set_d2_name(int);			// Sets the name of the day in the month for Day 2
	void set_d3_name(int);			// Sets the name of the day in the month for Day 3
	string* get_d1_name(void);		// Gets the name of the day in the month for Day 1
	string* get_d2_name(void);		// Gets the name of the day in the month for Day 2
	string* get_d3_name(void);		// Gets the name of the day in the month for Day 3
	string* get_subs(void);			// Get subfolder content

	// Core Functions
	void generate_mappings(string);	// Generate mappings for the folders for the month
	void create_folders(string);	// Create the folders from the mappings

	// Gaming Functions
	string get_game_concate(void);	// Get Ending to folder name for gaming content
	string* get_game_days(void);	// Get gaming days array
	int get_game_size(void);		// Get size of gaming days array
	int get_game_subs_size(void);	// Get size of gaming sub folders array
};

#endif // !NEW_MONTH_YT_H