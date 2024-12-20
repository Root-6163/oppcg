#include<iostream>
#include<string>
#include<vector>
using namespace std;

class StudData;

class Student {
    string name;
    int roll_no;
    string cls;
    string division;
    string dob;
    string bloodgroup;
    static int count;

public:
    Student();
    static int getCount();
    void getData(StudData*);
    void dispData(StudData*);
};

class StudData {
    string caddress;
    long int telno;
    long int dlno;

public:
    StudData();
    void getStudData();
    void dispStudData();
};

int Student::count = 0;

Student::Student() : name(""), roll_no(0), cls(""), division(""), dob("dd/mm/yyyy"), bloodgroup("") {}

StudData::StudData() : caddress(""), telno(0), dlno(0) {}

void Student::getData(StudData* st) {
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Roll Number: ";
    cin >> roll_no;
    cout << "Enter Class: ";
    cin >> cls;
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Date of Birth: ";
    cin >> dob;
    cout << "Enter Blood Group: ";
    cin >> bloodgroup;
    st->getStudData();
    count++;
}

void Student::dispData(StudData* st1) {
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << roll_no << endl;
    cout << "Class: " << cls << endl;
    cout << "Division: " << division << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodgroup << endl;
    st1->dispStudData();
}

void StudData::getStudData() {
    cout << "Enter Contact Address: ";
    cin.ignore();
    getline(cin, caddress);
    cout << "Enter Telephone Number: ";
    cin >> telno;
    cout << "Enter Driving License Number: ";
    cin >> dlno;
}

void StudData::dispStudData() {
    cout << "Contact Address: " << caddress << endl;
    cout << "Telephone Number: " << telno << endl;
    cout << "Driving License Number: " << dlno << endl;
}

int main() {
    vector<Student> students;
    vector<StudData> studData;
    char ch;

    do {
        Student s;
        StudData sd;
        
        cout << "Default Details of Student" << endl;
        s.dispData(&sd);

        cout << "Enter details of Student " << students.size() + 1 << endl;
        s.getData(&sd);

        students.push_back(s);
        studData.push_back(sd);

        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    for (size_t i = 0; i < students.size(); i++) {
        cout << "---------------------------------------------------------------" << endl;
        students[i].dispData(&studData[i]);
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students: " << Student::getCount() << endl;
    cout << "---------------------------------------------------------------" << endl;

    return 0;
}
