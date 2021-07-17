#include "New_User.h"
#include <iostream>
#include <string>
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

void New_User::generate_folders_maps(string main_path)
{
	// Local variables
	string name = "";		// User-defined name
	string* CORE;			// Core Data Array
	string* C_DATA;			// Course Data Array
	string* C_INFO;			// Course Info Array
	string* NCET;			// NCET Data Array
	string* AGREEMENT;		// Agreement Array
	string* BILLING;		// Billing Array

	set_tutee();			// Sets tutee name
	name = get_tutee();		// Pulls tutee name from private class

	system("CLS");
	cout << "User gave name: " << name << endl;
	system("pause");

	system("CLS");
	CORE = get_course_data();

	for (int i = 0; i < 4; i++)
	{
		cout << CORE[i] << endl;
	}

	// Create CORE folders within tutee folder

	// Create COURSE DATA folders

	// Create COURSE INFO folders

	// Create NCET DATA folders

	// Create AGREEMENT folders

	// Create BILLING folders

	system("pause");

	// Open PATH
	system("explorer C:\\Users\\06878\\Pictures\\Camera Roll\\");
}

string* New_User::get_course_data(void)
{
	return CORE_DATA;
}