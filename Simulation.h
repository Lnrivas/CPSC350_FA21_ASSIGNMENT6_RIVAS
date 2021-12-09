/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This is the header .h file for the Simulation class
*/
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
using namespace std;

class Simulation {
public:
  Simulation();
  ~Simulation();
  bool fileExists(const string& name);
  void readFacultyTable(BST<Faculty>* masterFaculty);
  void readStudentTable(BST<Student>* masterStudent);
  int showMenuToUser();
  void printStudent(BST<Student>* masterStudent);
  void printFaculty(BST<Faculty>* masterFaculty);
  void printAdvisorInfo(BST<Student>* masterStudent, BST<Faculty>* masterFaculty);
  void printAllAdvisees(BST<Student>* masterStudent);
  void addStudent(GenStack<string*>* databaseChanges, BST<Student>* masterStudent, BST<Faculty>* masterFaculty);
  void deleteStudent(GenStack<string*>* databaseChanges, BST<Faculty>* masterFaculty, BST<Student>* masterStudent);
  void addFaculty(GenStack<string*>* databaseChanges, BST<Faculty>* masterFaculty);
  void deleteFaculty(GenStack<string*>* databaseChanges, BST<Faculty>* masterFaculty);
  void changeAdvisor(GenStack<string*>* databaseChanges,BST<Student>* masterStudent, BST<Faculty>* masterFaculty);
  void removeAdvisee(GenStack<string*>* databaseChanges, BST<Student>* masterStudent, BST<Faculty>* masterFaculty);
  void addAdvisees(BST<Faculty>* masterFaculty, DoublyLinkedList<int>* IDsOfAdvisees);
  void undo(GenStack<string*>* databaseChanges, BST<Faculty>* masterFaculty, BST<Student>* masterStudent);
  void undoAddStudent(BST<Faculty>* masterFaculty, BST<Student>* masterStudent, int studentID);
  void undoDeleteStudent(BST<Faculty>* masterFaculty, BST<Student>* masterStudent, int studentID, string name, string level, string major, double GPA, int advisor);
  void undoAddFaculty(BST<Faculty>* masterFaculty, int facultyID);
  void undoDeleteFaculty(BST<Faculty>* masterFaculty, int facultyID, string name, string level, string department);
  void undoChangeAdvisor(BST<Student>* masterStudent, BST<Faculty>* masterFaculty, int studentID, int facultyID, int originalAdvisorID);
  void undoRemoveAdvisee(BST<Student>* masterStudent, BST<Faculty>* masterFaculty, int facultyID, int studentID, int newAdvisorID);
  void saveDatabase(BST<Faculty>* masterFaculty, BST<Student>* masterStudent);
};
