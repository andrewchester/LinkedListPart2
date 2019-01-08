#pragma once
#include <iostream>
#include "node.h"
#include "student.h"

class LinkedList {
 private:
  Node* first; //First node in list
  Node* last; //Last node in list
  int length; //Length of list
 public:
  LinkedList(); //Constructor, defaults first, last, and length to 0

  friend std::ostream& operator<<(std::ostream& os, const LinkedList& list); //Printing out the list using << 

  Node* operator[] (int); //Overloads the [] operator
  Node* at(int index); //Accesses a node in the list

  void append(Student*); //Appends a value to the end, just uses insert() at the end
  void insert(int index, Student*); //Inserts a value to a spot in the list
  void remove(int index);  //Removes a node at an index
  void deleteStudent(Student*); //Deletes all students matching the pointer
  void deleteStudent(char*); //Deletes all students matching the char*
  void clear(); //Delete's all nodes from the array
  int size(); //Returns the size of the list

  Node* end(); //Returns the last node in the list
  Node* begin(); //Returns the first node in the list
};