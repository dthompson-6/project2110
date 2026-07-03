#include "QueueSystem.h"
#include <iostream>
using namespace std;

QueueSystem::QueueSystem() {
    front = rear = nullptr;
}

bool QueueSystem::isEmpty() {
    return front == nullptr;
}

void QueueSystem::addRequest(Request r) {
    QNode* newNode = new QNode;
    newNode->data = r;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Request added to queue.\n";
}

void QueueSystem::processRequest() {
    if (isEmpty()) {
        cout << "No pending requests.\n";
        return;
    }

    QNode* temp = front;

    cout << "Processing Request:\n";
    cout << "Student ID: " << temp->data.studentID << endl;
    cout << "Issue: " << temp->data.issue << endl;

    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete temp;
}

void QueueSystem::displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    QNode* current = front;

    cout << "\nPending Advising Requests:\n";

    while (current != nullptr) {
        cout << "ID: " << current->data.studentID
             << " | Issue: " << current->data.issue << endl;
        current = current->next;
    }
}