/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 6 - Building a Database with Binary Search Trees
 * This .h file is a template class for a doubly linked list
*/
#ifndef GENLINKEDLIST_H
#define GENLINKEDLIST_H

#include <iostream>
#include <exception>

using namespace std;

template <class T>
class ListNode {
public:
  ListNode();
  ListNode(T d);
  ~ListNode();
  ListNode<T> *next;
  ListNode<T> *prev;
  T data;
};

//implementation for ListNode class
template <class T>
ListNode<T>::ListNode() {
  data = NULL;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d) {
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode() {
  prev = NULL;
}

template <class T>
class DoublyLinkedList {
private:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  T removeNode(T value);
  int find(T value);
  bool isEmpty();
  unsigned int getSize();
  void printList(bool isPrintLink);
  T getFrontData();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  ListNode<T> *temp = NULL;
  while (front) {
    temp = front;
    front = front->next;
    delete temp;
  }
  front = NULL;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d) {
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()) {
    back = node;
  }
  else { //it's not empty
    node->next = front;
    front->prev = node;
  }
  front = node;
  ++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d) {
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()) {
    front = node;
  }
  else {
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront() {
  if (isEmpty()) {
    throw runtime_error("list is empty");
  }
  ListNode<T> *temp = front;
  if (front->next == NULL) {
    back = NULL;
  }
  else { //more than one node in the list
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;
  T data = temp->data;
  --size;
  delete temp;
  return data;
}

template <class T>
T DoublyLinkedList<T>::removeBack() {
  if (isEmpty()) {
    throw runtime_error("list is empty");
  }
  ListNode<T> *temp = front;
  if (back->prev = NULL) { //only node in list
    front = NULL;
  }
  else { //more than one node in the list
    back->prev->next = NULL;
  }
  back = back->prev;
  temp->prev = NULL;
  int data = temp->data;
  --size;
  delete temp;
  return data;
}

template <class T>
T DoublyLinkedList<T>::removeNode(T value) {
  if(isEmpty()) {
    throw runtime_error("list is empty!");
  }
  //leverage find method
  ListNode<T> *curr = front;
  while(curr->data != value) {
    curr = curr->next;
    if (curr == NULL) {
      return -1;
    }
    //if we make it to this point, value was found so lets proceed to remove it
    if (curr != front && curr != back) { //it's in between front and back
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
    }
    if(curr == front) {
      front = curr->next;
      front->prev = NULL;
    }
    if (curr == back) {
      back = curr->prev;
      back->next = NULL;
    }
    curr->next = NULL;
    curr->prev = NULL;
    int data = curr->data;
    --size;
    //more should be here
  }
}

template <class T>
int DoublyLinkedList<T>::find(T value) {
  int pos = -1;
  ListNode<T> *curr = front;
  while(curr != NULL) {
    ++pos;
    if(curr->data == value) {
      break;
    }
    curr = curr->next;
  }
  if (curr == NULL) { //checks if curr is NULL which signifies value not in linked list
    pos = -1;
  }
  return pos;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() {
  return (size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize() {
  return size;
}

template <class T>
void DoublyLinkedList<T>::printList(bool isPrintLink) {
    ListNode<T> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(isPrintLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";

       curr = curr->next;
       if(curr != 0){
         cout << " ==> ";
       }
    }
    cout << endl;
}

template <class T>
T DoublyLinkedList<T>::getFrontData() {
  return front->data;
}

#endif
