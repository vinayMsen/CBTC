/*
The application allows users to add, view, and search for student records stored in a binary file. 
Header Inclusion:
 Added fstream for file handling operations
 Added #include <limits> to use numeric_limits.
Clearing Input Stream:
 Added a helper function clearInputStream() to clear the input stream.
 This function is used whenever an invalid input is encountered.
Error Handling in Menu:
 Added a check after reading the menu choice to handle non-integer inputs.
Consistent Stream Clearing:
 Ensured cin.ignore(numeric_limits<streamsize>::max(), '\n') is used consistently after reading from cin to clear the input buffer.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <limits>  // Including this for numeric_limits

using namespace std;

// Defining the Student structure
struct Student {
    int rollNumber;
    string name;
    string course;
    int year;
    float grade;
};

// Function prototypes
void addStudent();
void viewStudents();
void searchStudent();
void clearInputStream();  // Helper function to clear input stream from chatgpt

int main() {
    system("cls");
    int choice;
    do {
        cout << "Student Record Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 4." << endl;
            clearInputStream();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline left by cin

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

void addStudent() {
    Student student;
    ofstream outFile("students.dat", ios::app | ios::binary);

    if (!outFile) {
        cerr << "File could not be opened!" << endl;
        return;
    }

    cout << "Enter roll number: ";
    while (!(cin >> student.rollNumber)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid roll number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear newline left by cin

    cout << "Enter name: ";
    getline(cin, student.name);
    cout << "Enter course: ";
    getline(cin, student.course);
    cout << "Enter year: ";
    while (!(cin >> student.year)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid year: ";
    }
    cout << "Enter grade: ";
    while (!(cin >> student.grade)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid grade: ";
    }

    outFile.write(reinterpret_cast<char*>(&student), sizeof(student));
    outFile.close();
    cout << "Student added successfully!" << endl;
}

void viewStudents() {
    Student student;
    ifstream inFile("students.dat", ios::in | ios::binary);

    if (!inFile) {
        cerr << "File could not be opened!" << endl;
        return;
    }

    cout << "Roll Number\tName\tCourse\tYear\tGrade" << endl;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        cout << student.rollNumber << "\t" << student.name << "\t" << student.course << "\t" << student.year << "\t" << student.grade << endl;
    }

    inFile.close();
}

void searchStudent() {
    int rollNumber;
    cout << "Enter roll number to search: ";
    while (!(cin >> rollNumber)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid roll number: ";
    }

    Student student;
    ifstream inFile("students.dat", ios::in | ios::binary);
    bool found = false;

    if (!inFile) {
        cerr << "File could not be opened!" << endl;
        return;
    }

    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.rollNumber == rollNumber) {
            cout << "Student found!" << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Course: " << student.course << endl;
            cout << "Year: " << student.year << endl;
            cout << "Grade: " << student.grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
    }

    inFile.close();
}

void clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}