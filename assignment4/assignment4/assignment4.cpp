#include <iostream>
#include <cstring> // for strcpy and strlen

using namespace std;

struct Book {
    char* title;
    char* author;
    int year;
    int pages;

    // Constructor to initialize book details
    Book(const char* t, const char* a, int y, int p) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);

        author = new char[strlen(a) + 1];
        strcpy(author, a);

        year = y;
        pages = p;
    }

    // Destructor to release dynamically allocated memory
    ~Book() {
        delete[] title;
        delete[] author;
    }

    // Member function to display book details
    void display() const {
        cout << "Title: " << title << ", Author: " << author
            << ", Year: " << year << ", Pages: " << pages << endl;
    }
};

// Function to add a book to a dynamic array of books
void addBook(Book**& books, int& count, const char* title, const char* author, int year, int pages) {
    Book** newBooks = new Book * [count + 1];

    // Copy existing books to the new array
    for (int i = 0; i < count; i++) {
        newBooks[i] = books[i];
    }

    // Add the new book
    newBooks[count] = new Book(title, author, year, pages);

    // Clean up old array and update pointers
    delete[] books;
    books = newBooks;
    count++;
}

// Function to display all books
void displayBooks(Book** books, int count) {
    for (int i = 0; i < count; i++) {
        books[i]->display();
    }
}

int main() {
    int bookCount = 0;
    Book** books = nullptr;

    // Adding some books
    addBook(books, bookCount, "1984", "George Orwell", 1949, 328);
    addBook(books, bookCount, "To Kill a Mockingbird", "Harper Lee", 1960, 281);
    addBook(books, bookCount, "The Great Gatsby", "F. Scott Fitzgerald", 1925, 180);

    cout << "Library Collection:\n";
    displayBooks(books, bookCount);

    // Clean up dynamic memory
    for (int i = 0; i < bookCount; i++) {
        delete books[i];
    }
    delete[] books;

    return 0;
}

