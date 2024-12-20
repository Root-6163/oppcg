//file handling mode creata afile and write mode on and save it again used it asa in display on screen
/*1 . first we want to create a file
2. open this file in write mode
3.write file 
4.close this file
5. open the file again and display on screen 
6.file.close()
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    public:
        char name[20];
        string phone;

    public:
        void accept();
        void display();
};

void Student::accept() {
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Phone: ";
    cin >> phone;
}

void Student::display() {
    cout << "Name: " << name << ", Phone: " << phone << endl;
}

int main() {
    int ch, limit;
    cout << "Enter the number of people whose information is to be stored: ";
    cin >> limit;

    Student* a = new Student[limit];
    fstream file("data.txt", ios::in | ios::out | ios::app | ios::binary);

    if (!file) {
        cerr << "Error in opening the file!" << endl;
        return 1;
    }

    do {
        cout << "\n1. Store\n2. Display\n3. Search\n4. Modify\n5. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: // Store
                cout << "Enter the name and phone number for each person:\n";
                for (int i = 0; i < limit; ++i) {
                    a[i].accept();
                    file.write(reinterpret_cast<char*>(&a[i], sizeof(a[i])));
                }
                break;

            case 2: // Display
                cout << "Stored information:\n";
                file.clear(); // clear any EOF or error flags
                file.seekg(0); // reset to beginning of file
                for (int i = 0; i < limit; ++i) {
                    file.read(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
                    a[i].display();
                }
                break;

            case 3: { // Search
                int searchType;
                cout << "Search by:\n1. Name\n2. Phone\nEnter choice: ";
                cin >> searchType;
                if (searchType == 1) {
                    char searchName[20];
                    cout << "Enter the name: ";
                    cin >> searchName;

                    bool found = false;
                    file.clear();
                    file.seekg(0);
                    for (int i = 0; i < limit; ++i) {
                        file.read(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
                        if (strcmp(a[i].name, searchName) == 0) {
                            cout << "Phone: " << a[i].phone << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Record not found." << endl;
                    }
                } else if (searchType == 2) {
                    string searchPhone;
                    cout << "Enter the phone number: ";
                    cin >> searchPhone;

                    bool found = false;
                    file.clear();
                    file.seekg(0);
                    for (int i = 0; i < limit; ++i) {
                        file.read(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
                        if (a[i].phone == searchPhone) {
                            cout << "Name: " << a[i].name << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Record not found." << endl;
                    }
                }
                break;
            }

            case 4: { // Modify
                string oldPhone;
                cout << "Enter the old phone number to modify: ";
                cin >> oldPhone;

                bool modified = false;
                file.clear();
                file.seekg(0);
                for (int i = 0; i < limit; ++i) {
                    file.read(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
                    if (a[i].phone == oldPhone) {
                        cout << "Enter new phone number: ";
                        cin >> a[i].phone;
                        file.seekp(-static_cast<int>(sizeof(a[i])), ios::cur);
                        file.write(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
                        modified = true;
                        cout << "Record updated." << endl;
                        break;
                    }
                }
                if (!modified) {
                    cout << "Record not found." << endl;
                }
                break;
            }

            case 5: // Exit
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (ch != 5);

    file.close();
    delete[] a;

    return 0;
}
