#include "Book_Creation.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <direct.h>
using namespace std;

void BOOK_CREATION::any_appendixes(void)
{
	// Local Variables
	char choice = 'a';
	string app_val = "";
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

		set_app_val(num_appendixes);	// Sets the value of the number of saved appendixes
	}

	for (int i = 0; i < get_app_val(); i++)
	{
		while (app_val == "")
		{
			system("CLS");
			cout << "What is the name of Appendix " << (i + 1) << "? ";
			getline(cin, app_val);
		}

		set_appendixes(app_val, i);	// Sets the value of the appendix in the array
		app_val = "";				// Reset variable
	}
	
	system("CLS");
}

void BOOK_CREATION::chaps_pps(int pos, char which)
{
	// Local Variables
	string* PS = get_parts_secs();
	int beg_chap = 0;
	int end_chap = 0;
	int tot_chaps = 0;
	string write_map = "";

	while ((beg_chap < 1 && end_chap < 1) && tot_chaps < 1)
	{
		system("CLS");

		if (which == 'p')
		{
			cout << "What are the beginning and ending chapters under Part '" << PS[pos] << "'? [beg end]: ";
		}
		else if (which == 's')
		{
			cout << "What are the beginning and ending chapters under Section '" << PS[pos] << "'? [beg end]: ";
		}

		cin >> beg_chap >> end_chap;

		tot_chaps = (end_chap - beg_chap + 1);
	}

	set_chapter_cnt(tot_chaps);														// Sets the current chapter count
	write_map = ("PS " + to_string(beg_chap) + string(":") + to_string(end_chap));	// Sets the value up to be written as a map sequence
	append_map(map_pos, write_map);													// Writes the value into mapping at current position
	map_pos += 1;																	// Update counter to reflect next part of map array, globally
}

void BOOK_CREATION::chap_names(int cnt, int sec_pos)
{
	// Local Variables
	string* SECS = get_parts_secs();
	string name;
	cin.ignore();	// To keep from duplicating and putting in one value for all Chapters

	for (int i = 0; i < cnt; i++)
	{
		system("CLS");
		
		if (get_pts_chk() == 'y')							// If parts/sections exists
		{
			while (name == "")
			{
				cout << "Under '" << SECS[sec_pos] << "', what is the name of Chapter " << (i + 1) << "? ";
				getline(cin, name);
			}
		}
		else if (get_pts_chk() == 'n')					// If there are no parts/sections
		{
			while (name == "")
			{
				cout << "What is the name of Chapter " << (i + 1) << "? ";
				getline(cin, name);
			}
		}

		name = (to_string(i + 1) + ") " + name);		// Assigns a number to the Chapter variable
		set_chapters(name, curr_chap_cnt);				// Writes chapter name to Chapters array
		curr_chap_cnt += 1;								// Updates the position counter for chapters
		name = "";										// Reset cin value to avoid first input being all input for loop
	}
}

bool validity(void)
{
	// Local Variables
	char valid = 'a';

	while (valid != 'y' && valid != 'n')
	{
		system("CLS");
		cout << "Was the displayed data accurate? [Y/n]: ";
		cin >> valid;
	}

	if (valid == 'y')
		return true;
	else if (valid == 'n')
		return false;
}

void BOOK_CREATION::set_mappings(string PATH)
{
	// Local Variables
	char check_pts_secs;
	char check_subs;
	string part_name;
	string* Parts = get_parts_secs();
	string* CHAPS = get_chapters();
	string expl = "explorer ";			// Used to concatenate strings to open final path
	bool verified;						// Used to determine folder creation

	// ROOT
	set_book(); // Sets Book Name

	// Checks
	check_pts_secs = check_parts_sections();	// Checks if there are any parts or sections in book
	check_subs = check_subsections();			// Check if there are any subsections in book
	set_pts_chk(check_pts_secs);				// Assigns value to class object for check of parts or sections
	set_subs_chk(check_subs);					// Assigns value to class object for subsections

	// Get Appendixes
	any_appendixes();	// Checks and saves number of appendixes up to 5

	cin.ignore();		// To avoid a cin override -- unwanted behavior
	// Get Parts/Sections
	if (get_pts_chk() == 'y')
	{
		for (int i = 0; i < get_section_value(); i++)
		{
			if (get_pt_sec_val() == 'p')
			{
				cout << get_book() << "'s Part " << (i + 1) << " name: ";
				getline(cin, part_name);
			}
			else if (get_pt_sec_val() == 's')
			{
				cout << get_book() << "'s Section " << (i + 1) << " name: ";
				getline(cin, part_name);
			}

			part_name = (to_string(i + 1) + ") " + part_name);	// Assigns a number to the Part/Section variable

			set_parts_secs(i, part_name);
		}
	}

	// Generate Map
	if (get_pts_chk() == 'y') // Checks if there are any parts or sections
	{
		// Check if there are any sub-sections -- YES
		if (get_subs_chk() == 'y')
		{
			for (int i = 0; i < get_section_value(); i++)		// For every part or section...
			{
				// Ask how many chapters per part or section
				chaps_pps(i, get_pt_sec_val());		// Sets up data and writes mapping information
				chap_names(get_chapter_cnt(), i);	// Allows for user to input chapter names under sections
			}

			for (int i = 0; i < get_chapter_cnt(); i++)			// For every chapter...
			{
				// Ask how many sub-sections per chapter
				subs_chaps(i);
				sub_names(get_subs_cnt(), i);
			}
		}
		// Check if there are any sub-sections -- NO
		else if (get_subs_chk() == 'n')
		{
			for (int i = 0; i < get_section_value(); i++)
			{
				// Ask how many chapters per part or section
				chaps_pps(i, get_pt_sec_val());	// Sets up data and writes mapping information
				chap_names(get_chapter_cnt(), i);	// Allows for user to input chapter names under sections
			}
		}
	}
	else if (get_pts_chk() == 'n')
	{
		// Check if there are any sub-sections -- YES
		if (get_subs_chk() == 'y')
		{
			// Ask for names of chapters
			chaps_no_pps();						// Sets up data and writes mapping information
			chap_names(get_chapter_cnt(), -1);	// Allows for user to input chapter names under sections

			// Get the names of each sub-chapter
			for (int i = 0; i < get_chapter_cnt(); i++)			// For every chapter...
			{
				// Ask how many sub-sections per chapter
				subs_chaps(i);
				sub_names(get_subs_cnt(), i);
			}
		}
		// Check if there are any sub-sections -- NO
		else if (get_subs_chk() == 'n')
		{
			// Ask for names of chapters
			chaps_no_pps();						// Sets up data and writes mapping information
			chap_names(get_chapter_cnt(), -1);	// Allows for user to input chapter names under sections
		}
	}

	// Test mappings
	//test_mappings();

	// Show mappings and verify
	verified = verify_mappings();

	// Create folders
	if (verified == true)
		create_folders(PATH);						// Create folders for book
	else if (verified == false)
		cout << "Files failed to create due to accuracy error!" << endl;
	else
	{
		cout << "Something went wrong. Check the code!!!" << endl;
		Sleep(2000);
	}

	// Open PATH
	string tmp = (expl + PATH);
	system(tmp.c_str());
}

// Sets the book name
void BOOK_CREATION::set_book(void)
{
	// Local Variable
	string get_name = "";

	while (get_name == "")
	{
		cin.ignore();
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
	int num_val = 0;

	while (parts_sections != 'n' && parts_sections != 'y')
	{
		system("CLS");
		cout << "Does '" << get_book() << "' have any parts or sections? [Y/n]";
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

	while ((ps_val != 'p' && ps_val != 's') && (parts_sections == 'y'))
	{
		system("CLS");
		cout << "Is this book broken up by parts or sections? [P/s]: ";
		cin >> ps_val;

		if (ps_val == 'P' || ps_val == 'p' || ps_val == 'S' || ps_val == 's')
		{
			ps_val = tolower(ps_val);
			set_pt_sec_val(ps_val);

			// Get quantity of sections/parts
			if(ps_val == 'p')
				set_section_value("Parts");

			if (ps_val == 's')
				set_section_value("Sections");
		}
		else
		{
			system("CLS");
			cout << "Enter a valid value.[P/s]" << endl;
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
		cout << "Does '" << get_book() << "' have any subsections? [Y/n]";
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

// Sets the number of parts/section
void BOOK_CREATION::set_section_value(string choice)
{
	// Local Variable
	char num_secs = 'a';

	while (num_secs == 'a')
	{
		system("CLS");
		cout << "How many " << choice << " are in '" << get_book() << "': ";
		cin >> num_secs;
		system("CLS");	// Clear the screen before running conditional

		if (isdigit(num_secs) != 0)
		{
			cout << "Input accepted as: " << num_secs;
			Sleep(200);
		}
		else
		{
			cout << "Input is not valid! Enter a valid number (1 - 9)" << endl;
			Sleep(1000);
			num_secs = 0;
		}
	}

	PARTS_SECS_CNT = int(num_secs - 48);
}

// Gets the number of parts/section
int BOOK_CREATION::get_section_value(void)
{
	return PARTS_SECS_CNT;
}

// Appends the Parts/Sections array with a new string value
void BOOK_CREATION::set_parts_secs(int pos, string new_val)
{
	PART_SECTION[pos] = new_val;
}

// Returns the Parts/Section array as a pointer
string* BOOK_CREATION::get_parts_secs(void)
{
	return PART_SECTION;
}

// Sets the number of chapters in the book
void BOOK_CREATION::set_chapter_cnt(int count)
{
	CHPTRS = count;
}

// Gets the number of chapters in the book
int BOOK_CREATION::get_chapter_cnt(void)
{
	return CHPTRS;
}

// Sets the number of sub-chapters in the book
void BOOK_CREATION::set_subs_cnt(int count)
{
	SUBS = count;
}

// Gets the number of sub-chapters in the book
int BOOK_CREATION::get_subs_cnt(void)
{
	return SUBS;
}

// Sets current subs array value for sub-chapters
void BOOK_CREATION::set_curr_subs(int curr)
{
	CURR_SUBS = curr;
}

// Gets last used array value for sub-chapters
int BOOK_CREATION::get_curr_subs(void)
{
	return CURR_SUBS;
}

// Adds a formatted string to the map array
void BOOK_CREATION::append_map(int pos, string value)
{
	MAP[pos] = value;
}

// Returns the map array
string* BOOK_CREATION::get_map(void)
{
	return MAP;
}

// Inserts a value into the chapters array
void BOOK_CREATION::set_chapters(string value, int pos)
{
	CHAPTERS[pos] = value;
}

// Returns the chapters array
string* BOOK_CREATION::get_chapters(void)
{
	return CHAPTERS;
}

// Inserts a value into the sub-chapter array
void BOOK_CREATION::set_subs(int pos, string setter)
{
	SUB_CHPTRS[pos] = setter;
}

// Gets the array of sub-chapters
string* BOOK_CREATION::get_subs(void)
{
	return SUB_CHPTRS;
}

// Gathers the necessary data to map the sub-chapters according to the chapters infomration
void BOOK_CREATION::subs_chaps(int pos)
{
	// Local Variables
	string* CH = get_chapters();
	int beg_sub = 0;
	int end_sub = 0;
	int tot_subs = 0;
	string write_map = "";

	while ((beg_sub < 1 && end_sub < 1) && tot_subs < 1)
	{
		system("CLS");
		cout << "What are the global beginning and ending numbers for sub-chapters under Part '" << CH[pos] << "'? [beg end]: ";

		cin >> beg_sub >> end_sub;

		tot_subs = (end_sub - beg_sub + 1);
	}

	set_subs_cnt(tot_subs);															// Sets the current chapter count
	write_map = ("CH " + to_string(beg_sub) + string(":") + to_string(end_sub));	// Sets the value up to be written as a map sequence
	append_map(map_pos, write_map);													// Writes the value into mapping at current position
	map_pos += 1;																	// Update counter to reflect next part of map array, globally
}

// Gets the names of the sub-chapters per chapter
void BOOK_CREATION::sub_names(int cnt, int chap_pos)
{
	// Local Variables
	string* CHAPS = get_chapters();
	string name = "";
	cin.ignore();	// To keep from duplicating and putting in one value for all Chapters

	for (int i = 0; i < cnt; i++)
	{
		system("CLS");

		while (name == "")
		{
			cout << "Under '" << CHAPS[chap_pos] << "', what is the name of sub-chapter " << (chap_pos + 1) << ":" << (i + 1) << "? ";
			getline(cin, name);
		}

		name = (to_string(i + 1) + ") " + name);		// Assigns a number to the Sub-Section variable
		set_subs(curr_sub_cnt, name);					// Writes chapter name to Chapters array
		curr_sub_cnt += 1;								// Updates the position counter for chapters
		name = "";										// Reset cin value to avoid first input being all input for loop
	}
}

// NO PPS - Chapter name gathering
void BOOK_CREATION::chaps_no_pps(void)
{
	// Local Variables
	int tot_chaps = 0;
	string write_map = "";

	while (tot_chaps < 1)
	{
		system("CLS");
		cout << "How many total chapters are there in '" << get_book() << "'? ";
		cin >> tot_chaps;
	}

	set_chapter_cnt(tot_chaps);	// Sets the current chapter count
}

// Sets the names of appendixes
void BOOK_CREATION::set_appendixes(string val, int pos)
{
	APPENDIXES[pos] = val;
}

// Gets the array of appendixes
string* BOOK_CREATION::get_appendixes(void)
{
	return APPENDIXES;
}

// Test map output
void BOOK_CREATION::test_mappings(void)
{
	string* PART_SECTION = get_parts_secs();
	string* CHAPTERS = get_chapters();
	string* APPENDIXES = get_appendixes();
	string* SUB_CHPTRS = get_subs();
	string* MAP = get_map();

	// Map
	for (int i = 0; i < 50; i++)
	{
		if(MAP[i] != "")
			cout << "Mapping " << (i + 1) << ": " << MAP[i] << endl;
	}

	// Parts or sections
	for (int i = 0; i < 9; i++)
	{
		if (PART_SECTION[i] != "")
			cout << "PS Value " << (i + 1) << ": " << PART_SECTION[i] << endl;
	}

	// Appendixes
	for (int i = 0; i < 5; i++)
	{
		if (APPENDIXES[i] != "")
			cout << "Appendixes " << (i + 1) << ": " << APPENDIXES[i] << endl;
	}

	// Chapters
	for (int i = 0; i < 50; i++)
	{
		if (CHAPTERS[i] != "")
			cout << "Chapters " << (i + 1) << ": " << CHAPTERS[i] << endl;
	}

	// Sub-chapters
	for (int i = 0; i < 300; i++)
	{
		if (SUB_CHPTRS[i] != "")
			cout << "Sub-Chapters " << (i + 1) << ": " << SUB_CHPTRS[i] << endl;
	}

	system("pause");
}

// Verify mapping Core Function
bool BOOK_CREATION::verify_mappings(void)
{
	// Local Variables
	bool verify = false;
	int curr_ps = 0;
	int curr_chap = 0;
	string* M = get_map();
	string curr_map_item = "";
	string cat = "";
	string num_data = "";
	int num_pages = 0;
	int page_start = 0;
	int page_end = 0;
	size_t splitter;
	string temp = "";
	int range = 0;
	string arr_data = "";
	string* PART_SECTION = get_parts_secs();
	string* CHAPTERS = get_chapters();
	string* APPENDIXES = get_appendixes();
	string* SUB_CHPTRS = get_subs();
	string* MAP = get_map();

	// Get map value
	for (int i = 0; i < map_pos; i++)
	{
		curr_map_item = M[i];								// Get each item
		cat = curr_map_item.substr(0, 2);					// Set category keyword
		splitter = curr_map_item.find(" ");					// Split category and num data
		num_data = curr_map_item.substr(splitter + 1);		// Splits at " "
		splitter = num_data.find(":");						// Looks for splitting key
		page_start = stoi(num_data.substr(0, splitter));	// Gets the beginning value
		page_end = stoi(num_data.substr(splitter + 1));		// Gets the ending value
		system("CLS");										// Clear screen for presentation to user

		// First two letters contain 'PS' -- Has Part or Section
		if (cat == "PS")
		{
			cout << "Sections/Parts Data" << endl;
			cout << "-------------------" << endl;
			arr_data = PART_SECTION[ver_PS_val];
			ver_PS_val += 1;	// Update global counter

			cout << arr_data << endl;

			// Get chapter data
			range = (page_end - page_start + 1);	// Gets the range of chapters under Part or Section

			cout << "\nChapters Data" << endl;
			cout << "--------------" << endl;

			// Get Chapter data
			for (int i = 0; i < range; i++)
			{
				cout << "\t" << CHAPTERS[page_start + i - 1] << endl;	// Display Chapters
			}
		}
		else if (cat == "CH")
		{
			cout << "\nChapters Data" << endl;
			cout << "--------------" << endl;
			arr_data = CHAPTERS[ver_CHAPS];
			ver_CHAPS += 1;	// Update global counter

			cout << arr_data << endl;

			// Get chapter data
			range = (page_end - page_start + 1);	// Gets the range of Sub-Chapters under Chapters

			cout << "\nSub-Chapters Data" << endl;
			cout << "-------------" << endl;

			// Get Chapter data
			for (int i = 0; i < range; i++)
			{
				cout << "\t" << SUB_CHPTRS[page_start + i - 1] << endl;	// Display Sub-Chapters
			}
		}

		system("pause");
	}

	verify = validity(); // Verify accuracy for creation


	return verify;
}

// Creates all folders
void BOOK_CREATION::create_folders(string PATH)
{
	// Local Variables
	string path_ps;
	string path_ps_chap;
	string path_subs;
	ver_PS_val = 0;						// RESET Current PS val
	ver_CHAPS = 0;						// RESET Current Chapters value
	int curr_ps = 0;
	int curr_chap = 0;
	string* M = get_map();
	string curr_map_item = "";
	string cat = "";
	string num_data = "";
	int num_pages = 0;
	int page_start = 0;
	int page_end = 0;
	size_t splitter;
	string temp = "";
	int range = 0;
	string arr_data = "";
	string* PART_SECTION = get_parts_secs();
	string* CHAPTERS = get_chapters();
	string* APPENDIXES = get_appendixes();
	string* SUB_CHPTRS = get_subs();

	// Create book folder
	string book_folder = (PATH + "/" + get_book());

	if (_mkdir(book_folder.c_str()) == 0)
	{
		cout << "Book folder created!" << endl;
		Sleep(200);
	}
	else
	{
		system("CLS");
		cout << "Book folder failed to create!" << endl;
		Sleep(1000);
	}

	// Get map value
	for (int i = 0; i < map_pos; i++)
	{
		curr_map_item = M[i];								// Get each item
		cat = curr_map_item.substr(0, 2);					// Set category keyword
		splitter = curr_map_item.find(" ");					// Split category and num data
		num_data = curr_map_item.substr(splitter + 1);		// Splits at " "
		splitter = num_data.find(":");						// Looks for splitting key
		page_start = stoi(num_data.substr(0, splitter));	// Gets the beginning value
		page_end = stoi(num_data.substr(splitter + 1));		// Gets the ending value
		system("CLS");										// Clear screen for presentation to user

		// Write appendixes to folders
		if (get_app_val() > 0)
		{
			// Make appendixes folder
			string make_app_folder = (PATH + "/" + get_book() + "/Appendixes");

			if (_mkdir(make_app_folder.c_str()) == 0)
			{
				cout << "Appendixes folder created!" << endl;
				Sleep(200);
			}
			else
			{
				cout << "Appendixes folder failed to create!" << endl;
			}

			// Create all appendixes folders
			for (int i = 0; i < get_app_val(); i++)
			{
				string app_curr = APPENDIXES[i];
				string path_app = (PATH + "/" + get_book() + "/Appendixes/" + app_curr);

				if (_mkdir(path_app.c_str()) == 0)
				{
					cout << "'" << app_curr << "' created!" << endl;
					Sleep(200);
				}
				else
				{
					cout << "'" << app_curr << "' failed to create!" << endl;
				}
			}
		}

		// First two letters contain 'PS' -- Has Part or Section
		if (cat == "PS")
		{
			arr_data = PART_SECTION[ver_PS_val];								// Pull current Part/Section value
			path_ps = (PATH + "/" + get_book() + "/" + arr_data);				// Part/Section Path
			ver_PS_val += 1;	// Update global counter

			if (_mkdir(path_ps.c_str()) == 0)
			{
				cout << "'" << arr_data << "' created!" << endl;
				Sleep(200);
			}
			else
			{
				cout << "'" << arr_data << "' failed to create!" << endl;
			}

			// Get chapter data
			range = (page_end - page_start + 1);	// Gets the range of chapters under Part or Section

			// Get Chapter data
			for (int i = 0; i < range; i++)
			{
				string curr_chap = CHAPTERS[page_start + i - 1];
				path_ps_chap = (PATH + "/" + get_book() + "/" + arr_data + "/" + curr_chap);

				if (_mkdir(path_ps_chap.c_str()) == 0)
				{
					cout << "'" << curr_chap << "' created!" << endl;
					Sleep(200);
				}
				else
				{
					cout << "'" << curr_chap << "' failed to create!" << endl;
				}
			}
		}
		else if (cat == "CH")
		{
			arr_data = CHAPTERS[ver_CHAPS];
			ver_CHAPS += 1;	// Update global counter
			path_ps_chap = (PATH + "/" + get_book() + "/" + arr_data);

			if (_mkdir(path_ps_chap.c_str()) == 0)
			{
				cout << "'" << arr_data << "' created!" << endl;
				Sleep(200);
			}
			else
			{
				cout << "'" << arr_data << "' failed to create!" << endl;
			}

			// Get sub-chapter data
			range = (page_end - page_start + 1);	// Gets the range of Sub-Chapters under Chapters

			// Get Chapter data
			for (int i = 0; i < range; i++)
			{
				cout << "\t" << SUB_CHPTRS[page_start + i - 1] << endl;	// Display Sub-Chapters
				string subies = SUB_CHPTRS[page_start + i - 1];
				path_subs = (PATH + "/" + get_book() + "/" + arr_data + "/" + subies);

				if (_mkdir(path_subs.c_str()) == 0)
				{
					cout << "'" << subies << "' created!" << endl;
					Sleep(200);
				}
				else
				{
					cout << "'" << subies << "' failed to create!" << endl;
				}
			}
		}
	}
}