#include <iostream>
#include <cstring> // for strcpy and strlen
#include <iomanip>

using namespace std;

struct Borrower {
    char* name;
    int id;

    //constructor to initialize borrowers details
    Borrower(const char* n, int i) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        id = i;
    }

    //destructor to release dynamically allocated memory
    ~Borrower() {
        delete[] name;
    }

    //member function to display name and id
    void display() const {
        cout << "Borrower: " << name << ", (Id: " << id << ").\n" << endl;
    }
};

struct Book {
    char* title;
    char* author;
    Borrower* borrower;
    int year;
    int pages;

    // Constructor to initialize book details
    Book(const char* t, const char* a, int y, int p) : borrower(nullptr) {
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
        delete borrower;
    }

    // Member function to display book details
    // I decided to change this up a little bit to make the library output easier to read
    void display() const {
        cout << left << setw(25) << title
            << left << setw(20) << author
            << right << setw(6) << year
            << right << setw(12) << pages;
        if (borrower) {
            cout << right << setw(21) << " - Borrowed by " << borrower->name << " (Id: "
                << borrower->id << ")";
        }
        else {
            cout << setw(18) << " - Available";
        }
        cout << endl;
    }
};

//Adding function prototypes here and moving function definitions under main to get rid of warnings
// and it helps me understand the code a little better
void addBook(Book**& books, int& count, const char* title, const char* author, int year, int pages);
void displayBooks(Book** books, int count);
void borrowBook(Book* book, const char* borrowerName, int borrowerId);
void returnBook(Book* book);


int main() {
    int bookCount = 0;
    Book** books = nullptr;

    // Adding books
    addBook(books, bookCount, "1984", "George Orwell", 1949, 328);
    addBook(books, bookCount, "To Kill a Mockingbird", "Harper Lee", 1960, 281);
    addBook(books, bookCount, "The Great Gatsby", "F. Scott Fitzgerald", 1925, 180);
    addBook(books, bookCount, "Moby Dick", "Herman Melville", 1851, 635);
    addBook(books, bookCount, "The Catcher in the Rye", "J.D Salinger", 1951, 277);
    addBook(books, bookCount, "War and Peace", "Leo Tolstoy", 1869, 1225);
    addBook(books, bookCount, "Pride and Prejudice", "Jane Austen", 1813, 279);
    addBook(books, bookCount, "The Shining", "Stephen King", 1977, 447); //My favorite book!

    //display initial library
    cout << "\nLibrary Collection\n";
    cout << "Title:" << setw(26) << "Author:" << setw(19) << "Year:" << setw(15) << "Page Count:" << setw(16) << "Status:\n\n";
    displayBooks(books, bookCount);
    cout << "\n";

    //borrow a few books
    borrowBook(books[0], "Alice", 101);

    borrowBook(books[0], "Bob", 102);

    borrowBook(books[3], "Charlie", 103);
    borrowBook(books[7], "Charlie", 103);

    //display the library after borrowing
    cout << "\nLibrary after borrowing\n";
    cout << "Title:" << setw(26) << "Author:" << setw(19) << "Year:" << setw(15) << "Page Count:" << setw(14) << "Status:\n\n";
    displayBooks(books, bookCount);
    cout << "\n";

    //returning books
    returnBook(books[0]);
    returnBook(books[3]);

    //display library after partial returning
    cout << "\nUpdated Library\n";
    cout << "Title:" << setw(26) << "Author:" << setw(19) << "Year:" << setw(15) << "Page Count:" << setw(14) << "Status:\n\n";
    displayBooks(books, bookCount);
    cout << "\n";

    //returning last book
    returnBook(books[7]);

    //display library after returning all books
    cout << "\nLibrary after returning all books\n";
    cout << "Title:" << setw(26) << "Author:" << setw(19) << "Year:" << setw(15) << "Page Count:" << setw(14) << "Status:\n\n";
    displayBooks(books, bookCount);
    cout << "\n";

    // Clean up dynamic memory
    for (int i = 0; i < bookCount; i++) {
        delete books[i];
    }
    delete[] books;

    return 0;
}

// Function Definitions
// Function to add a book to a dynamic array of books
void addBook(Book**& books, int& count, const char* title, const char* author, int year, int pages) {
    Book** newBooks = new Book * [count + 1];

    // Copy existing books to the new array
    for (int i = 0; i < static_cast<size_t>(count); i++) {
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

void borrowBook(Book* book, const char* borrowerName, int borrowerId) {
    if (book->borrower) {
        cout << "The book '" << book->title << "'" << " is already borrowed by: "
            << book->borrower->name << " (Id: " << book->borrower->id << ")\n";
    }
    else {
        delete book->borrower;
        book->borrower = new Borrower(borrowerName, borrowerId);
        cout << borrowerName << " successfully borrowed '" << book->title << "'\n";
    }
}

void returnBook(Book* book) {
    if (!book->borrower) {
        cout << "The book: '" << book->title << "' is not being borrowed\n";
    }
    else {
        cout << book->borrower->name << " returned: '" << book->title << "'\n";
        delete book->borrower;
        book->borrower = nullptr;
    }
}