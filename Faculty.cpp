/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This is the implementation .cpp file for the Faculty class.
*/
#include "Faculty.h"

Faculty::Faculty() {
  facultyID = 0;
  name = "Unnamed Faculty";
  level = "lecturer";
  department = "Computer Science";
  IDsOfAdvisees = new DoublyLinkedList<int>();
}

Faculty::Faculty(int fFacultyID, string fName, string fLevel, string fDepartment, DoublyLinkedList<int>* fIDsOfAdvisees) {
  facultyID = fFacultyID;
  name = fName;
  level = fLevel;
  department = fDepartment;
  IDsOfAdvisees = fIDsOfAdvisees;
}

Faculty::~Faculty() {

}

int Faculty::getFacultyId() {
  return facultyID;
}

void Faculty::setFacultyID(int fFacultyID) {
  facultyID = fFacultyID;
}

string Faculty::getName() {
  return name;
}

void Faculty::setName(string fName) {
  name = fName;
}

string Faculty::getLevel() {
  return level;
}

void Faculty::setLevel(string fLevel) {
  level = fLevel;
}

string Faculty::getDepartment() {
  return department;
}

void Faculty::setDepartment(string fDepartment) {
  department = fDepartment;
}

DoublyLinkedList<int>* Faculty::getIDsOfAdvisees() { //check if this method works
  return IDsOfAdvisees;
}

void Faculty::setIDsOfAdvisees(DoublyLinkedList<int>* fIDsOfAdvisees) { //check if this method works
  IDsOfAdvisees = fIDsOfAdvisees;
}

bool Faculty::operator==(const Faculty& f) { //overloaded equality operator
  return (facultyID == f.facultyID);
}

bool Faculty::operator<(const Faculty& f) { //overloaded less than operator
  return (facultyID < f.facultyID);
}

bool Faculty::operator>(const Faculty& f) { //overloaded greater than operator
  return (facultyID > f.facultyID);
}
