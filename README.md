# NCET_Windows_Folders_Group_Creation

### Last major update: __13 July 2021__

	Name: NCET_Windows_Folders_Group_Creation
	Author: Nicholas Perez-Aguilar
	Company: NCompEng Technologies
	Date of Start: 13 July 2021

## What is this program expected to do?
This program is expected to provide different choices for creating different types of folder groupings. These groupings will be a set style from books with chapters to creating new user profiles with necessary folders encompassed within them, and each generated folder is to be placed in user-set locations for use within NCompEng Technologies.

## Roadmap to achieve this plan
- [X] Locate and verify folder location
  - [X] Get path from user __(can only save locally, with just a file name creating a folder at the location of the executable file.)__
- [X] Allow for choice between groupings for user to select
  - [ ] Book
    - [ ] Get book name for encompassing folder
      - [ ] Place book name as a global variable for later use
    - [ ] Get encompassing sections of the book. Ask what style they use and counts
      - [ ] Ask if parts or sections are involved
        - [ ] Get part or section
          - [ ] Parts
            - [ ] Get parts count
          - [ ] Section
            - [ ] Get section count
      - [ ] Chapters
        - [ ] Get chapter count per section
      - [ ] Sub-chapters
        - [ ] Get sub-chapter count per chapter
      - [ ] Appendixes
        - [ ] Get usable appendixes count
  - [X] New User (Tutoring)
    - [X] Get name of Tutee
      - [X] Save to a global variable for later
    - [X] Create main folders to go into Tutees folder
      - [X] 1) Course Data
        - [X] Create sub-folder for Course Data
          - [X] 1) Course Info
            - [X] Create sub-folders for Course-info
              - [X] 1) Syllabus
              - [X] 2) Supplemental Material
          - [X] 2) Course Lessons
      - [X] 2) NCET Data
        - [X] Create sub-folders for NCET Data
          - [X] 1) Agreement
            - [X] Create sub-folders for Agreement
              - [X] 1) Contracts
              - [X] 2) Billing
                - [X] Create sub-folders for Billing
                  - [X] 1) Invoices
                  - [X] 2) Reciepts
          - [X] 2) Time Clock
      - [X] 3) Book Data
      - [X] 4) Lessons
  - [ ] Monthly YouTube Gaming
    - [X] Get month as a container folder
      - [X] Save month in a global array
      - [ ] Create weekend folders
        - [ ] Saturdays
        - [ ] Sundays
      - [ ] Get number of Saturdays and Sundays
        - [ ] Keep each data piece global to be used later
          - [ ] Ask for date of each Saturday
          - [ ] Ask for date of each Sunday
        - [ ] Have a global value of " - \<Game Type>" to be appended to each date
          - [ ] Final value of one folder is: "8 August 2021 - \<Game Type>"
          - [ ] Verify that folder names match this example
      - [ ] Create a global array to create sub-folders that go in every weekend
        - [ ] Sub-folders per folder
          - [ ] Completed Video
          - [ ] Working Directory
          - [ ] Social Media & YouTube documents
- [X] Set up code to pull from different lists/arrays/vectors (choose what is most efficient)
- [X] Ask for all names, showing which part of the hierarchy it relates to.
- [X] Generate a hierarchy of names from code and display them to the user to check for validation.
  - [X] Not validated, ask where it went wrong (redo section)
  - [X] Valid, create file hierarchy at path location.
- [X] End-note advertising NCET.

## Possible languages to be used?
- C++
> Language of Choice for Start
- Python
> Potentially used for data collection if data can be passed into scripts from C++ commands and returned in some form from Python scripts back to C++.

## What are potential future plans?
1. Read hierarchy from a .txt file, using an established code for unpacking.