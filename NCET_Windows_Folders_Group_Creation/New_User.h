#pragma once
#ifndef NEW_USER_H
#define NEW_USER_H

// Pre-processors
#include <string>
using namespace std;

class New_User
{
private:
	// Class Variables
	string tutee;
	string CORE_DATA[4] = { "1) Course Data", "2) NCET Data", "3) Book Data", "4) Lessons" };	// Under encompassing folder (user name)
	string COURSE_DATA[2] = { "1) Course Information", "2) Course Lessons" };				// Main data folder COURSE DATA
	string COURSE_INFO[2] = { "1) Syllabus", "2) Supplemental Material" };					// COURSE DATA -> COURSE INFO
	string NCET_DATA[2] = { "1) Agreement", "2) Time Clock" };								// Main data folder	NCET DATA
	string AGREEMENT[2] = { "1) Contracts", "2) Billing" };									// NCET DATA -> AGREEMENT
	string BILLING[2] = { "1) Invoices", "2) Reciepts" };									// NCET DATA -> AGREEMENT -> BILLING

	// Private Functions
	string get_tutee(void);				// Get tutee name
	void set_tutee(void);				// Set tutee name

	// Private Getter Functions
	string* get_core_data(void);
	string* get_course_data(void);
	string* get_course_info(void);
	string* get_ncet_data(void);
	string* get_agreement(void);
	string* get_billing(void);
public:
	void generate_folders_maps(string);						// Creates a mapping of all established folders
	void generate_path_locations(string, string, string);	// Creates all folders according to the given mapping
};

#endif // !NEW_USER_H