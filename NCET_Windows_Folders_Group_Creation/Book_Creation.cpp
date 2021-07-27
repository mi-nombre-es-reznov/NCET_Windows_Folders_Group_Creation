#include "Book_Creation.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// Local Functions
void any_appendixes(void)
{
	// Local Variables
	BOOK_CREATION BOOK;
	char choice = 'a';
	int num_appendixes = 0;

	while (choice != 'y' && choice != 'n')
	{
		system("CLS");
		cout << "Does this book have any appendixes you would like to save? [Y/n]: ";
		cin >> choice;

		choice = tolower(choice);	// Makes choice a lowercase
	}

	if (choice == 'y')
	{
		while (num_appendixes < 1 || num_appendixes > 5)
		{
			system("CLS");
			cout << "How many appendixes do you want to save? ";
			cin >> num_appendixes;

			if (num_appendixes < 1 || num_appendixes > 5)
			{
				system("CLS");
				cout << "Please enter a valid number [1 - 5]" << endl;
				Sleep(1000);
				num_appendixes = 0;
			}
		}

		BOOK.set_app_val(num_appendixes);	// Sets the value of the number of saved appendixes
	}
	
	system("CLS");
}

void BOOK_CREATION::set_mappings(string PATH)
{
	// Local Variables
	char check_pts_secs;
	char check_subs;
	
	// ROOT
	set_book(); // Sets Book Name

	// Checks
	check_pts_secs = check_parts_sections();	// Checks if there are any parts or sections in book
	check_subs = check_subsections();			// Check if there are any subsections in book
	set_pts_chk(check_pts_secs);				// Assigns value to class object for check of parts or sections
	set_subs_chk(check_subs);					// Assigns value to class object for subsections

	system("CLS");
	cout << "Parts: " << check_pts_secs << endl;
	cout << "Subs: " << check_subs << endl;
	system("pause");

	// Get Appendixes
	any_appendixes();	// Checks and saves number of appendixes up to 5

	// Generate map

	// Get Parts/Sections

	// Get Chapters

	// Get Sub-Chapters

	// Create folders

	// Open PATH
}

// Sets the book name
void BOOK_CREATION::set_book(void)
{
	// Local Variable
	string get_name = "";

	while (get_name == "")
	{
		cout << "Name of Book: ";
		getline(cin, get_name);
	}

	BOOK_NAME = get_name;
}

// Gets the book name
string BOOK_CREATION::get_book(void)
{
	return BOOK_NAME;
}

// Checks if there are any Parts/Sections
char BOOK_CREATION::check_parts_sections(void)
{
	// Local Variables
	char parts_sections = 'a';
	char ps_val = 'a';

	while (parts_sections != 'n' && parts_sections != 'y')
	{
		system("CLS");
		cout << "Does " << get_book() << " have any parts or sections? [Y/n]";
		cin >> parts_sections;

		if (parts_sections == 'Y' || parts_sections == 'y' || parts_sections == 'N' || parts_sections == 'n')
		{
			parts_sections = tolower(parts_sections);
		}
		else
		{
			system("CLS");
			cout << "Please enter a valid value. [Y/n]" << endl;
			Sleep(1000);
		}
	}

	while (ps_val != 'p' && ps_val != 's')
	{
		system("CLS");
		cout << "Is this book broken up by parts or sections? [P/s]: ";
		cin >> ps_val;

		if (ps_val == 'P' || ps_val == 'p' || ps_val == 'S' || ps_val == 's')
		{
			ps_val = tolower(ps_val);
			set_pt_sec_val(ps_val);
		}
		else
		{
			system("CLS");
			cout << "Enter a valid value.[P / s]" << endl;
			Sleep(1000);
		}
	}

	return parts_sections;
}

// Checks if there are any Sub-Chapters
char BOOK_CREATION::check_subsections(void)
{
	// Local Variables
	char subs = 'a';

	while (subs != 'n' && subs != 'y')
	{
		system("CLS");
		cout << "Does " << get_book() << " have any subsections? [Y/n]";
		cin >> subs;

		if (subs == 'Y' || subs == 'y' || subs == 'N' || subs == 'n')
		{
			subs = tolower(subs);
		}
		else
		{
			system("CLS");
			cout << "Please enter a valid value. [Y/n]" << endl;
			Sleep(1000);
		}
	}

	return subs;
}

// Sets the checker for parts or sections
void BOOK_CREATION::set_pts_chk(char pts)
{
	CHECK_PARTS = pts;
}

// Gets the value for parts or sections
char BOOK_CREATION::get_pts_chk(void)
{
	return CHECK_PARTS;
}

// Sets the checker for subsections
void BOOK_CREATION::set_subs_chk(char subs)
{
	CHECK_SUBS = subs;
}

// Gets the value of the checker for subsections
char BOOK_CREATION::get_subs_chk(void)
{
	return CHECK_SUBS;
}

// Sets the parts or section value
void BOOK_CREATION::set_pt_sec_val(char val)
{
	PTS_OR_SECS = val;
}

// Gets the value of either parts or sections
char BOOK_CREATION::get_pt_sec_val(void)
{
	return PTS_OR_SECS;
}

// Sets the number appendixes to save
void BOOK_CREATION::set_app_val(int val)
{
	APP = val;
}

// Gets the saved number of appendixes
int BOOK_CREATION::get_app_val(void)
{
	return APP;
}