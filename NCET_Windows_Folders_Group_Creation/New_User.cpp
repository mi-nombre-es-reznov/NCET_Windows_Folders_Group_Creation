#include "New_User.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <direct.h>
using namespace std;

void New_User::set_tutee(void)
{
	// Local variables
	string name = "";

	while (name == "")
	{
		system("CLS");
		cout << "Name of Tutee: ";
		cin >> name;
	}

	tutee = name;	// Set the variable in the private class.
}

string New_User::get_tutee(void)
{
	return tutee;
}

void New_User::generate_path_locations(string path, string inter, string core)
{
	// Local Variables
	string full_path = "";
	int valid = -1;

	// Create full path
	if (inter == "")
	{
		full_path = (path + "/" + core);
	}
	else
	{
		full_path = (path + "/" + inter + "/" + core);
	}

	// Generate the folder
	while (valid != 0)
	{
		system("CLS"); // Ensure that the screen is only showing the question for the path.

		valid = _mkdir(full_path.c_str());

		if (valid != 0)
		{
			system("CLS");
			cout << "Folder Creation Failed!" << endl;
			Sleep(1000);
		}
	}
}

void New_User::generate_folders_maps(string main_path)
{
	// Local variables
	string name = "";			// User-defined name
	string expl = "explorer ";	// Used to concatenate strings to open final path
	string* CORE;				// Core Data Array
	string* C_DATA;				// Course Data Array
	string* C_INFO;				// Course Info Array
	string* NCET;				// NCET Data Array
	string* AGREEMENT;			// Agreement Array
	string* BILLING;			// Billing Array

	set_tutee();			// Sets tutee name
	name = get_tutee();		// Pulls tutee name from private class

	// Gather all folder arrays
	system("CLS");
	CORE = get_core_data();
	C_DATA = get_course_data();
	C_INFO = get_course_info();
	NCET = get_ncet_data();
	AGREEMENT = get_agreement();
	BILLING = get_billing();

	// Intermediate Path
	string CD = (name + "/" + CORE[0]);
	string CI = (name + "/" + CORE[0] + "/" + C_DATA[0]);
	string ND = (name + "/" + CORE[1]);
	string AG = (name + "/" + CORE[1] + "/" + NCET[0]);
	string BI = (name + "/" + CORE[1] + "/" + NCET[0] + "/" + AGREEMENT[1]);
	
	// Create Encompassing folder with Tutee info
	generate_path_locations(main_path, "", name);

	// Create CORE folders within tutee folder
	for (int i = 0; i < 4; i++)						// Core holds 4 strings
	{
		generate_path_locations(main_path, name, CORE[i]);
		cout << "CORE " << (i + 1) << " passed" << endl;
	}

	// Create COURSE DATA folders
	for (int i = 0; i < 2; i++)						// Course Data has 2 strings
	{
		generate_path_locations(main_path, CD, C_DATA[i]);
		cout << "CD " << (i + 1) << " passed" << endl;
	}

	// Create COURSE INFO folders
	for (int i = 0; i < 2; i++)						// Course Info has 2 strings
	{
		generate_path_locations(main_path, CI, C_INFO[i]);
		cout << "CI " << (i + 1) << " passed" << endl;
	}

	// Create NCET DATA folders
	for (int i = 0; i < 2; i++)						// NCET Data has 2 strings
	{
		generate_path_locations(main_path, ND, NCET[i]);
		cout << "NCET " << (i + 1) << " passed" << endl;
	}

	// Create AGREEMENT folders
	for (int i = 0; i < 2; i++)						// AGREEMENT has 2 strings
	{
		generate_path_locations(main_path, AG, AGREEMENT[i]);
		cout << "AG " << (i + 1) << " passed" << endl;
	}

	// Create BILLING folders
	for (int i = 0; i < 2; i++)						// BILLING has 2 strings
	{
		generate_path_locations(main_path, BI, BILLING[i]);
	}

	// Open PATH
	string tmp = (expl + main_path);
	system(tmp.c_str());

	system("pause");
}

// Return Core Array
string* New_User::get_core_data(void)
{
	return CORE_DATA;
}

// Return Course Data Array
string* New_User::get_course_data(void)
{
	return COURSE_DATA;
}

// Return Course Info Array
string* New_User::get_course_info(void)
{
	return COURSE_INFO;
}

// Return NCET Data Array
string* New_User::get_ncet_data(void)
{
	return NCET_DATA;
}

// Return Agreement Array
string* New_User::get_agreement(void)
{
	return AGREEMENT;
}

// Return Billing Array
string* New_User::get_billing(void)
{
	return BILLING;
}