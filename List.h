/**
   Nathaniel Larsen - nlarsen - nathaniel.e.larsen@gmail.com
   List.h - Linked List class template Header File
   Support for T of type: int, double, string.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <class T>
class LinkNode;  // forward declaration

/*
  Linked List Template class - doubly linked list generic class
  TODO: op overloading, specialization, + a few functions
*/

template <class T>
class List {
 public:
  List() {
    head = 0;
    tail = 0;
    size = 0;
  }
  // List(List&); // copy constructor --TODO
  ~List();
  void push_front(T*);         // prepend to list
  void push_back(T*);          // append to list
  void insert_at(size_t, T*);  // insert an element at given index
  T* pop_front();  // pop the data from the front link node off of the list
  T* pop_back();   // pop the data from the back link node off of the list
  void remove_all(T* val);    // remove every occurrence of val from the list
  void remove_first(T* val);  // remove first occurrence of val from the list
  void erase(size_t index);   // erase the element at given index
  void erase_front();         // erase the first element of the list
  void erase_back();          // erase the last element of the list
  void print();  // print the list. PRE: T stream insertion operator is defined
  size_t length() { return size; }
 private:
  LinkNode<T>* head;
  LinkNode<T>* tail;
  size_t size;
};

#endif
