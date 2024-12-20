#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int rollno;
    string name;
    string dob; // Changed to string for better handling

    // Overload the '==' operator to compare students by roll number
    bool operator==(const Student &student1) const {
        return rollno == student1.rollno;
    }

    // Overload the '<' operator to compare students by roll number
    bool operator<(const Student &student1) const {
        return rollno < student1.rollno;
    }
};

// Global vector to store student data
vector<Student> students;

// Function declarations
void print(const Student &student);
void display();
void insert();
void search();
void sortStudents();
void deleteStudent();
bool compare(const Student &s1, const Student &s2);

int main() {
    int option;
    do {
        // Menu
        cout << "\n\n\t\t-------<< MENU >>---------";
        cout << "\n\t\t1. Insert";
        cout << "\n\t\t2. Display";
        cout << "\n\t\t3. Search";
        cout << "\n\t\t4. Sort";
        cout << "\n\t\t5. Delete";
        cout << "\n\t\t6. Quit";
        cout << "\n\t\t--------------------------";
        cout << "\n\t\tEnter your choice: ";
        cin >> option;

        // Handle the menu option
        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sortStudents();
                cout << "Sorted based on roll numbers." << endl;
                display();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    } while (option != 6);

    return 0;
}

// Insert a new student into the vector
void insert() {
    Student student;
    cout << "\nEnter Roll No: ";
    cin >> student.rollno;
    cout << "Enter Name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, student.name);
    cout << "Enter DOB (YYYY-MM-DD): ";
    cin >> student.dob;
    students.push_back(student);
    cout << "Student inserted successfully." << endl;
}

// Display the details of all students
void display() {
    if (students.empty()) {
        cout << "No students available." << endl;
        return;
    }
    cout << "\n\n\t\t-------<< Student List >>---------\n";
    for_each(students.begin(), students.end(), print);
}

// Print student details
void print(const Student &student) {
    cout << "\nStudent Name: " << student.name;
    cout << "\nRoll Number: " << student.rollno;
    cout << "\nDate of Birth: " << student.dob << endl;
}

// Search for a student by roll number
void search() {
    int rollno;
    cout << "\nEnter Student Roll No to Search: ";
    cin >> rollno;

    // Use lambda to search for a student
    auto it = find_if(students.begin(), students.end(), [rollno](const Student &s) {
        return s.rollno == rollno;
    });

    if (it != students.end()) {
        cout << "\nStudent found:\n";
        print(*it);
    } else {
        cout << "\nStudent with Roll No " << rollno << " not found." << endl;
    }
}

// Sort students based on roll numbers
void sortStudents() {
    sort(students.begin(), students.end(), compare);
}

// Comparator function to sort students based on roll number
bool compare(const Student &s1, const Student &s2) {
    return s1.rollno < s2.rollno;
}

// Delete a student by roll number
void deleteStudent() {
    int rollno;
    cout << "\nEnter Student Roll No to Delete: ";
    cin >> rollno;

    // Use lambda to find the student
    auto it = find_if(students.begin(), students.end(), [rollno](const Student &s) {
        return s.rollno == rollno;
    });

    if (it != students.end()) {
        students.erase(it);
        cout << "\nStudent with Roll No " << rollno << " deleted successfully." << endl;
    } else {
        cout << "\nStudent with Roll No " << rollno << " not found." << endl;
    }
}
