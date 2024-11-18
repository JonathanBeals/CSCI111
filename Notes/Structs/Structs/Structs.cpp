#include <iostream>

// Constants for maximum number of books and authors
const int MAX_BOOKS = 100;
const int MAX_AUTHORS = 50;

// Define an Author struct to store author information
struct Author {
    int id;                    // Unique ID for each author
    char name[100];            // Author's name
    int birthYear;             // Author's birth year
    char nationality[50];      // Author's nationality
};

// Define a Book struct to store book information
struct Book {
    int id;                    // Unique ID for each book
    char title[100];           // Book title
    int publicationYear;       // Year of publication
    Author author;             // Author of the book (using the Author struct)
    char genre[50];            // Genre of the book
    bool isAvailable;          // Availability status
};

// Function prototypes to handle adding authors, adding books, and listing books
void addAuthor(Author authors[], int& authorCount);
void addBook(Book books[], int& bookCount, const Author authors[], int authorCount);
void listBooks(const Book books[], int bookCount);
void listBooksByAuthor(const Book books[], int bookCount, int authorId);

int main(int argc, const char* argv[])
{
    // Arrays to store multiple authors and books
    Author authors[MAX_AUTHORS];
    Book books[MAX_BOOKS];
    int authorCount = 0, bookCount = 0;

    // Sample data input for demonstration purposes
    addAuthor(authors, authorCount);
    addBook(books, bookCount, authors, authorCount);
    addBook(books, bookCount, authors, authorCount);

    // Display all books and books by a specific author
    listBooks(books, bookCount);
    listBooksByAuthor(books, bookCount, authors[0].id);

    return 0;
}

// Function to add a new author to the authors array
void addAuthor(Author authors[], int& authorCount)
{
    Author newAuthor;
    newAuthor.id = authorCount + 1; // Automatically assign a unique ID

    // Prompt user for author details
    std::cout << "Enter author name: ";
    std::cin.getline(newAuthor.name, 100);
    std::cout << "Enter birth year: ";
    std::cin >> newAuthor.birthYear;
    std::cin.ignore();
    std::cout << "Enter nationality: ";
    std::cin.getline(newAuthor.nationality, 50);

    // Add new author to the array and increment the author count
    authors[authorCount++] = newAuthor;
    std::cout << "Author added successfully!\n";
}

// Function to add a new book to the books array
void addBook(Book books[], int& bookCount, const Author authors[], int authorCount)
{
    // Ensure there is at least one author before adding a book
    if (authorCount == 0)
    {
        std::cout << "No authors available. Please add an author first.\n";
        return;
    }

    Book newBook;
    newBook.id = bookCount + 1; // Automatically assign a unique ID

    // Prompt user for book details
    std::cout << "Enter book title: ";
    std::cin.getline(newBook.title, 100);

    std::cout << "Enter publication year: ";
    std::cin >> newBook.publicationYear;

    // Display author choices and allow user to select an author
    std::cout << "Select author by ID:\n";
    for (int i = 0; i < authorCount; ++i)
    {
        std::cout << authors[i].id << ". " << authors[i].name << "\n";
    }
    int authorId;
    std::cin >> authorId;
    newBook.author = authors[authorId - 1]; // Assign the chosen author to the book

    // Prompt user for genre and set availability status
    std::cout << "Enter genre: ";
    std::cin.ignore();
    std::cin.getline(newBook.genre, 50);
    newBook.isAvailable = true; // Default availability set to true

    // Add new book to the array and increment the book count
    books[bookCount++] = newBook;
    std::cout << "Book added successfully!\n";
}

// Function to list all books with their details
void listBooks(const Book books[], int bookCount)
{
    std::cout << "Listing all books:\n";
    for (int i = 0; i < bookCount; ++i)
    {
        std::cout << "ID: " << books[i].id << ", Title: " << books[i].title
            << ", Author: " << books[i].author.name
            << ", Year: " << books[i].publicationYear
            << ", Genre: " << books[i].genre
            << ", Available: " << (books[i].isAvailable ? "Yes" : "No") << "\n";
    }
}

// Function to list all books by a specific author
void listBooksByAuthor(const Book books[], int bookCount, int authorId)
{
    std::cout << "Books by author ID " << authorId << ":\n";
    for (int i = 0; i < bookCount; ++i)
    {
        if (books[i].author.id == authorId)
        {
            std::cout << "ID: " << books[i].id << ", Title: " << books[i].title
                << ", Year: " << books[i].publicationYear
                << ", Genre: " << books[i].genre
                << ", Available: " << (books[i].isAvailable ? "Yes" : "No") << "\n";
        }
    }
}