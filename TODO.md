# Library Management System

## Project Overview

The Library Management System is a desktop application designed to help librarians manage books, members, and borrowing activities efficiently. The system provides a graphical user interface (GUI) for performing common library operations.

---

## Features

### 1. Dashboard

~~ Display total number of books ‍‍~~

- Display total number of members
- Display number of borrowed books
- Display number of available books

### 2. Book Management

- Add a new book
- Edit book information
- Delete a book
- View all books
- Search books by:
  - Title
  - Author
  - ISBN
  - Category

- View book availability status

### 3. Member Management

- Register a new member
- Edit member information
- Delete a member
- View all members
- Search members by:
  - Member ID
  - Name

### 4. Borrowing Management

- Borrow a book
- Assign a book to a member
- Record borrowing date
- View currently borrowed books
- Prevent borrowing unavailable books

### 5. Return Management

- Return a borrowed book
- Update book availability
- Record return date
- View borrowing history

### 6. Search and Filter

- Search books
- Search members
- Filter available books
- Filter borrowed books

### 7. Data Validation

- Prevent duplicate ISBN entries
- Validate member information
- Validate required fields
- Display error messages for invalid inputs

### 8. Reports and Statistics

- Total books in library
- Total available books
- Total borrowed books
- Total registered members

### 9. Data Storage

- Save data to files
- Load data from files on startup
- Update records automatically after modifications

### 10. User Interface

- Main dashboard window
- Book management window
- Member management window
- Borrow/Return window
- Search functionality
- Confirmation dialogs for critical actions

---

## Data Structures

### Book

- Book ID
- Title
- Author
- ISBN
- Category
- Availability Status

### Member

- Member ID
- First Name
- Last Name
- Phone Number
- Email

### Borrow Record

- Record ID
- Member ID
- Book ID
- Borrow Date
- Return Date
- Status

---

## Future Improvements

- User authentication and login
- Fine calculation for overdue books
- Barcode scanning
- Multiple librarian accounts
- Database integration
- Book reservation system
