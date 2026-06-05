Library Management System - Development Plan
Project Goal

Develop a Library Management System that allows librarians to manage books, members, and borrowing activities.

The project will be developed in two phases:

CLI Version (Core Functionality)
GUI Version (User Interface Enhancement)

The CLI version must be fully functional before GUI development begins.

Phase 1 - Core System Design
Data Structures
Book
Book ID
Title
Author
ISBN
Category
Availability Status
Member
Member ID
First Name
Last Name
Phone Number
Borrow Record
Record ID
Member ID
Book ID
Borrow Date
Return Date
Phase 2 - CLI Implementation
Main Menu
Library Management System

1. Book Management
2. Member Management
3. Borrow Book
4. Return Book
5. Reports
6. Exit
   Book Management Module
   Features
   Add Book
   Enter book information
   Validate required fields
   Store book in system
   Edit Book
   Search book by ID
   Modify information
   Delete Book
   Search book by ID
   Confirm deletion
   Search Book
   Search by:
   Book ID
   Title
   Author
   ISBN
   View All Books
   Display complete book list
   Member Management Module
   Features
   Add Member
   Register new member
   Edit Member
   Modify member information
   Delete Member
   Remove member
   Search Member
   Search by:
   Member ID
   Name
   View All Members
   Display all members
   Borrow Book Module
   Features
   Borrow Book
   Select member
   Select book
   Verify availability
   Create borrow record
   Update book status
   Validation
   Member must exist
   Book must exist
   Book must be available
   Return Book Module
   Features
   Return Book
   Locate borrowing record
   Record return date
   Update availability status
   Validation
   Borrow record must exist
   Reports Module
   Statistics

Display:

Total Books
Available Books
Borrowed Books
Total Members
Phase 3 - Data Persistence
File Storage
Books File

Store all books.

Members File

Store all members.

Borrow Records File

Store all borrowing records.

Loading Process

Program Start:

Load books
Load members
Load records
Saving Process

When:

Adding data
Editing data
Deleting data
Borrowing books
Returning books
Program exit
Phase 4 - Testing
Test Cases
Book Management
Add book
Edit book
Delete book
Search book
Member Management
Add member
Edit member
Delete member
Search member
Borrowing
Borrow available book
Attempt borrowing unavailable book
Returning
Return borrowed book
Attempt returning invalid record
File Handling
Save data
Load data
Data consistency
Phase 5 - GUI Upgrade

The GUI will be built after the CLI version is complete.

Main Window

Display:

Total Books
Available Books
Borrowed Books
Total Members

Buttons:

Manage Books
Manage Members
Borrow Book
Return Book
Reports
Exit
Book Management Window

Features:

Add Book
Edit Book
Delete Book
Search Book
View Books
Member Management Window

Features:

Add Member
Edit Member
Delete Member
Search Member
View Members
Borrow Window

Features:

Select Member
Select Book
Borrow Book
Return Window

Features:

Select Borrow Record
Return Book
Reports Window

Display:

Statistics
Borrowing Summary
Development Priority

Priority 1:

Data Structures
Book Management
Member Management

Priority 2:

Borrow Book
Return Book

Priority 3:

File Handling
Reports

Priority 4:

GUI Integration

Priority 5:

UI Improvements and Enhancements
