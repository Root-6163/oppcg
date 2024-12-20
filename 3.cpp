//============================================================================
// Name        : Publication.cpp
// Author      : Souvik Majumdar
// Version     :
// Copyright   : NOBODY SHOULD COPY THE CODE
// Description : Handling publications in C++
//============================================================================

#include <iostream>
#include <stdexcept> // For std::invalid_argument
using namespace std;

class Publication {
private:
    string title;
    float price;

public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore(); // Ignore any newline character left in the input buffer
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void display() const {
        cout << "Title of Book is: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pagecount;

public:
    void insert() {
        getData();
        cout << "Enter the total page numbers: ";
        try {
            cin >> pagecount;
            if (pagecount == 0) {
                throw std::invalid_argument("Page count cannot be zero");
            }
        } catch (const std::invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore the rest of the line
        }
    }

    void display() const {
        Publication::display();
        cout << "Total page numbers is: " << pagecount << endl;
    }
};

class Tape : public Publication {
private:
    float minutes;

public:
    void getTime() {
        getData();
        cout << "Enter the time of playing (in minutes): ";
        cin >> minutes;
    }

    void show() const {
        Publication::display();
        cout << "Time of playing is: " << minutes << " minutes" << endl;
    }
};

int main() {
    Book b;
    Tape t;
    int ch;

    do {
        cout << "1. Book\n2. Tape\n3. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                b.insert();
                b.display();
                break;

            case 2:
                t.getTime();
                t.show();
                break;

            case 3:
                return 0; // Use return instead of exit(0) for better practice

            default:
                cout << "Invalid choice. Please choose again.\n";
        }
    } while (true);

    return 0;
}
