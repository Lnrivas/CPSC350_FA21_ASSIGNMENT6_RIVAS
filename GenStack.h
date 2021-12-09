/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This .h file is a template class for a stack based off of a doubly linked list
*/
#include "GenLinkedList.h"

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>

using namespace std;

template <class T>
class GenStack {
public:
  GenStack(); // default constructor
  ~GenStack(); // destructor

  //core functions
  void push(T data);
  T pop();

  //aux/helper functions
  T peek(); // aka top()
  bool isEmpty();
  int getSize();

private:
  DoublyLinkedList<T> *myList;
  int top;
};

//implementation
template <class T>
GenStack<T>::GenStack() {
  top = -1;
  myList = new DoublyLinkedList<T>();
}

template <class T>
GenStack<T>::~GenStack() {
  delete myList;
}

template <class T>
void GenStack<T>::push(T data) {
  top++;
  myList->insertFront(data);
}

template <class T>
T GenStack<T>::pop() {
  if (isEmpty()) { //check if empty
    throw runtime_error("stack is empty!");
  }
  top--;
  return myList->removeFront();
}

template <class T>
T GenStack<T>::peek() {
  if (isEmpty()) { //check if empty
    throw runtime_error("stack is empty!");
  }
  return myList->getFrontData();
}

template <class T>
bool GenStack<T>::isEmpty() {
  return (top == -1);
}

template <class T>
int GenStack<T>::getSize() {
  return (top + 1);
}

#endif
