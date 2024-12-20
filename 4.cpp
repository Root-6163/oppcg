#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // For strcmp
using namespace std;

class Student {
public:
    char name[20];
    char phone[15];

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

    Student* students = new Student[limit];
    fstream file("data.bin", ios::in | ios::out | ios::binary | ios::app);

    if (!file) {
        cerr << "Error in opening the file!" << endl;
        delete[] students;
        return 1;
    }

    do {
        cout << "\n1. Store\n2. Display\n3. Search\n4. Modify\n5. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: { // Store
                cout << "Enter details of each person:\n";
                for (int i = 0; i < limit; ++i) {
                    students[i].accept();
                    file.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
                }
                break;
            }

            case 2: { // Display
                cout << "Stored information:\n";
                file.clear();
                file.seekg(0, ios::beg);
                Student temp;
                while (file.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
                    temp.display();
                }
                break;
            }

            case 3: { // Search
                char searchName[20];
                cout << "Enter the name to search: ";
                cin >> searchName;

                bool found = false;
                file.clear();
                file.seekg(0, ios::beg);
                Student temp;
                while (file.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
                    if (strcmp(temp.name, searchName) == 0) {
                        cout << "Record Found:\n";
                        temp.display();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Record not found." << endl;
                }
                break;
            }

            case 4: { // Modify
                char searchName[20];
                cout << "Enter the name to modify: ";
                cin >> searchName;

                bool modified = false;
                file.clear();
                file.seekg(0, ios::beg);
                Student temp;
                while (file.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
                    if (strcmp(temp.name, searchName) == 0) {
                        cout << "Enter new phone number: ";
                        cin >> temp.phone;

                        file.seekp(-static_cast<int>(sizeof(Student)), ios::cur);
                        file.write(reinterpret_cast<char*>(&temp), sizeof(Student));
                        cout << "Record updated." << endl;
                        modified = true;
                        break;
                    }
                }
                if (!modified) {
                    cout << "Record not found." << endl;
                }
                break;
            }

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (ch != 5);

    file.close();
    delete[] students;

    return 0;
}
