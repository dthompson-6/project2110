#include "CampusMap.h"
#include "StudentList.h"
#include "Filemanager.h"
#include "QueueSystem.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ───────────────────────── Helpers ─────────────────────────

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getInt(const string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) { clearInput(); return x; }
        cout << "Invalid input.\n";
        clearInput();
    }
}

float getFloat(const string& prompt) {
    float x;
    while (true) {
        cout << prompt;
        if (cin >> x) { clearInput(); return x; }
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

// ───────────────────────── Menu ─────────────────────────

void printMenu() {
    cout << "\n========== CAMPUS MANAGEMENT SYSTEM ==========\n"
         << "0. Choose Files (Map + Students)\n\n"

         << "---- CAMPUS MAP ----\n"
         << "1. Display Map\n"
         << "2. Explore Location\n"
         << "3. Show Neighbors\n"
         << "4. Count Campus Objects\n\n"

         << "---- STUDENTS ----\n"
         << "5. Add Student (Save to File)\n"
         << "6. Remove Student\n"
         << "7. Search Student\n"
         << "8. Display All Students\n"
         << "9. Sort Students by ID\n\n"

         << "---- ADVISOR QUEUE ----\n"
         << "10. Add Advising Request\n"
         << "11. Process Request\n"
         << "12. Display Queue\n\n"

         << "---- SYSTEM ----\n"
         << "13. Load Students Again\n"
         << "14. Campus Statistics\n"
         << "15. Exit\n"
         << "=============================================\n"
         << "Choice: ";
}

// ───────────────────────── MAIN ─────────────────────────

int main() {

    CampusMap map;
    StudentList students;
    FileManager fileManager;
    QueueSystem queue;

    string mapFile = "";
    string studentFile = "";

    int choice;

    do {
        printMenu();
        choice = getInt("");

        switch (choice) {

        // ───── FILE SELECTION ─────
        case 0: {
            mapFile = getLine("Enter campus map file: ");
            if (map.loadMap(mapFile))
                cout << "Map loaded successfully.\n";
            else
                cout << "Failed to load map.\n";

            studentFile = getLine("Enter student file: ");
            fileManager.loadStudents(studentFile, students);

            cout << "Students loaded.\n";
            break;
        }

        // ───── MAP ─────
        case 1:
            map.displayMap();
            break;

        case 2: {
            int r = getInt("Row: ");
            int c = getInt("Col: ");

            char loc = map.getLocation(r, c);

            if (loc == '\0') {
                cout << "Invalid coordinates.\n";
                break;
            }

            cout << "Type: " << map.getLocationType(r, c) << endl;

            if (map.isBlocked(r, c))
                cout << "Location is blocked.\n";
            else
                map.displayNeighbors(r, c);

            break;
        }

        case 3: {
            int r = getInt("Row: ");
            int c = getInt("Col: ");
            map.displayNeighbors(r, c);
            break;
        }

        case 4:
            map.countObjects();
            break;

        // ───── STUDENTS ─────
        case 5: {
            if (studentFile == "") {
                cout << "Select files first (option 0).\n";
                break;
            }

            Student s;
            s.id = getInt("ID: ");
            s.name = getLine("Name: ");
            s.major = getLine("Major: ");
            s.gpa = getFloat("GPA: ");

            students.addStudent(s);
            fileManager.saveStudent(studentFile, s);

            cout << "Student added & saved.\n";
            break;
        }

        case 6: {
            int id = getInt("Enter ID to remove: ");
            students.removeStudent(id);
            cout << "Student removed.\n";
            break;
        }

        case 7: {
            int id = getInt("Enter ID: ");
            Student* s = students.searchStudent(id);

            if (s)
                cout << "ID: " << s->id << "\nName: " << s->name
                     << "\nMajor: " << s->major << "\nGPA: " << s->gpa << endl;
            else
                cout << "Not found.\n";

            break;
        }

        case 8:
            students.displayStudents();
            break;

        case 9:
            students.sortByID();
            cout << "Sorted.\n";
            break;

        // ───── QUEUE ─────
        case 10: {
            Request r;
            r.studentID = getInt("Student ID: ");
            r.issue = getLine("Issue: ");
            queue.addRequest(r);
            break;
        }

        case 11:
            queue.processRequest();
            break;

        case 12:
            queue.displayQueue();
            break;

        // ───── SYSTEM ─────
        case 13:
            if (studentFile == "") {
                cout << "Select files first.\n";
                break;
            }
            fileManager.loadStudents(studentFile, students);
            cout << "Reloaded students.\n";
            break;

        case 14:
            cout << "\n--- CAMPUS STATISTICS ---\n";
            students.displayStudents();
            cout << "\nQueue active.\n";
            map.countObjects();
            break;

        case 15:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 15);

    return 0;
}