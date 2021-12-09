/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This is the main file, where our main method lives. If facultyTable and or studentTable files exist, read them to create a database.
 * If not, make new empty database. Gives the user 14 menu options for manipulating the database. Saves database back to those 2 files at the end.
*/
#include "Simulation.h"

int main(int argc, char** argv) {
  Simulation* s = new Simulation();
  BST<Faculty>* masterFaculty = new BST<Faculty>();
  BST<Student>* masterStudent = new BST<Student>();
  int option = 0;
  GenStack<string*>* databaseChanges = new GenStack<string*>();
  if (s->fileExists("facultyTable")) { //if a "facultyTable" file exists, read it into the masterFaculty BST
    s->readFacultyTable(masterFaculty);
  }
  if (s->fileExists("studentTable")) { //if a "studentTable" file exists, read it into the masterStudent BST
    s->readStudentTable(masterStudent);
  }
  while (option != 14) {
    option = s->showMenuToUser();
    if (option == 1) { // 1. Print all students and their information (sorted by ascending id #)
      masterStudent->studentPrintNodes();
    } else if (option == 2) { // 2. Print all faculty and their information (sorted by ascending id #)
      masterFaculty->facultyPrintNodes();
    } else if (option == 3) { // 3. Find and display student information given the students id
      s->printStudent(masterStudent);
    } else if (option == 4) { // 4. Find and display faculty information given the faculty id
      s->printFaculty(masterFaculty);
    } else if (option == 5) { // 5. Given a student’s id, print the name and info of their faculty advisor
      s->printAdvisorInfo(masterStudent, masterFaculty);
    } else if (option == 6) { // 6. Given a faculty id, print ALL the names and info of his/her advisees.
      s->printAllAdvisees(masterStudent);
    } else if (option == 7) { // 7. Add a new student
      s->addStudent(databaseChanges, masterStudent, masterFaculty);
    } else if (option == 8) { // 8. Delete a student given the id
      s->deleteStudent(databaseChanges, masterFaculty, masterStudent);
    } else if (option == 9) { // 9. Add a new faculty member
      s->addFaculty(databaseChanges, masterFaculty);
    } else if (option == 10) { // 10. Delete a faculty member given the id.
      s->deleteFaculty(databaseChanges, masterFaculty);
    } else if (option == 11) { // 11. Change a student’s advisor given the student id and the new faculty id.
      s->changeAdvisor(databaseChanges, masterStudent, masterFaculty);
    } else if (option == 12) { // 12. Remove an advisee from a faculty member given the ids
      s->removeAdvisee(databaseChanges, masterStudent, masterFaculty);
    } else if (option == 13) { // 13. Rollback (should allow the user to roll back the last 5 commands that CHANGED the DB)
      s->undo(databaseChanges, masterFaculty, masterStudent);
    }
  } // 14. Exit (If the user chooses to exit, write the faculty and student tables back out to the “facultyTable” and “studentTable” files (see appendix A), clean up, and quit gracefully)
  s->saveDatabase(masterFaculty, masterStudent);
  delete masterFaculty;
  delete masterStudent;
  delete s;
  delete databaseChanges;
  return 0;
}
