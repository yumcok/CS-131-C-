#include <iostream>
#include <string>

class LibraryBook {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isIssued;

public:
    // Constructor
    LibraryBook(const std::string& bookTitle, const std::string& bookAuthor, const std::string& bookISBN)
        : title(bookTitle), author(bookAuthor), ISBN(bookISBN), isIssued(false) {}

    // Function to issue the book
    void issueBook() {
        if (isIssued) {
            std::cout << "Sorry, the book is already issued." << std::endl;
        } else {
            isIssued = true;
            std::cout << "Book issued successfully." << std::endl;
        }
    }

    // Function to return the book
    void returnBook() {
        if (!isIssued) {
            std::cout << "The book is not issued yet." << std::endl;
        } else {
            isIssued = false;
            std::cout << "Book returned successfully." << std::endl;
        }
    }

    // Function to display book details
    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << ISBN << std::endl;
        std::cout << "Status: " << (isIssued ? "Issued" : "Available") << std::endl;
    }
};

int main() {
    // Creating a LibraryBook object
    LibraryBook book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");

    // Displaying book details
    book.displayDetails();

    // Issuing the book
    book.issueBook();

    // Displaying book details after issuing
    book.displayDetails();

    // Issuing the book again (already issued)
    book.issueBook();

    // Returning the book
    book.returnBook();

    // Displaying book details after returning
    book.displayDetails();

    return 0;
}
