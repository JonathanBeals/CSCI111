#include <iostream>
#include <cstring> // for strcpy and strlen

using namespace std;

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
    void display() const {
        cout << "Title: " << title << ", Author: " << author
            << ", Year: " << year << ", Pages: " << pages;
        if (borrower) {
            borrower->display();
        }
        else {
            cout << ", available";
        }
        cout << endl;
    }
};

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
        cout << "Borrower: " << name << ", Id: " << id << endl;
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

void borrowBook(Book* book, const char* borrowerName, int borrowerId) {
    if (book->borrower) {
        cout << "The book: " << book->title << " is already borrowed" << endl;
    }
    else {
        book->borrower = new Borrower(borrowerName, borrowerId);
        cout << "The book: " << book->title << ", has been borrowed by: "
            << borrowerName << " Id: " << borrowerId << endl;
    }
}

void returnBook(Book* book) {
    if (!book->borrower) {
        cout << "The book: " << book->title << " is not being borrowed" << endl;
    }
    else {
        cout << "The book: " << book->title << " has been returned by: "
            << book->borrower->name << " Id: " << book->borrower->id << endl;
        delete book->borrower;
        book->borrower = nullptr;
    }
}

int main() {
    int bookCount = 0;
    Book** books = nullptr;

    // Adding some books
    addBook(books, bookCount, "1984", "George Orwell", 1949, 328);
    addBook(books, bookCount, "To Kill a Mockingbird", "Harper Lee", 1960, 281);
    addBook(books, bookCount, "The Great Gatsby", "F. Scott Fitzgerald", 1925, 180);
    addBook(books, bookCount, "Moby Dick", "Herman Melvile", 1851, 635);
    addBook(books, bookCount, "The Catcher in the Rye", "J.D Salinger", 1951, 277);
    addBook(books, bookCount, "War and Peace", "Leo Tolstoy", 1869, 1225);
    addBook(books, bookCount, "Pride and Prejudice", "Jane Austen", 1813, 279);
    addBook(books, bookCount, "The Shining", "Stephen King", 1977, 447);//My favorite book

    cout << "Library Collection:\n";
    displayBooks(books, bookCount);


    borrowBook(books[0], "Alice", 101);
    borrowBook(books[0], "Bob", 102);

    returnBook(books[0]);

    borrowBook(books[0], "Charlie", 103);

    // Clean up dynamic memory
    for (int i = 0; i < bookCount; i++) {
        delete books[i];
    }
    delete[] books;

    return 0;
}
