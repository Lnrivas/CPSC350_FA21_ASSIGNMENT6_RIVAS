/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This is the header .h file for the Faculty class
*/
#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include "GenLinkedList.h"
using namespace std;

class Faculty {
public:
  Faculty();
  Faculty(int fFacultyID, string fName, string fLevel, string fDepartment, DoublyLinkedList<int>* fIDsOfAdvisees);
  ~Faculty();
  int getFacultyId();
  void setFacultyID(int fFacultyID);
  string getName();
  void setName(string fName);
  string getLevel();
  void setLevel(string fLevel);
  string getDepartment();
  void setDepartment(string fDepartment);
  DoublyLinkedList<int>* getIDsOfAdvisees();
  void setIDsOfAdvisees(DoublyLinkedList<int>* fIDsOfAdvisees);
  bool operator==(const Faculty& f); //overloaded equality operator
  bool operator<(const Faculty& f); //overloaded less than operator
  bool operator>(const Faculty& f); //overloaded greater than operator
private:
  int facultyID; // an integer Faculty ID
  string name; // a String name
  string level; // String level (lecturer, assistant prof, associate prof, etc)
  string department; // a String department
  DoublyLinkedList<int>* IDsOfAdvisees; // a list of integers corresponding to all of the faculty member’s advisees’ ids
};

#endif
