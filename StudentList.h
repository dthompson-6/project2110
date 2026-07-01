#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>
using namespace std;
struct Student{
  int id;
  string name;
  string major;
  float gpa;
};

struct Node{
  Student data;
  Node* next;
};

class StudentList{
  private:
    Node* head;

    public:
      StudentList();
      void addStudent (Student s);
      Student* searchStudent(int id);
      void displayStudents();
};
#endif
