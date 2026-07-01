#include "CampusMap.h"
#include "StudentList.h"
#include "Filemanager.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;

//---

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getInt(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val) { clearInput(); return val; }
        cout << "Invalid input. Please enter a number.\n";
        clearInput();
    }
}

float getFloat(const string& prompt) {
    float val;
    while (true) {
        cout << prompt;
        if (cin >> val) { clearInput(); return val; }
        cout << "Invalid input.\n";
        clearInput();
    }
}

string getLine(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}

void printMenu() {
    cout << "\n======= Campus Management System (Milestone 1) =======\n"
         << "1. Display Campus Map\n"
         << "2. Explore Location\n"
         << "3. Add Student\n"
         << "4. Search Student\n"
         << "5. Display All Students\n"
         << "6. Exit\n"
         << "========================================================\n"
         << "Choice: ";
}

// main

int main() {
    CampusMap   map;
    StudentList students;

    cout << "=== Campus Exploration & Student Resource Management System ===\n\n";

    // load campus map (no hardcoded filename)
    string mapFile = getLine("Enter campus map filename: ");
    if (!map.loadMap(mapFile)) {
        cout << "Warning: continuing without a loaded map.\n";
    }

    int choice;
    do {
        printMenu();
        choice = getInt("");

        switch (choice) {

        // 1 – display map
        case 1:
            map.displayMap();
            break;

        // 2 - explore location
        case 2: {
            int r = getInt("Enter row: ");
            int c = getInt("Enter col: ");

            char loc = map.getLocation(r, c);
            if (loc == '\0') {
                cout << "Invalid coordinates.\n";
                break;
            }

            cout << "\nLocation Type: " << map.getLocationType(r, c) << "\n";

            if (map.isBlocked(r, c)) {
                cout << "This location is blocked.\n";
            } else {
                map.displayNeighbors(r, c);
            }
            break;
        }

        // 3 – add student
        case 3: {
            Student s;
            s.id    = getInt("Enter student ID: ");
            s.name  = getLine("Enter name: ");
            s.major = getLine("Enter major: ");
            s.gpa   = getFloat("Enter GPA: ");
            students.addStudent(s);
            cout << "Student added.\n";
            break;
        }

        // 4 – search student
        case 4: {
            int id = getInt("Enter student ID to search: ");
            Student* result = students.searchStudent(id);
            if (result) {
                cout << "\nFound:\n"
                     << "  ID:    " << result->id    << "\n"
                     << "  Name:  " << result->name  << "\n"
                     << "  Major: " << result->major << "\n"
                     << "  GPA:   " << result->gpa   << "\n";
            } else {
                cout << "Student ID " << id << " not found.\n";
            }
            break;
        }

        // 5 – display all students
        case 5:
            students.displayStudents();
            break;

        // 6 – exit
        case 6:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please enter 1-6.\n";
        }

    } while (choice != 6);

    return 0;
}
