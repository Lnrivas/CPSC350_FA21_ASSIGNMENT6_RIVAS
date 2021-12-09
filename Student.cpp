/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This is the implementation .cpp file for the Student class.
*/
#include "Student.h"

Student::Student() {
  studentID = 0;
  name = "Unnamed Student";
  level = "Freshman";
  major = "Undeclared";
  GPA = 4.0;
  advisor = 0;
}

Student::Student(int sStudentID, string sName, string sLevel, string sMajor, double sGPA, int sAdvisor) {
  studentID = sStudentID;
  name = sName;
  level = sLevel;
  major = sMajor;
  GPA = sGPA;
  advisor = sAdvisor;
}

Student::~Student() {

}

int Student::getStudentID() {
  return studentID;
}

void Student::setStudentID(int sStudentID) {
  studentID = sStudentID;
}

string Student::getName() {
  return name;
}

void Student::setName(string sName) {
  name = sName;
}

string Student::getLevel() {
  return level;
}

void Student::setLevel(string sLevel) {
  level = sLevel;
}

string Student::getMajor() {
  return major;
}

void Student::setMajor(string sMajor) {
  major = sMajor;
}

double Student::getGPA() {
  return GPA;
}

void Student::setGPA(double sGPA) {
  GPA = sGPA;
}

int Student::getAdvisor() {
  return advisor;
}

void Student::setAdvisor(int sAdvisor) {
  advisor = sAdvisor;
}

bool Student::operator==(const Student& s) { //overloaded equality operator
  return (studentID == s.studentID);
}

bool Student::operator<(const Student& s) { //overloaded less than operator
  return (studentID < s.studentID);
}

bool Student::operator>(const Student& s) { //overloaded greater than operator
  return (studentID > s.studentID);
}
