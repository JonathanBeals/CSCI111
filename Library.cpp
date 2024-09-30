#include <iostream>
using namespace std;

// Global variables to store book information
string bookTitle1 = "";
string bookAuthor1 = "";
bool isBookBorrowed1 = false;

string bookTitle2 = "";
string bookAuthor2 = "";
bool isBookBorrowed2 = false;

string bookTitle3 = "";
string bookAuthor3 = "";
bool isBookBorrowed3 = false;

// Function prototypes
void displayMenu();
void addBook();
void removeBook();
void displayBooks();
void searchBook();
void borrowBook();
void returnBook();

int main() {
    int choice;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                searchBook();
                break;
            case 5:
                borrowBook();
                break;
            case 6:
                returnBook();
                break;
            case 7:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// Function to display the menu options
void displayMenu() {
    cout << "\nWelcome to the Library Management System" << endl;
    cout << "1. Add a Book" << endl;
    cout << "2. Remove a Book" << endl;
    cout << "3. Display All Books" << endl;
    cout << "4. Search for a Book" << endl;
    cout << "5. Borrow a Book" << endl;
    cout << "6. Return a Book" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

// Incomplete function to add a book
void addBook() {
    // Pseudocode:
    // 1. Check if there's an empty slot for a book (use global variables like bookTitle1, bookTitle2, etc.).
    // 2. If an empty slot is found, ask the user to enter the title and author.
    // 3. Set the isBookBorrowed flag to false (because the book is new and not borrowed).
    // 4. Display a success message.

    string title, author;
    if(bookTitle1 == "")
    {
        cout << "Enter the title of the book: ";
        cin.ignore();
        getline(cin, title);
        bookTitle1 = title;
        cout << "Enter the author of the book: ";
        cin.ignore();
        getline(cin, author);
        bookAuthor1 = author;
        isBookBorrowed1 = false;
        cout << "Book added successfully!"
    }

    else if(bookTitle2 == "")
    {
        cout << "Enter the title of the book: ";
        cin.ignore();
        getline(cin, title);
        bookTitle2 = title;
        cout << "Enter the author of the book: ";
        cin.ignore();
        getline(cin, author);
        bookAuthor2 = author;
        isBookBorrowed2 = false;
        cout << "Book added successfully!"

    }

    else if(bookTitle3 == "")
    {
        cout << "Enter the title of the book: ";
        cin.ignore();
        getline(cin, title);
        bookTitle3 = title;
        cout << "Enter the author of the book: ";
        cin.ignore();
        getline(cin, author);
        bookAuthor3 = author;
        isBookBorrowed3 = false;
        cout << "Book added successfully!"

    }
    else
        cout << "Library is full!" << endl;

}

// Incomplete function to remove a book
void removeBook() {
    // Pseudocode:
    // 1. Ask the user to enter the title of the book to remove.
    // 2. Check if the title matches any of the available books.
    // 3. If a match is found, clear the title, author, and isBookBorrowed flag.
    // 4. If no match is found, display an error message.
}

// Stub function to display all books (empty, needs to be implemented)
void displayBooks() {
    // Pseudocode:
    // 1. Check if each book slot (bookTitle1, bookTitle2, bookTitle3) is empty or filled.
    // 2. For filled slots, display the title, author, and borrowing status.
    // 3. If no books are available, display a message stating that the library is empty.
}

// Function to search for a book (left incomplete for students to fill)
void searchBook() {
    string searchTitle;
    cout << "Enter the book title to search: ";
    cin.ignore();  // Ignore any previous input
    getline(cin, searchTitle);
    
    // Pseudocode:
    // 1. Compare the searchTitle with bookTitle1, bookTitle2, bookTitle3.
    // 2. If a match is found, display the book's title, author, and borrowing status.
    // 3. If no match is found, display a "Book not found" message.
}

// Function to borrow a book (partially implemented, students complete)
void borrowBook() {
    string borrowTitle;
    cout << "Enter the book title to borrow: ";
    cin.ignore();
    getline(cin, borrowTitle);

    if (borrowTitle == bookTitle1 && !isBookBorrowed1) {
        isBookBorrowed1 = true;
        cout << "You have successfully borrowed \"" << bookTitle1 << "\"." << endl;
    } else if (borrowTitle == bookTitle2 && !isBookBorrowed2) {
        isBookBorrowed2 = true;
        cout << "You have successfully borrowed \"" << bookTitle2 << "\"." << endl;
    } else if (borrowTitle == bookTitle3 && !isBookBorrowed3) {
        isBookBorrowed3 = true;
        cout << "You have successfully borrowed \"" << bookTitle3 << "\"." << endl;
    } else {
        cout << "Book not found or already borrowed." << endl;
    }
}

// Function to return a book (complete)
void returnBook() {
    string returnTitle;
    cout << "Enter the book title to return: ";
    cin.ignore();
    getline(cin, returnTitle);

    if (returnTitle == bookTitle1 && isBookBorrowed1) {
        isBookBorrowed1 = false;
        cout << "You have successfully returned \"" << bookTitle1 << "\"." << endl;
    } else if (returnTitle == bookTitle2 && isBookBorrowed2) {
        isBookBorrowed2 = false;
        cout << "You have successfully returned \"" << bookTitle2 << "\"." << endl;
    } else if (returnTitle == bookTitle3 && isBookBorrowed3) {
        isBookBorrowed3 = false;
        cout << "You have successfully returned \"" << bookTitle3 << "\"." << endl;
    } else {
        cout << "Book not found or wasn't borrowed." << endl;
    }
}