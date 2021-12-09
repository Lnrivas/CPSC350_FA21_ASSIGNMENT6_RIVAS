/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This is the header .h file for the Student class
*/
#include <iostream>
using namespace std;

class Student {
public:
  Student();
  Student(int sStudentID, string sName, string sLevel, string sMajor, double sGPA, int sAdvisor);
  ~Student();
  int getStudentID();
  void setStudentID(int sStudentID);
  string getName();
  void setName(string sName);
  string getLevel();
  void setLevel(string sLevel);
  string getMajor();
  void setMajor(string sMajor);
  double getGPA();
  void setGPA(double sGPA);
  int getAdvisor();
  void setAdvisor(int sAdvisor);
  bool operator==(const Student& s); //overloaded equality operator
  bool operator<(const Student& s); //overloaded less than operator
  bool operator>(const Student& s); //overloaded greater than operator
private:
  int studentID; // a unique student ID (an integer)
  string name; // a String name field
  string level; // a string level field (Freshman, Sophomore, etc)
  string major; // a String major field,
  double GPA; // a double GPA field
  int advisor; // an integer advisor field which will contain the Faculty ID of their advisor
};
