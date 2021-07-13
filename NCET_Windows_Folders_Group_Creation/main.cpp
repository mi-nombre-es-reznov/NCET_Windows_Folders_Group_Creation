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
using namespace std;

// Global Values
string TEST = "/TEST";
string PATH;

// Function Declarations
void test_file_directory(void);

int main()
{
	test_file_directory();

	system("pause");
	return 0;
}

// Test add/delete file from user-given path.
void test_file_directory(void)
{
	// local variable
	string path = "";
	int valid = -1;

	while (valid != 0)
	{
		system("CLS"); // Ensure that the screen is only showing the question for the path.
		cout << "Local Path to Test: ";
		cin >> path;

		path += TEST; // Append Test folder to path

		valid = _mkdir(path.c_str());

		if (valid == 0)
		{
			system("CLS");
			cout << "Path test passed!" << endl;
			Sleep(1000);
		}
		else
		{
			system("CLS");
			cout << "Path test Failed!\nEnter a valid local path." << endl;
			Sleep(1000);
		}
	}
}
