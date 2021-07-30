#pragma once
#ifndef BOOK_CREATION_H
#define BOOK_CREATION_H
#include <string>
using namespace std;

class BOOK_CREATION
{
private:
	string BOOK_NAME;
	string PART_SECTION[9];
	string CHAPTERS[50];
	string APPENDIXES[5];
	string SUB_CHPTRS[300];
	string MAP[50];
	int CURR_SUBS = 0;
	int GET_PRTS_SECS_CNT = 0;
	int PARTS_SECS_CNT = 0;
	int APP = 0;
	int CHPTRS = 0;
	int SUBS = 0;
	char CHECK_PARTS = 'a';
	char CHECK_SUBS = 'a';
	char PTS_OR_SECS = 'a';
public:
	// Book Functions
	void set_book(void);					// Sets the title of the book
	string get_book(void);					// Gets the title of the book

	// Checking methods
	char check_parts_sections(void);		// Checks if there are any parts or sections
	char check_subsections(void);			// Checks if there are any subsections
	void set_pts_chk(char);					// Sets the value for parts/sections check value
	char get_pts_chk(void);					// Gets the value for parts/sections check value
	void set_subs_chk(char);				// Sets value for subsections check
	char get_subs_chk(void);				// Gets value for subsections check

	// Setters and Getters
	void set_pt_sec_val(char);				// Sets the value of parts or sections
	char get_pt_sec_val(void);				// Gets the value of parts or sections
	void set_parts_secs(int, string);		// Sets the parts/sections array
	string* get_parts_secs(void);			// Get the parts/sections array
	void set_chapters(string, int);			// Set the chapters array
	string* get_chapters(void);				// Get the chapters array
	void set_subs(int, string);				// Set the sub-chapters array
	string* get_subs(void);					// Get the sub-chapters array
	void set_appendixes(string, int);		// Set the appendixes array
	string* get_appendixes(void);			// Get the appendixes array
	void set_app_val(int);					// Set the appendixes value
	int get_app_val(void);					// Get the apendixes value
	void set_section_value(string);			// Sets the number of parts or sections
	int get_section_value(void);			// Gets the number of parts or sections
	void set_chapter_cnt(int);				// Sets the number of chapters in the book
	int get_chapter_cnt(void);				// Gets the number of chapters in the book
	void set_subs_cnt(int);					// Sets the number of sub-chapters
	int get_subs_cnt(void);					// Gets the number of sub-chapters
	void set_pps(void);						// Sets the number of parts per section
	void set_curr_subs(int);				// Sets the current substitution value in array
	int get_curr_subs(void);				// Gets the current substitution value in array
	void append_map(int, string);			// Adds formatted string value to mappings array
	string* get_map(void);					// Gets the current mappings for all values in mappings array

	// Main Functions
	void set_mappings(string);				// Create the main function roadmap
	void create_folders(void);				// Create the folders from mapping

	// Mapping Functions
	void chaps_pps(int, char);				// Allows for the gathering and traversing of data, and writing of chapters with part or section
	void chap_names(int, int);				// Gets the chapters names and puts them in the CHPTRS array
	void subs_chaps(int);					// Allows for the gathering and traversing of data, and writing of sub-chapters
	void sub_names(int, int);				// Gets the sub-chapter names and puts them in the SUB_CHPTRS array
	void chaps_no_pps(void);				// Allows for gathering and traversing of data, and writing of data with NO part or section
	void any_appendixes(void);				// Appendix creation
	void test_mappings(void);				// Test what map returns

	// Variables
	int map_pos = 0;						// Holds the current value of the mapping position
	int curr_chap_cnt = 0;					// Holds the current value of the chapter position
	int curr_sub_cnt = 0;					// Holds the current writing of the sub-chapter position
};

#endif // !BOOK_CREATION_H