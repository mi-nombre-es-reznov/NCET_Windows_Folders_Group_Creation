#include "New_Month_YT.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void NEW_MONTH_YT::generate_mappings(string path)
{
	// Local Variables
	string month;
	
	// Get month to use as encompassing folder
	set_month();
	month = get_month();

	system("CLS");
	cout << "Month selected: " << month << endl;
	system("pause");

	// Create gaming days folders - 'Saturdays' & 'Sundays'

	// Get number of Saturdays and Sundays for the month selected

	// Get the dates from each day

	// Append the game template to each date

	// Create folders from map

	// Generate subfolders for each day in posting month

	// Open folder once completed
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