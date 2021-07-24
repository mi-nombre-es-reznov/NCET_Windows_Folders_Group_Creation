#include "New_Month_YT.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <direct.h>
using namespace std;

// Local functions
void create_day_folders(string fp, string nf)
{
	// Local Variables
	string full_path;

	// Create encompassing folder
	system("CLS");
	full_path = (fp + "/" + nf);
	if (_mkdir(full_path.c_str()) == 0)
	{
		cout << nf << " Folder Created!" << endl;
		Sleep(1000);
	}
	else
	{
		cout << nf << " Folder Creation Failed!" << endl;
		Sleep(1000);
	}
}

void NEW_MONTH_YT::generate_mappings(string path)
{
	// Local Variables
	string expl = "explorer ";	// Used to concatenate strings to open final path
	string month;
	string full_path;
	string* Game_Days = get_game_days();
	int num_days = get_game_size();
	int day_cnt = 0;
	char test_cnt;
	
	// Get month to use as encompassing folder
	set_month();
	month = get_month();

	system("CLS");
	cout << "Month selected: " << month << endl;
	system("pause");

	// Create encompassing folder
	system("CLS");
	full_path = (path + "/" + month);
	if (_mkdir(full_path.c_str()) == 0)
	{
		cout << "Base folder created!" << endl;
		Sleep(1000);
	}
	else
	{
		cout << "Base folder creation failed!" << endl;
		Sleep(1000);
	}

	// Create gaming days folders - 'Saturdays' & 'Sundays'
	for (int i = 0; i < num_days; i++)
	{
		create_day_folders(full_path, Game_Days[i]);
	}

	// Get number of Saturdays and Sundays for the month selected
	for (int i = 0; i < num_days; i++)
	{
		while (day_cnt < 1 || day_cnt > 5)
		{
			system("CLS");
			cout << "How many " << Game_Days[i] << " are there in the month of " << month << "? ";
			cin >> test_cnt;

			if (isdigit(test_cnt) == 0)
			{
				system("CLS");
				day_cnt = 0;
				cout << "Invalid option. Select a number between 1 - 5" << endl;
				Sleep(1000);
			}
			else
			{
				day_cnt = int(test_cnt);
				day_cnt -= 48;	// Subtract out ASCII value to make it a number vs. character
				cout << "Input accepted as: " << day_cnt << endl;
				Sleep(1000);
			}
		}

		// Set num per day according to num currently on
		if (i == 0)
		{
			set_num_d1(day_cnt);
		}
		else if(i == 1)
		{
			set_num_d2(day_cnt);
		}
		else if (i == 2)
		{
			set_num_d3(day_cnt);
		}
	}

	// Get the dates from each day
	if (get_num_d1() != 0)
	{
		set_d1_name(get_num_d1());
	}
	system("pause");

	if (get_num_d2() != 0)
	{
		set_d2_name(get_num_d2());
	}
	system("pause");

	if (get_num_d3() != 0)
	{
		set_d3_name(get_num_d3());
	}
	system("pause");

	// Create folders from map

	// Generate subfolders for each day in posting month

	// Open folder once completed
	string tmp = (expl + path);
	system(tmp.c_str());
}

// Set the month
void NEW_MONTH_YT::set_month(void)
{
	// Local Variables
	string ret_month;
	int month = -1;
	char temp;

	while (month < 1 || month > 12)
	{
		system("CLS");	// Clear Screen

		cout << "Month Selection" << endl << endl;	// Title

		// Display months
		for (int i = 0; i < 12; i++)
		{
			cout << (i + 1) << ") " << month_select[i] << endl;
		}

		cout << "\nSelect month by number: ";
		cin >> ret_month;

		temp = ret_month[0];
		
		if (isdigit(int(temp)) == 0)
		{
			month = -1;
		}
		else
		{
			month = stoi(ret_month);
		}

		if (month < 1 || month > 12)
		{
			system("CLS");
			cout << "Invalid option. Select a valid number." << endl;
			Sleep(1000);
		}
	}

	month -= 1;
	ret_month = month_select[month];

	final_month = ret_month;
}

// Get the month
string NEW_MONTH_YT::get_month(void)
{
	return final_month;
}

// Get the days of game postings
string* NEW_MONTH_YT::get_game_days(void)
{
	return Gaming_days;
}

// Get the number of posting days
int NEW_MONTH_YT::get_game_size(void)
{
	return Gaming_days_size;
}

// Set the number of weeks for the first day in the month
void NEW_MONTH_YT::set_num_d1(int num1)
{
	num_d1 = num1;
}

// Set the number of weeks for the second day in the month
void NEW_MONTH_YT::set_num_d2(int num2)
{
	num_d2 = num2;
}

// Set the number of weeks for the third day in the month
void NEW_MONTH_YT::set_num_d3(int num3)
{
	num_d3 = num3;
}

// Get the number of days for day 1 in the month
int NEW_MONTH_YT::get_num_d1(void)
{
	return num_d1;
}

// Get the number of days for day 2 in the month
int NEW_MONTH_YT::get_num_d2(void)
{
	return num_d2;
}

// Get the number of days for day 3 in the month
int NEW_MONTH_YT::get_num_d3(void)
{
	return num_d3;
}

// Set the day 1 array for the month
void NEW_MONTH_YT::set_d1_name(int num_days)
{
	// Local Variables
	int day, year;
	string full_name;
	string space = " ";
	string* D1 = get_d1_name();

	for (int i = 0; i < num_days; i++)
	{
		system("CLS");
		cout << "What day and year is this folder? (day year): ";
		cin >> day >> year;

		// Concatenate folder name together
		full_name = (to_string(day) + space + get_month() + space + to_string(year) + get_game_concate());

		system("CLS");	// Clear screen for aesthetics

		// Show adding current name
		cout << "Adding to list: " << full_name << endl << endl;

		// Add new item to list
		D1[i] = full_name;

		// Show current list
		cout << "Current List\n";
		cout << "------------\n";

		for (int i = 0; i < 5; i++)	// Set to 5 because array is pre-programmed to be AT MOST 5
		{
			if (D1[i] != "0")
			{
				cout << "Week " << (i + 1) << ") " << D1[i] << endl;
			}
		}

		Sleep(3000);	// Allows user to see what is going on
		cout << endl;
	}
}

// Set the day 2 array for the month
void NEW_MONTH_YT::set_d2_name(int num_days)
{
	// Local Variables
	int day, year;
	string full_name;
	string space = " ";
	string* D2 = get_d1_name();

	for (int i = 0; i < num_days; i++)
	{
		system("CLS");
		cout << "What day and year is this folder? (day year): ";
		cin >> day >> year;

		// Concatenate folder name together
		full_name = (to_string(day) + space + get_month() + space + to_string(year) + get_game_concate());

		system("CLS");	// Clear screen for aesthetics

		// Show adding current name
		cout << "Adding to list: " << full_name << endl << endl;

		// Add new item to list
		D2[i] = full_name;

		// Show current list
		cout << "Current List\n";
		cout << "------------\n";

		for (int i = 0; i < 5; i++)	// Set to 5 because array is pre-programmed to be AT MOST 5
		{
			if (D2[i] != "0")
			{
				cout << "Week " << (i + 1) << ") " << D2[i] << endl;
			}
		}

		Sleep(3000);	// Allows user to see what is going on
		cout << endl;
	}
}

// Set the day 3 array for the month
void NEW_MONTH_YT::set_d3_name(int num_days)
{
	// Local Variables
	int day, year;
	string full_name;
	string space = " ";
	string* D3 = get_d1_name();

	for (int i = 0; i < num_days; i++)
	{
		system("CLS");
		cout << "What day and year is this folder? (day year): ";
		cin >> day >> year;

		// Concatenate folder name together
		full_name = (to_string(day) + space + get_month() + space + to_string(year) + get_game_concate());

		system("CLS");	// Clear screen for aesthetics

		// Show adding current name
		cout << "Adding to list: " << full_name << endl << endl;

		// Add new item to list
		D3[i] = full_name;

		// Show current list
		cout << "Current List\n";
		cout << "------------\n";

		for (int i = 0; i < 5; i++)	// Set to 5 because array is pre-programmed to be AT MOST 5
		{
			if (D3[i] != "0")
			{
				cout << "Week " << (i + 1) << ") " << D3[i] << endl;
			}
		}

		Sleep(3000);	// Allows user to see what is going on
		cout << endl;
	}
}

// Get game concate ending
string NEW_MONTH_YT::get_game_concate(void)
{
	return game_concate;
}

// Get day 1 in week array
string* NEW_MONTH_YT::get_d1_name(void)
{
	return d1_name;
}

// Get day 2 in week array
string* NEW_MONTH_YT::get_d2_name(void)
{
	return d2_name;
}

// Get day 3 in week array
string* NEW_MONTH_YT::get_d3_name(void)
{
	return d3_name;
}