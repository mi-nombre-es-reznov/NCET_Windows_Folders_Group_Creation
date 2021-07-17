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
	

	// Create CORE folders within tutee folder

	// Create COURSE DATA folders

	// Create COURSE INFO folders

	// Create NCET DATA folders

	// Create AGREEMENT folders

	// Create BILLING folders

	system("pause");

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