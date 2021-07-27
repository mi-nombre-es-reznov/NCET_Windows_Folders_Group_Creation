/* 
	Name: NCET_Windows_Folders_Group_Creation
	Author: Nicholas Perez-Aguilar
	Company: NCompEng Technologies
	Date of Start: 13 July 2021
*/

// Pre-processors
#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <Windows.h>
#include "New_User.h"
#include "New_Month_YT.h"
#include "Book_Creation.h"
using namespace std;

// Global Values
string GROUPS[3] = {"Book", "New Tutee", "Monthly Gaming"};
string TEST = "/TEST";
string PATH;

// Function Declarations
void test_file_directory(void);
int select_group(void);

int main()
{
	// Class Objects
	New_User user;
	NEW_MONTH_YT YT;
	BOOK_CREATION BC;

	// Local Variables
	int group_choice = -1;

	test_file_directory();	// Test user-given path
	group_choice = select_group();	// User-selects folder creation option
	system("CLS");	// Clear screen before entering options functions

	// Choice mappings
	if (group_choice == 0)
	{
		BC.set_mappings(PATH);
	}
	else if (group_choice == 1)
	{
		user.generate_folders_maps(PATH);
	}
	else if (group_choice == 2)
	{
		YT.generate_mappings(PATH);
	}
	else
	{
		cout << "An internal error occurred!!!\nPlease try to rerun the program after checking the code!" << endl;
	}

	system("CLS");
	cout << "NCompEng Technologies thanks you for using NCET Windows Folders Group Creation Application." << endl;
	system("pause");
	return 0;
}

// Test add/delete file from user-given path.
void test_file_directory(void)
{
	// local variable
	string path;
	string path_app;
	int valid = -1;

	while (valid != 0)
	{
		system("CLS"); // Ensure that the screen is only showing the question for the path.
		cout << "Local Path to Test: ";
		cin >> path;

		path_app += TEST; // Append Test folder to path

		valid = _mkdir(path_app.c_str());

		if (valid == 0)
		{
			system("CLS");
			cout << "Path test passed!" << endl;
			Sleep(1000);
			system("CLS");
			cout << "Deleting test folder" << endl;
			Sleep(1000);
			if (_rmdir(path_app.c_str()) == 0)
			{
				system("CLS");
				cout << "Test folder deleted successfully!" << endl;
				Sleep(1000);
				PATH = path;	// Assign global PATH the user-input path
			}
		}
		else
		{
			system("CLS");
			cout << "Path test Failed!\nEnter a valid local path." << endl;
			Sleep(1000);
		}
	}
}

// Allow a user to select which folder group they want to create
int select_group(void)
{
	// Local Variables
	int num_choices = sizeof(GROUPS) / sizeof(GROUPS[0]);
	int valid_choice = -1;
	char test;	// Only allows numbers 0 -> 9 for input. Convert to string if array GROUPS exceeds 10+

	while (valid_choice < 1 || valid_choice > num_choices)
	{
		system("CLS");

		for (int i = 0; i < num_choices; i++)
		{
			cout << (i + 1) << ") " << GROUPS[i] << endl;
		}

		cout << "\nSelect an group to begin: ";
		cin >> test;	// Only accepts 1 character value.

		// Verify input is a number
		if (isdigit(test) == 0)
		{
			valid_choice = -1;
		}
		else
		{
			valid_choice = int(test);
			valid_choice -= 48;	// Subtract out ASCII char value of 48 for numbers.
		}

		system("CLS"); // Clear screen for feedback

		if (valid_choice < 1 || valid_choice > num_choices)
		{
			cout << "Answer choice is invalid\nEnter a valid group to begin." << endl;
			valid_choice = -1;
		}

		Sleep(1000);
	}

	valid_choice -= 1;	// Set up to pull directly from array of GROUPS

	return valid_choice;
}