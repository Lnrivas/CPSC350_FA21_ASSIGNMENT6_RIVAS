/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This .h file is a template class for a Binary Search Tree
*/
#ifndef BST_H
#define BST_H
#include <iostream>
#include <exception>
#include "Faculty.h"

using namespace std;

template <class T>
class TreeNode {
public:
  TreeNode();
  TreeNode(T key);
  virtual ~TreeNode(); //virtual means if u use inheretance u can overrride that in a subclass

  T key; //key = data
  TreeNode<T> *left;
  TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode() {
  left = NULL;
  right = NULL;
  key = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k) {
  left = NULL;
  right = NULL;
  key = k;
}

template <class T>
TreeNode<T>::~TreeNode() {
  left = NULL;
  right = NULL;
}

template <class T>
class BST {
public:
  BST();
  virtual ~BST();
  void insert(T value);
  bool contains(T value); //search
  bool deleteNode(T k);
  bool isEmpty();
  T* getMin();
  T* getMax();
  TreeNode<T> *getSuccessor(TreeNode<T> *d); //d represents the node we are going to delete
  void printNodes();
  void recPrint(TreeNode<T> *node);
  void facultyPrintNodes(); //added method for assignment 6
  void facultyRecPrint(TreeNode<T> *node); //added method for assignment 6
  void studentPrintNodes(); //added method for assignment 6
  void studentRecPrint(TreeNode<T> *node); //added method for assignment 6
  void printStudentNode(int studentID); //added method for assignment 6
  void printFacultyNode(int facultyID); //added method for assignment 6
  int findAdvisorID(int studentID); //added method for assignment 6
  void studentPrintNodesOfAdvisor(int advisorID, TreeNode<T>* node); //added method for assignment 6
  void printAllStudentsGivenAdvisor(int advisorID); //added method for assignment 6
  bool deleteStudentNode(int studentID); //added method for assignment 6
  bool deleteFacultyNode(int facultyID); //added method for assignment 6
  void changeAdvisorOfStudent(int studentID, int facultyID); //added method for assignment 6
  void removeAdvisee(int originalAdvisorID, int studentID); //added method for assignment 6
  void addAdvisee(int facultyID, int studentID); //added method for assignment 6
  DoublyLinkedList<int>* getAllAdvisees(int facultyID); //added method for assignment 6
  void addAllAdviseesToNewAdvisor(DoublyLinkedList<int>* IDsOfAdvisees); //added method for assignment 6
  string getStudentName(int studentID); //added method for assignment 6
  string getStudentLevel(int studentID); //added method for assignment 6
  string getStudentMajor(int studentID); //added method for assignment 6
  string getStudentGPA(int studentID); //added method for assignment 6
  string getFacultyName(int studentID); //added method for assignment 6
  string getFacultyLevel(int studentID); //added method for assignment 6
  string getFacultyDepartment(int studentID); //added method for assignment 6
  string getFacultyInfo(); //added method for assignment 6
  string getStudentInfo(); //added method for assignment 6
private:
  TreeNode<T> *root;
};

template <class T>
BST<T>::BST() {
  root = NULL;
}

template <class T>
BST<T>::~BST() {
  //research this
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node) {
  if (node == NULL) {
    return;
  }
  cout << node->key << endl;  //preorder traversal
  recPrint(node->left);
  recPrint(node->right);
}

template <class T>
 //this function prints the entire tree
 void BST<T>::printNodes() {
   recPrint(root);
 }

template <class T>
bool BST<T>::isEmpty() {
  return (root == NULL);
}

template <class T>
T* BST<T>::getMin() {
  if (isEmpty()) {
    return NULL;
  }
  TreeNode<T> *current = root;
  while (current->left != NULL) {
    current = current->left;
  }
  return &(current->key);
}

template <class T>
T* BST<T>::getMax() {
  if (isEmpty()) {
    return NULL;
  }
  TreeNode<T> *current = root;
  while (current->right != NULL) {
    current = current->right;
  }
  return &(current->key);
}

template <class T>
void BST<T>::insert(T value) {
  TreeNode<T> *node = new TreeNode<T>(value);
  if (isEmpty()) {
    root = node;
  } else {
    //tree is not empty
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;
    while (true) {
      parent = current; //so parent is always 1 above current
      if (value < current->key) {
        //we go left
        current = current->left;
        if (current == NULL) {
          //we found the insertion point
          parent->left = node;
          break;
        }
      } else {
        //we go right
        current = current->right;
        if(current == NULL) {
          //we found the insertion point
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::contains(T value) {
  if (isEmpty()) {
    return false;
  }
  TreeNode <T> *current = root;
  while(current->key != value) {
    if (value < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
    if (current == NULL) {
      return false;
    }
  }
  return true;
}

template <class T>
bool BST<T>::deleteNode(T k) {
  if (isEmpty()) {
    return false;
  }
  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;
  while (current->key != k) {
    parent = current;
    if(k < current->key) {
      isLeft = true;
      current = current->left;
    } else {
      isLeft = false;
      current = current->right;
    }
    if (current == NULL) {
      return false;
    }
  }
  //out of while loop means we found the node/value, now lets proceed to delete
  //no children, node to be deleted is a leaf
  if(current->left == NULL && current->right == NULL) {
    if (current == root) {
      root = NULL;
    } else if (isLeft) {
      parent->left = NULL;
    } else {
      parent->right = NULL;
    }
  } else if (current->right == NULL) {
    //node to be delete has a left child (no right)
    if (current == root) {
      root = current->left;
    } else if (isLeft) {
      parent->left = current->left;
    } else {
      parent->right = current->left;
    }
  } else if (current->left == NULL) {
    //node to be deleted has a right child (no left)
    if (current == root) {
      root = current->right;
    } else if (isLeft) {
      parent->left = current->right;
    } else {
      parent->right = current->right;
    }
  } else {
    //node to deleteded has two children
    TreeNode<T> *successor = getSuccessor(current);
    if (current == root) {
      root = successor;
    } else if (isLeft) {
      parent->left = successor;
    } else {
      parent->right = successor;
    }
    successor->left = current->left;
    current->left = NULL;
    current->right = NULL;
  }
  delete current;
  return true;
}

template <class T>
//represents the node to be deleted
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d) {
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;
  while (current != NULL) { //or just while(current) i think
    sp = successor;
    successor = current;
    current = current->left;
  }
  //we found successor but we need to check if the successor is a descendant of the right child
  if(successor != d->right) {
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template <class T>
void BST<T>::facultyRecPrint(TreeNode<T> *node) { //new method for assignment 6
  if (node == NULL) {
    return;
  }
  facultyRecPrint(node->left);
  cout << "Faculty ID: " << node->key.getFacultyId() << endl;  //inorder traversal
  cout << "Name: " << node->key.getName() << endl;
  cout << "Level: " << node->key.getLevel() << endl;
  cout << "Department: " << node->key.getDepartment() << endl;
  cout << "IDs of advisees: ";
  node->key.getIDsOfAdvisees()->printList(false);
  facultyRecPrint(node->right);
}

template <class T>
 //this function prints the entire tree
 void BST<T>::facultyPrintNodes() { //new method for assignment 6
   facultyRecPrint(root);
 }

template <class T>
void BST<T>::studentRecPrint(TreeNode<T> *node) { //new method for assignmnet 6
  if (node == NULL) {
    return;
  }
  studentRecPrint(node->left);
  cout << "Student ID: " << node->key.getStudentID() << endl;  //inorder traversal
  cout << "Name: " << node->key.getName() << endl;
  cout << "Level: " << node->key.getLevel() << endl;
  cout << "Major: " << node->key.getMajor() << endl;
  cout << "GPA: " << node->key.getGPA() << endl;
  cout << "Advisor: " << node->key.getAdvisor() << endl;
  studentRecPrint(node->right);
}

template <class T>
 //this function prints the entire tree
 void BST<T>::studentPrintNodes() { //new method for assignment 6
   studentRecPrint(root);
 }

 template <class T>
 void BST<T>::printStudentNode(int studentID) { //new method for assignment 6
   if (isEmpty()) {
     throw runtime_error("No students in database!");
   }
   TreeNode<T>* current = root;
   while(current->key.getStudentID() != studentID) {
     if (studentID < current->key.getStudentID()) {
       current = current->left;
     } else {
       current = current->right;
     }
     if (current == NULL) {
       throw runtime_error("Student does not exist!");
     }
   }
   cout << "Student ID: " << current->key.getStudentID() << endl;  //inorder traversal
   cout << "Name: " << current->key.getName() << endl;
   cout << "Level: " << current->key.getLevel() << endl;
   cout << "Major: " << current->key.getMajor() << endl;
   cout << "GPA: " << current->key.getGPA() << endl;
   cout << "Advisor: " << current->key.getAdvisor() << endl;
 }

 template <class T>
 void BST<T>::printFacultyNode(int facultyID) { //added method for assignment 6
   if (isEmpty()) {
     throw runtime_error("No faculty in database!");
   }
   TreeNode<T>* current = root;
   while(current->key.getFacultyId() != facultyID) {
     if (facultyID < current->key.getFacultyId()) {
       current = current->left;
     } else {
       current = current->right;
     }
     if (current == NULL) {
       throw runtime_error("Faculty does not exist!");
     }
   }
   cout << "Faculty ID: " << current->key.getFacultyId() << endl;  //inorder traversal
   cout << "Name: " << current->key.getName() << endl;
   cout << "Level: " << current->key.getLevel() << endl;
   cout << "Department: " << current->key.getDepartment() << endl;
   cout << "IDs of advisees: ";
   current->key.getIDsOfAdvisees()->printList(false);
 }

 template <class T>
 int BST<T>::findAdvisorID(int studentID) { //new method for assignment 6
   if (isEmpty()) {
     throw runtime_error("No students in database!");
   }
   TreeNode<T>* current = root;
   while(current->key.getStudentID() != studentID) {
     if (studentID < current->key.getStudentID()) {
       current = current->left;
     } else {
       current = current->right;
     }
     if (current == NULL) {
       throw runtime_error("Student does not exist!");
     }
   }
   return current->key.getAdvisor();
 }

template <class T>
 void BST<T>::studentPrintNodesOfAdvisor(int advisorID, TreeNode<T>* node) { //new method for assignment 6
   if (node == NULL) {
     return;
   }
   studentPrintNodesOfAdvisor(advisorID, node->left);
   if (node->key.getAdvisor() == advisorID) {
     cout << "Student ID: " << node->key.getStudentID() << endl;  //inorder traversal
     cout << "Name: " << node->key.getName() << endl;
     cout << "Level: " << node->key.getLevel() << endl;
     cout << "Major: " << node->key.getMajor() << endl;
     cout << "GPA: " << node->key.getGPA() << endl;
     cout << "Advisor: " << node->key.getAdvisor() << endl;
   }
   studentPrintNodesOfAdvisor(advisorID, node->right);
 }

 template <class T>
  //this function prints the entire tree
  void BST<T>::printAllStudentsGivenAdvisor(int advisorID) { //new method for assignment 6
    studentPrintNodesOfAdvisor(advisorID, root);
  }

  template <class T>
  bool BST<T>::deleteStudentNode(int studentID) { //new method for assignment 6
    if (isEmpty()) {
      return false;
    }
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;
    while (current->key.getStudentID() != studentID) {
      parent = current;
      if(studentID < current->key.getStudentID()) {
        isLeft = true;
        current = current->left;
      } else {
        isLeft = false;
        current = current->right;
      }
      if (current == NULL) {
        return false;
      }
    }
    //out of while loop means we found the node/value, now lets proceed to delete
    //no children, node to be deleted is a leaf
    if(current->left == NULL && current->right == NULL) {
      if (current == root) {
        root = NULL;
      } else if (isLeft) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
    } else if (current->right == NULL) {
      //node to be delete has a left child (no right)
      if (current == root) {
        root = current->left;
      } else if (isLeft) {
        parent->left = current->left;
      } else {
        parent->right = current->left;
      }
    } else if (current->left == NULL) {
      //node to be deleted has a right child (no left)
      if (current == root) {
        root = current->right;
      } else if (isLeft) {
        parent->left = current->right;
      } else {
        parent->right = current->right;
      }
    } else {
      //node to deleteded has two children
      TreeNode<T> *successor = getSuccessor(current);
      if (current == root) {
        root = successor;
      } else if (isLeft) {
        parent->left = successor;
      } else {
        parent->right = successor;
      }
      successor->left = current->left;
      current->left = NULL;
      current->right = NULL;
    }
    delete current;
    return true;
  }

  template <class T>
  bool BST<T>::deleteFacultyNode(int facultyID) { //new method for assignment 6
    if (isEmpty()) {
      return false;
    }
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;
    while (current->key.getFacultyId() != facultyID) {
      parent = current;
      if(facultyID < current->key.getFacultyId()) {
        isLeft = true;
        current = current->left;
      } else {
        isLeft = false;
        current = current->right;
      }
      if (current == NULL) {
        return false;
      }
    }
    //out of while loop means we found the node/value, now lets proceed to delete
    //no children, node to be deleted is a leaf
    if(current->left == NULL && current->right == NULL) {
      if (current == root) {
        root = NULL;
      } else if (isLeft) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
    } else if (current->right == NULL) {
      //node to be delete has a left child (no right)
      if (current == root) {
        root = current->left;
      } else if (isLeft) {
        parent->left = current->left;
      } else {
        parent->right = current->left;
      }
    } else if (current->left == NULL) {
      //node to be deleted has a right child (no left)
      if (current == root) {
        root = current->right;
      } else if (isLeft) {
        parent->left = current->right;
      } else {
        parent->right = current->right;
      }
    } else {
      //node to deleteded has two children
      TreeNode<T> *successor = getSuccessor(current);
      if (current == root) {
        root = successor;
      } else if (isLeft) {
        parent->left = successor;
      } else {
        parent->right = successor;
      }
      successor->left = current->left;
      current->left = NULL;
      current->right = NULL;
    }
    delete current;
    return true;
  }

  template <class T>
  void BST<T>::changeAdvisorOfStudent(int studentID, int facultyID) { //new method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No students in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getStudentID() != studentID) {
      if (studentID < current->key.getStudentID()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("Student does not exist!");
      }
    }
    current->key.setAdvisor(facultyID);
  }

  template <class T>
  void BST<T>::removeAdvisee(int originalAdvisorID, int studentID) { //new method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No Faculty in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getFacultyId() != originalAdvisorID) {
      if (originalAdvisorID < current->key.getFacultyId()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("Faculty does not exist!");
      }
    }
    if (current->key.getIDsOfAdvisees()->find(studentID) == 0) {
      current->key.getIDsOfAdvisees()->removeFront();
    } else {
      current->key.getIDsOfAdvisees()->removeNode(studentID);
    }
  }

  template <class T>
  void BST<T>::addAdvisee(int facultyID, int studentID) { //new method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No Faculty in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getFacultyId() != facultyID) {
      if (facultyID < current->key.getFacultyId()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("Faculty does not exist!");
      }
    }
    current->key.getIDsOfAdvisees()->insertBack(studentID);
  }

  template <class T>
  DoublyLinkedList<int>* BST<T>::getAllAdvisees(int facultyID) { //added method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No faculty in database!");
    }
    DoublyLinkedList<int>* IDsOfAdvisees = new DoublyLinkedList<int>;
    TreeNode<T>* current = root;
    while(current->key.getFacultyId() != facultyID) {
      if (facultyID < current->key.getFacultyId()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("Faculty does not exist!");
      }
    }
    IDsOfAdvisees = current->key.getIDsOfAdvisees();
    return IDsOfAdvisees;
  }

  template <class T>
  void BST<T>::addAllAdviseesToNewAdvisor(DoublyLinkedList<int>* IDsOfAdvisees) { //new method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No Faculty in database!");
    }
    while(!IDsOfAdvisees->isEmpty()) {
      root->key.getIDsOfAdvisees()->insertBack(IDsOfAdvisees->removeFront());
    }
  }

  template <class T>
  string BST<T>::getStudentName(int studentID) { //added method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No students in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getStudentID() != studentID) {
      if (studentID < current->key.getStudentID()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("Student does not exist!");
      }
    }
    return current->key.getName();
  }

  template <class T>
  string BST<T>::getStudentLevel(int studentID) { //added method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No students in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getStudentID() != studentID) {
      if (studentID < current->key.getStudentID()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("Student does not exist!");
      }
    }
    return current->key.getLevel();
  }

  template <class T>
  string BST<T>::getStudentMajor(int studentID) { //added method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No students in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getStudentID() != studentID) {
      if (studentID < current->key.getStudentID()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("Student does not exist!");
      }
    }
    return current->key.getMajor();
  }

  template <class T>
  string BST<T>::getStudentGPA(int studentID) { //added method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No students in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getStudentID() != studentID) {
      if (studentID < current->key.getStudentID()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("Student does not exist!");
      }
    }
    return to_string(current->key.getGPA());
  }

  template <class T>
  string BST<T>::getFacultyName(int facultyID) { //added method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No faculty in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getFacultyId() != facultyID) {
      if (facultyID < current->key.getFacultyId()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("faculty does not exist!");
      }
    }
    return current->key.getName();
  }

  template <class T>
  string BST<T>::getFacultyLevel(int facultyID) { //added method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No faculty in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getFacultyId() != facultyID) {
      if (facultyID < current->key.getFacultyId()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("faculty does not exist!");
      }
    }
    return current->key.getLevel();
  }

  template <class T>
  string BST<T>::getFacultyDepartment(int facultyID) { //added method for assignment 6
    if (isEmpty()) {
      throw runtime_error("No faculty in database!");
    }
    TreeNode<T>* current = root;
    while(current->key.getFacultyId() != facultyID) {
      if (facultyID < current->key.getFacultyId()) {
        current = current->left;
      } else {
        current = current->right;
      }
      if (current == NULL) {
        throw runtime_error("faculty does not exist!");
      }
    }
    return current->key.getDepartment();
  }

  template <class T>
  string BST<T>::getFacultyInfo() { //added method for assignment 6
    string dataForFile = "";
    if (isEmpty()) {
      throw runtime_error("No faculty in database!");
    }
    dataForFile += to_string(root->key.getFacultyId()) + "\n";  //inorder traversal
    dataForFile += root->key.getName() + "\n";
    dataForFile += root->key.getLevel() + "\n";
    dataForFile += root->key.getDepartment() + "\n";
    while (!root->key.getIDsOfAdvisees()->isEmpty()) {
      dataForFile += root->key.getIDsOfAdvisees()->removeFront() + ",";
    }
    dataForFile += "\n";
    deleteFacultyNode(root->key.getFacultyId());
    return dataForFile;
  }

  template <class T>
  string BST<T>::getStudentInfo() { //added method for assignment 6
    string dataForFile = "";
    if (isEmpty()) {
      throw runtime_error("No Student in database!");
    }
    dataForFile += to_string(root->key.getStudentID()) + "\n";  //inorder traversal
    dataForFile += root->key.getName() + "\n";
    dataForFile += root->key.getLevel() + "\n";
    dataForFile += root->key.getMajor() + "\n";
    dataForFile += to_string(root->key.getGPA()) + "\n";
    dataForFile += to_string(root->key.getAdvisor()) + "\n";
    deleteStudentNode(root->key.getStudentID());
    return dataForFile;
  }

#endif
