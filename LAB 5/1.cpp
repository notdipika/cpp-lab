/*Define a class Library with data members ISBN, bookTitle, author, and numberOfCopies. Implement methods to add new books, issue books, return books, update book details, and delete books. The library's catalog should be maintained in a file. Specifically, implement the following operations:
1. Add New Book: Insert a new book's details into the catalog file. Ensure that each book has a unique ISBN and that duplicate entries are not allowed.
2. Issue Book: Mark a book as issued by decreasing the number of available copies in the catalog file. Ensure that a book cannot be issued if the number of available copies is
zero.
3. Return Book: Mark a book as returned by increasing the number of available copies in the catalog file.
4. Update Book Details: Edit the details of a book, such as ISBN, book Title, author, or numberOfCopies, in the catalog file. Ensure that changing ISBN does not result in duplicates.
5. Delete Book: Allow the user to delete a book's record from the catalog file only if the following conditions are met:
- The number of available copies is zero.
- The book has not been issued to any user, meaning all copies have been returned and there are no outstanding issues for the book.
Ensure that the number of copies is appropriately updated for each operation and that file operations maintain data integrity. Provide methods to read from and write to the file for maintaining the catalog data.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book {
public:
    string ISBN;
    string bookTitle;
    string author;
    int numberOfCopies;

    void inputBook() {
        cout<< "Enter ISBN: ";
        cin>> ISBN;
        cout<< "Enter Book Title: ";
        cin>> bookTitle;
        cout<< "Enter Author: ";
        cin>> author;
        cout<< "Enter Number of Copies: ";
        cin>> numberOfCopies;
    }

    void displayBook()  {
        cout<< "ISBN: " << ISBN << endl;
        cout<< "Title: " << bookTitle << endl;
        cout<< "Author: " << author << endl;
        cout<<"Copies: " << numberOfCopies << endl;
    }
};

class Library {
private:
    string catName;

    bool bookExists( string& isbn) {
        ifstream file(catName);
        string line;
        while (getline(file, line)) {
            if (line.find(isbn) == 0) {
                return true;
            }
        }
        return false;
    }

    void writeBook(ofstream& file,  Book& book) {
        file << book.ISBN << ";" << book.bookTitle << ";" << book.author << ";" << book.numberOfCopies << endl;
    }

public:
    Library(const string& fileName) : catName(fileName) {}

    void addNewBook() {
        Book newBook;
        newBook.inputBook();

        if (bookExists(newBook.ISBN)) {
            cerr << "Book with ISBN " << newBook.ISBN << " already exists.\n";
            return;
        }

        ofstream file(catName, ios::app);
        if (!file) {
            cerr << "Error! Could not open file.\n";
            return;
        }
        writeBook(file, newBook);
    }

    void issueBook() {
        cout << "Enter ISBN to issue: ";
        string isbn;
        cin>> isbn;

        ifstream file(catName);
        ofstream tempFile("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {
            Book book;
            size_t pos = line.find(';');
            book.ISBN = line.substr(0, pos);

            if (book.ISBN == isbn) {
                found = true;
                book.numberOfCopies = stoi(line.substr(line.find_last_of(';') + 1)) - 1;
                if (book.numberOfCopies < 0) {
                    cerr << "No copies available.\n";
                    book.numberOfCopies = 0;
                }
            } else {
                tempFile << line << endl;
            }

            if (found) {
                tempFile << book.ISBN << ";" << line.substr(pos + 1, line.find_last_of(';') - pos - 1) << ";" << book.numberOfCopies << endl;
            }
        }

        if (!found) {
            cerr << "Book with ISBN " << isbn << " not found.\n";
        }

        file.close();
        tempFile.close();
        remove(catName.c_str());
        rename("temp.txt", catName.c_str());
    }

    void returnBook() {
        cout << "Enter ISBN to return: ";
        string isbn;
        cin>> isbn;

        ifstream file(catName);
        ofstream tempFile("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {
            Book book;
            size_t pos = line.find(';');
            book.ISBN = line.substr(0, pos);

            if (book.ISBN == isbn) {
                found = true;
                book.numberOfCopies = stoi(line.substr(line.find_last_of(';') + 1)) + 1;
            } else {
                tempFile << line << endl;
            }

            if (found) {
                tempFile << book.ISBN << ";" << line.substr(pos + 1, line.find_last_of(';') - pos - 1) << ";" << book.numberOfCopies << endl;
            }
        }

        if (!found) {
            cerr << "Book with ISBN " << isbn << " not found.\n";
        }

        file.close();
        tempFile.close();
        remove(catName.c_str());
        rename("temp.txt", catName.c_str());
    }

    void updateBookDetails() {
        Book updatedBook;
        updatedBook.inputBook();

        ifstream file(catName);
        ofstream tempFile("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {
            Book book;
            size_t pos = line.find(';');
            book.ISBN = line.substr(0, pos);

            if (book.ISBN == updatedBook.ISBN) {
                found = true;
                tempFile << updatedBook.ISBN << ";" << updatedBook.bookTitle << ";" << updatedBook.author << ";" << updatedBook.numberOfCopies << endl;
            } else {
                tempFile << line << endl;
            }
        }

        if (!found) {
            cerr << "Book with ISBN " << updatedBook.ISBN << " not found.\n";
        }

        file.close();
        tempFile.close();
        remove(catName.c_str());
        rename("temp.txt", catName.c_str());
    }

    void deleteBook() {
        cout << "Enter ISBN to delete: ";
        string isbn;
        cin>> isbn;

        ifstream file(catName);
        ofstream tempFile("temp.txt");

        string line;
        bool found = false;

        while (getline(file, line)) {
            Book book;
            size_t pos = line.find(';');
            book.ISBN = line.substr(0, pos);

            if (book.ISBN == isbn) {
                found = true;
                int copies = stoi(line.substr(line.find_last_of(';') + 1));
                if (copies > 0) {
                    cerr << "Error: Cannot delete a book with available copies.\n";
                    tempFile << line << endl;
                }
            } else {
                tempFile << line << endl;
            }
        }

        if (!found) {
            cerr << "Error: Book with ISBN " << isbn << " not found.\n";
        }

        file.close();
        tempFile.close();
        remove(catName.c_str());
        rename("temp.txt", catName.c_str());
    }
};

int main() {
    Library lib("catalogue.txt");
    lib.addNewBook();
    lib.issueBook();
    lib.returnBook();
    lib.updateBookDetails();
    lib.deleteBook();
    return 0;
}