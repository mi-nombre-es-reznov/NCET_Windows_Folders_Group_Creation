#pragma once
#ifndef BOOK_CREATION_H
#define BOOK_CREATION_H

class BOOK_CREATION
{
private:
	string BOOK_NAME;
	string PART_SECTION[10] = { "", "", "", "", "", "", "", "", "", "" };
	string CHAPTERS[50] = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
	string APPENDIXES[5] = { "", "", "", "", "" };
	string SUB_CHPTRS[100] = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
	string MAP[50];
	int GET_PRTS_SECS_CNT = 0;
	int PARTS_SECS_CNT = 0;
	int APP = 0;
	int CHPTRS = 0;
	int SUBS = 0;
	char CHECK_PARTS;
	char CHECK_SUBS;
	char PTS_OR_SECS;
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
	void set_pt_sec_val(char);				// Sets the value if parts or sections
	char get_pt_sec_val(void);				// Gets the value if parts or sections
	void set_parts_secs(string);			// Sets the parts/sections array
	string* get_parts_secs(void);			// Get the parts/sections array
	void set_chapters(string);				// Set the chapters array
	string* get_chapters(void);				// Get the chapters array
	void set_subs(string);					// Set the sub-chapters array
	string* get_subs(void);					// Get the sub-chapters array
	void set_appendixes(string);			// Set the appendixes array
	string* get_appendixes(void);			// Get the appendixes array
	void set_app_val(int);					// Set the appendixes value
	int get_app_val(void);					// Get the apendixes value

	// Main Functions
	void set_mappings(string);				// Create the main function roadmap
	void create_folders(void);				// Create the folders from mapping
};

#endif // !BOOK_CREATION_H