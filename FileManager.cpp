#include "Filemanager.h"
#include <fstream>
#include <iostream>

using namespace std;

bool FileManager::loadStudents(const string& filename, StudentList& list) {
    ifstream in(filename);

    if (!in) {
        cout << "Cannot open file.\n";
        return false;
    }

    Student s;

    while (in >> s.id >> s.name >> s.major >> s.gpa) {
        list.addStudent(s);
    }

    return true;
}

bool FileManager::saveStudent(const string& filename, const Student& s) {
    ofstream out(filename, ios::app);

    if (!out) return false;

    out << s.id << " " << s.name << " "
        << s.major << " " << s.gpa << endl;

    return true;
}

bool FileManager::saveAllStudents(const string& filename, StudentList& list) {
    ofstream out(filename);

    if (!out) return false;

    Node* cur = list.getHead();

    while (cur) {
        out << cur->data.id << " "
            << cur->data.name << " "
            << cur->data.major << " "
            << cur->data.gpa << endl;

        cur = cur->next;
    }

    return true;
}

