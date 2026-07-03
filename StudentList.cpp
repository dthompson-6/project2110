#include "StudentList.h"
#include <iostream>
using namespace std;

StudentList::StudentList() {
    head = nullptr;
}

void StudentList::addStudent(Student s) {
    Node* n = new Node{s, nullptr};

    if (!head) {
        head = n;
        return;
    }

    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

Student* StudentList::searchStudent(int id) {
    Node* cur = head;

    while (cur) {
        if (cur->data.id == id)
            return &cur->data;
        cur = cur->next;
    }

    return nullptr;
}

void StudentList::displayStudents() {
    Node* cur = head;

    if (!cur) {
        cout << "No students.\n";
        return;
    }

    while (cur) {
        cout << "ID: " << cur->data.id << "\n"
             << "Name: " << cur->data.name << "\n"
             << "Major: " << cur->data.major << "\n"
             << "GPA: " << cur->data.gpa << "\n"
             << "-----------------\n";
        cur = cur->next;
    }
}

void StudentList::removeStudent(int id) {
    if (!head) return;

    if (head->data.id == id) {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }

    Node* cur = head;
    while (cur->next && cur->next->data.id != id)
        cur = cur->next;

    if (cur->next) {
        Node* t = cur->next;
        cur->next = t->next;
        delete t;
    }
}

void StudentList::sortByID() {
    if (!head) return;

    bool swapped;
    do {
        swapped = false;
        Node* cur = head;

        while (cur->next) {
            if (cur->data.id > cur->next->data.id) {
                swap(cur->data, cur->next->data);
                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);
}

Node* StudentList::getHead() {
    return head;
}

StudentList::~StudentList() {
    Node* cur = head;

    while (cur) {
        Node* t = cur;
        cur = cur->next;
        delete t;
    }
}