#ifndef QUEUESYSTEM_H
#define QUEUESYSTEM_H

#include <string>
using namespace std;

struct Request {
    int studentID;
    string issue;
};

struct QNode {
    Request data;
    QNode* next;
};

class QueueSystem {
private:
    QNode* front;
    QNode* rear;

public:
    QueueSystem();

    void addRequest(Request r);
    void processRequest();
    void displayQueue();

    bool isEmpty();
};

#endif