/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This is the implementation .cpp file for the Simulation class.
*/
#include "Simulation.h"

Simulation::Simulation() {

}

Simulation::~Simulation() {

}

bool Simulation::fileExists(const string& name) {
    ifstream f(name.c_str());
    return f.good();
}

void Simulation::readFacultyTable(BST<Faculty>* masterFaculty) {
  fstream fileStream;
  string stringID = "";
  int facultyID = 0;
  string name = "";
  string level = "";
  string department = "";
  string stringAdvisees = "";
  fileStream.open("facultyTable", ios::in); // opens file facultyTable in read mode
  if (fileStream.fail()) { // ensures file was opened incorrectly
    throw runtime_error("Input file not opened!");
	}
  while (true) { // loops through entire file, line by line, until the end is reached
    Faculty f;
    DoublyLinkedList<int>* IDsOfAdvisees = new DoublyLinkedList<int>;
    getline(fileStream, stringID); // reads facultyID
    facultyID = stoi(stringID);
    f.setFacultyID(facultyID);
    getline(fileStream, name); // reads name
    f.setName(name);
    getline(fileStream, level); // reads level
    f.setLevel(level);
    getline(fileStream, department); // reads department
    f.setDepartment(department);
    getline(fileStream, stringAdvisees); // reads IDsOfAdvisees
    string temp = "";
    for (int i = 0; i < stringAdvisees.size(); ++i) { //converts string of adviseesIds to DoublyLinkedList<int>
      if (stringAdvisees[i] == ',' || stringAdvisees[i] == ' ') {
        IDsOfAdvisees->insertBack(stoi(temp));
        temp = "";
        continue;
      } else {
        temp += stringAdvisees[i];
      }
    }
    f.setIDsOfAdvisees(IDsOfAdvisees);
    masterFaculty->insert(f);
		if (fileStream.eof()) { //breaks out of loop once the entire file has been read.
      break;
    }
	}
	fileStream.close();
}

void Simulation::readStudentTable(BST<Student>* masterStudent) {
  fstream fileStream;
  string stringID = "";
  int studentID = 0;
  string name = "";
  string level = "";
  string major = "";
  string stringGPA = "";
  double GPA = 0.0;
  string stringAdvisor = "";
  int advisor = 0;
  fileStream.open("studentTable", ios::in); // opens file studentTable in read mode
  if (fileStream.fail()) { // ensures file was opened incorrectly
    throw runtime_error("Input file not opened!");
	}
  while (true) { // loops through entire file, line by line, until the end is reached
    Student s;
    getline(fileStream, stringID); // reads studentID
    studentID = stoi(stringID);
    s.setStudentID(studentID);
    getline(fileStream, name); // reads name
    s.setName(name);
    getline(fileStream, level); // reads level
    s.setLevel(level);
    getline(fileStream, major); // reads major
    s.setMajor(major);
    getline(fileStream, stringGPA); // reads GPA
    GPA = stod(stringGPA);
    s.setGPA(GPA);
    getline(fileStream, stringAdvisor);
    advisor = stoi(stringAdvisor);
    s.setAdvisor(advisor);
    masterStudent->insert(s);
		if (fileStream.eof()) { //breaks out of loop once the entire file has been read.
      break;
    }
	}
	fileStream.close();
}

int Simulation::showMenuToUser() {
  string input;
  int result;
  cout << "\tChoose an option (1-14) to manipulate the database." << endl;
  cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
  cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << "3. Find and display student information given the students id" << endl;
  cout << "4. Find and display faculty information given the faculty id" << endl;
  cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
  cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Delete a student given the id" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member given the id." << endl;
  cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
  cout << "12. Remove an advisee from a faculty member given the ids" << endl;
  cout << "13. Rollback (should allow the user to roll back the last 5 commands that CHANGED the DB)" << endl;
  cout << "14. Exit (write the faculty and student tables back out to the “facultyTable” and “studentTable” files, clean up, and quit gracefully)" << endl;
  cin >> input;
  if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10" || input == "11" || input == "12" || input == "13" || input == "14") {
    result = stoi(input);
  } else { //if invalid input (not 1-14)
    throw runtime_error("Invalid input! Must enter a number 1 through 14!");
  }
  return result;
}

void Simulation::printStudent(BST<Student>* masterStudent) {
  int input;
  cout << "Enter the ID number of the student you would like to print:" << endl;
  cin >> input;
  masterStudent->printStudentNode(input);
}

void Simulation::printFaculty(BST<Faculty>* masterFaculty) {
  int input;
  cout << "Enter the ID number of the faculty you would like to print:" << endl;
  cin >> input;
  masterFaculty->printFacultyNode(input);
}

void Simulation::printAdvisorInfo(BST<Student>* masterStudent, BST<Faculty>* masterFaculty) {
  int input;
  int advisorID;
  cout << "Enter a student ID to print their advisor's info:" << endl;
  cin >> input;
  advisorID = masterStudent->findAdvisorID(input);
  masterFaculty->printFacultyNode(advisorID);
}

void Simulation::printAllAdvisees(BST<Student>* masterStudent) {
  int input;
  cout << "Enter a Faculty ID to print the info for all of their advisees:" << endl;
  cin >> input;
  masterStudent->printAllStudentsGivenAdvisor(input);
}

void Simulation::addStudent(GenStack<string*>* databaseChanges, BST<Student>* masterStudent, BST<Faculty>* masterFaculty) {
  Student s;
  string* stackInput = new string[2];
  int studentID;
  string name;
  string level;
  string major;
  double GPA;
  int advisor;
  stackInput[0] = "7";
  cout << "Enter the student ID for the new student:" << endl;
  cin >> studentID;
  s.setStudentID(studentID);
  stackInput[1] = to_string(studentID);
  cout << "Enter the name for the new student:" << endl;
  getline(cin, name);
  getline(cin, name);
  s.setName(name);
  cout << "Enter the level for the new student:" << endl;
  cin >> level;
  s.setLevel(level);
  cout << "Enter the major for the new student:" << endl;
  cin >> major;
  s.setMajor(major);
  cout << "Enter the GPA for the new student:" << endl;
  cin >> GPA;
  s.setGPA(GPA);
  cout << "Enter the advisor's ID for the new student:" << endl;
  cin >> advisor;
  s.setAdvisor(advisor);
  masterStudent->insert(s);
  masterFaculty->addAdvisee(advisor, studentID);
  databaseChanges->push(stackInput);
}

void Simulation::deleteStudent(GenStack<string*>* databaseChanges, BST<Faculty>* masterFaculty, BST<Student>* masterStudent) { //removes student as an advisee, then deletes student from database
  int studentID;
  string name;
  string level;
  string major;
  double GPA;
  int advisorID;
  string* stackInput = new string[7];
  stackInput[0] = "8";
  cout << "Enter the Student ID of the student to be deleted:" << endl;
  cin >> studentID;
  advisorID = masterStudent->findAdvisorID(studentID);
  stackInput[1] = to_string(studentID);
  stackInput[2] = masterStudent->getStudentName(studentID);
  stackInput[3] = masterStudent->getStudentLevel(studentID);
  stackInput[4] = masterStudent->getStudentMajor(studentID);
  stackInput[5] = masterStudent->getStudentGPA(studentID);
  stackInput[6] = to_string(advisorID);
  databaseChanges->push(stackInput);
  masterFaculty->removeAdvisee(advisorID, studentID);
  masterStudent->deleteStudentNode(studentID);
}

void Simulation::addFaculty(GenStack<string*>* databaseChanges, BST<Faculty>* masterFaculty) {
  Faculty f;
  int facultyID;
  string name;
  string level;
  string department;
  string stringAdvisees;
  DoublyLinkedList<int>* IDsOfAdvisees = new DoublyLinkedList<int>;
  string* stackInput = new string[2];
  cout << "Enter the Faculty ID for the new faculty:" << endl;
  cin >> facultyID;
  f.setFacultyID(facultyID);
  cout << "Enter the name for the new faculty:" << endl;
  getline(cin, name);
  getline(cin, name);
  f.setName(name);
  cout << "Enter the level for the new faculty:" << endl;
  cin >> level;
  f.setLevel(level);
  cout << "Enter the department for the new faculty:" << endl;
  cin >> department;
  f.setDepartment(department);
  cout << "Enter the list of advisees for the new faculty(enter each advisee ID directly followed by a comma):" << endl;
  getline(cin, stringAdvisees);
  getline(cin, stringAdvisees);
  string temp = "";
  for (int i = 0; i < stringAdvisees.size(); ++i) { //converts string of adviseesIds to DoublyLinkedList<int>
    if (stringAdvisees[i] == ',' || stringAdvisees[i] == ' ') {
      IDsOfAdvisees->insertBack(stoi(temp));
      temp = "";
      continue;
    } else {
      temp += stringAdvisees[i];
    }
  }
  f.setIDsOfAdvisees(IDsOfAdvisees);
  masterFaculty->insert(f);
  stackInput[0] = "9";
  stackInput[1] = to_string(facultyID);
  databaseChanges->push(stackInput);
}

void Simulation::deleteFaculty(GenStack<string*>* databaseChanges, BST<Faculty>* masterFaculty) {
  int facultyID;
  DoublyLinkedList<int>* IDsOfAdvisees = new DoublyLinkedList<int>;
  string* stackInput = new string[5];
  cout << "Enter the Faculty ID of the faculty to be deleted:" << endl;
  cin >> facultyID;
  IDsOfAdvisees = masterFaculty->getAllAdvisees(facultyID);
  stackInput[0] = "10";
  stackInput[1] = to_string(facultyID);
  stackInput[2] = masterFaculty->getFacultyName(facultyID);
  stackInput[3] = masterFaculty->getFacultyLevel(facultyID);
  stackInput[4] = masterFaculty->getFacultyDepartment(facultyID);
  databaseChanges->push(stackInput);
  masterFaculty->deleteFacultyNode(facultyID);
  addAdvisees(masterFaculty, IDsOfAdvisees);
}

void Simulation::changeAdvisor(GenStack<string*>* databaseChanges, BST<Student>* masterStudent, BST<Faculty>* masterFaculty) {
  int studentID;
  int facultyID;
  int originalAdvisorID;
  string* stackInput = new string[4];
  cout << "Enter the Student ID of a student to change their advisor:" << endl;
  cin >> studentID;
  cout << "Enter the faculty ID for their new advisor:" << endl;
  cin >> facultyID;
  originalAdvisorID = masterStudent->findAdvisorID(studentID);
  stackInput[0] = "11";
  stackInput[1] = to_string(studentID);
  stackInput[2] = to_string(facultyID);
  stackInput[3] = to_string(originalAdvisorID);
  masterFaculty->removeAdvisee(originalAdvisorID, studentID); //remove the student as an advisee of the original advisor
  masterStudent->changeAdvisorOfStudent(studentID, facultyID); //changes the advisor of the student
  masterFaculty->addAdvisee(facultyID, studentID); //adds student as an advisee for their new advisor
  databaseChanges->push(stackInput);
}

void Simulation::removeAdvisee(GenStack<string*>* databaseChanges, BST<Student>* masterStudent, BST<Faculty>* masterFaculty) {
  int facultyID;
  int studentID;
  int newAdvisorID;
  string* stackInput = new string[4];
  cout << "Enter the Faculty ID of the faculty to remove an advisee from:" << endl;
  cin >> facultyID;
  cout << "Enter the Student ID of the advisee to remove:" << endl;
  cin >> studentID;
  cout << "Enter the ID of a new advisor to assign to the student:" << endl;
  cin >> newAdvisorID;
  stackInput[0] = "12";
  stackInput[1] = to_string(facultyID);
  stackInput[2] = to_string(studentID);
  stackInput[3] = to_string(newAdvisorID);
  masterFaculty->removeAdvisee(facultyID, studentID);
  masterStudent->changeAdvisorOfStudent(studentID, newAdvisorID);
  masterFaculty->addAdvisee(newAdvisorID, studentID);
  databaseChanges->push(stackInput);
}

void Simulation::addAdvisees(BST<Faculty>* masterFaculty, DoublyLinkedList<int>* IDsOfAdvisees) {
  masterFaculty->addAllAdviseesToNewAdvisor(IDsOfAdvisees);
}

void Simulation::undo(GenStack<string*>* databaseChanges, BST<Faculty>* masterFaculty, BST<Student>* masterStudent) {
  if (databaseChanges->isEmpty()) {
    cout << "Nothing to undo!" << endl;
    return;
  }
  int undoOption = stoi(databaseChanges->peek()[0]);
  if (undoOption == 7) { //undo addStudent()
    undoAddStudent(masterFaculty, masterStudent, stoi(databaseChanges->peek()[1]));
  } else if (undoOption == 8) {
    undoDeleteStudent(masterFaculty, masterStudent, stoi(databaseChanges->peek()[1]), databaseChanges->peek()[2], databaseChanges->peek()[3], databaseChanges->peek()[4], stod(databaseChanges->peek()[5]), stoi(databaseChanges->peek()[6]));
  } else if (undoOption == 9) {
    undoAddFaculty(masterFaculty, stoi(databaseChanges->peek()[1]));
  } else if (undoOption == 10) {
    undoDeleteFaculty(masterFaculty, stoi(databaseChanges->peek()[1]), databaseChanges->peek()[2], databaseChanges->peek()[3], databaseChanges->peek()[4]);
  } else if (undoOption == 11) {
    undoChangeAdvisor(masterStudent, masterFaculty, stoi(databaseChanges->peek()[1]), stoi(databaseChanges->peek()[2]), stoi(databaseChanges->peek()[3]));
  } else if (undoOption == 12) {
    undoRemoveAdvisee(masterStudent, masterFaculty, stoi(databaseChanges->peek()[1]), stoi(databaseChanges->peek()[2]), stoi(databaseChanges->peek()[3]));
  }
  databaseChanges->pop();
}

void Simulation::undoAddStudent(BST<Faculty>* masterFaculty, BST<Student>* masterStudent, int studentID) {
  int advisorID;
  advisorID = masterStudent->findAdvisorID(studentID);
  masterFaculty->removeAdvisee(advisorID, studentID);
  masterStudent->deleteStudentNode(studentID);
}

void Simulation::undoDeleteStudent(BST<Faculty>* masterFaculty, BST<Student>* masterStudent, int studentID, string name, string level, string major, double GPA, int advisor) {
  Student s;
  s.setStudentID(studentID);
  s.setName(name);
  s.setLevel(level);
  s.setMajor(major);
  s.setGPA(GPA);
  s.setAdvisor(advisor);
  masterStudent->insert(s);
  masterFaculty->addAdvisee(advisor, studentID);
}

void Simulation::undoAddFaculty(BST<Faculty>* masterFaculty, int facultyID) {
  DoublyLinkedList<int>* IDsOfAdvisees = new DoublyLinkedList<int>;
  IDsOfAdvisees = masterFaculty->getAllAdvisees(facultyID);
  masterFaculty->deleteFacultyNode(facultyID);
  addAdvisees(masterFaculty, IDsOfAdvisees);
}

void Simulation::undoDeleteFaculty(BST<Faculty>* masterFaculty, int facultyID, string name, string level, string department) {
  Faculty f;
  DoublyLinkedList<int>* IDsOfAdvisees = new DoublyLinkedList<int>;
  f.setFacultyID(facultyID);
  f.setName(name);
  f.setLevel(level);
  f.setDepartment(department);
  f.setIDsOfAdvisees(IDsOfAdvisees);
  masterFaculty->insert(f);
}

void Simulation::undoChangeAdvisor(BST<Student>* masterStudent, BST<Faculty>* masterFaculty, int studentID, int facultyID, int originalAdvisorID) {
  masterFaculty->removeAdvisee(originalAdvisorID, studentID); //remove the student as an advisee of the original advisor
  masterStudent->changeAdvisorOfStudent(studentID, facultyID); //changes the advisor of the student
  masterFaculty->addAdvisee(facultyID, studentID); //adds student as an advisee for their new advisor
}

void Simulation::undoRemoveAdvisee(BST<Student>* masterStudent, BST<Faculty>* masterFaculty, int facultyID, int studentID, int newAdvisorID) {
  masterFaculty->removeAdvisee(facultyID, studentID);
  masterStudent->changeAdvisorOfStudent(studentID, newAdvisorID);
  masterFaculty->addAdvisee(newAdvisorID, studentID);
}

void Simulation::saveDatabase(BST<Faculty>* masterFaculty, BST<Student>* masterStudent) {
  fstream fileStream;
  string forFile = "";
  fileStream.open("facultyTable", ios::out); // opens facultyTable in write mode -> saves faculty BST
  if (fileStream.fail()) { // checks if file was opened incorrectly
    throw runtime_error("Output file not opened!");
  } else { // if file was opened correctly
    while (!masterFaculty->isEmpty()) {
      fileStream << masterFaculty->getFacultyInfo();
    }
  }
  fileStream.close();
  fileStream.open("studentTable", ios::out); // opens studentTable in write mode -> saves student BST
  if (fileStream.fail()) { // checks if file was opened incorrectly
    throw runtime_error("Output file not opened!");
  } else { // if file was opened correctly
    while (!masterStudent->isEmpty()) {
      fileStream << masterStudent->getStudentInfo();
    }
  }
  fileStream.close();
}
