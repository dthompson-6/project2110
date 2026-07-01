#include "StudentList.h"
#include <iostream>
using namespace std;
StudentList::StudentList(){
  head=nullptr;
}

void StudentList::addStudent(Student s){
  Node* newNode = new Node;
  newNode->data = s;
  newNode->next = nullptr;
  
  if(head == nullptr){
    head = newNode;
  }
  else{
    Node * current = head;

    while(current->next !=nullptr){
      current = current->next;
    }
    current->next = newNode;
  }
}

Student * StudentList::searchStudent(int id){
  Node * current = head;
  while (current != nullptr)
  {
    if (current->data.id == id){
      return &(current->data);
    }
    current = current->next;
  }
  return nullptr;
}

void StudentList::displayStudents(){
  Node * current = head;
  while (current != nullptr){
    cout << current->data.id << " "
         << current->data.name << " "
         << current->data.major << " "
         << current->data.gpa << endl;
    current = current->next;
  }
}