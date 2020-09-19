/**
   Nathaniel Larsen - nlarsen - nathaniel.e.larsen@gmail.com
   List.cpp - Linked List class template Implementaion File
   Assignment 1 - Linked List Review
   Removed TODOs for ease of review.
*/

#include <iostream>
#include "List.h"

/*
*  Node class to contain data for linked list
*/

template <class T>
class LinkNode{
  friend class List<T>; // list can modify node members
public:
  LinkNode(){next = 0; prev = 0; data = 0;} // default constructor
  LinkNode(T* val); // constructor from data value
  LinkNode(LinkNode<T>& toCopy); // copy constructor
  ~LinkNode(){if(data){delete data; data = 0;}} // destructor
private:
  T* data;
  LinkNode* next;
  LinkNode* prev;
};

template <class T>
LinkNode<T>::LinkNode(T* val){
  data = new T(); //allocate memory and point data to it
  *data = *val; //dereference and default memberwise copy or op= 
  next = 0; prev = 0; 
}

template <class T>
LinkNode<T>::LinkNode(LinkNode<T>& toCopy) {
  data = new T();
  *data = toCopy->data;
  next = prev = 0;
}

template <class T>
List<T>::~List(){
  LinkNode<T>* temp = head;
  while(head){ // list is not empty
    temp = head; // keep reference to head
    head = head->next; // move head to next node
    delete temp; // calls linknode destructor
  }
}

template <class T>
void List<T>::push_front(T* new_data){
  ++size; 
  LinkNode<T>* temp = new LinkNode<T>(new_data); //create a new linknode to prepend to list
  if(!head){ //empty list case
    head = tail = temp;
    return;
  }
  //otherwise, attach and point head to new node
  temp->next = head; head->prev = temp;
  head = temp;                                                                       }

template <class T>
void List<T>::push_back(T* new_data){
  ++size;
  LinkNode<T>* temp = new LinkNode<T>(new_data);
  if(!tail) { //empty list
    head = tail = temp;
    return;
  }
  //otherwise, attach and point tail to new node
  temp->prev = tail; tail->next = temp;
  tail = temp;
}

template <class T>
T* List<T>::pop_front(){
  if (!head) return NULL; //empty list
  --size; 
  T* result = head->data; //point result to head's data - return value
  head->data = 0; //release head node's data pointer

  if (head == tail){ //one element list
    delete head;
    head = tail = 0;
    return result;
  }

  LinkNode<T>* temp = head; // get reference to current head node

  //detach head and point head to next element
  head->next->prev = 0; head = head->next; 
  delete temp;
  return result;
}

template <class T>
T* List<T>::pop_back(){
  T* result = 0;
  if (!tail) return 0; //empty list
  --size;
  result = tail->data;
  tail->data = 0;
  if (head == tail){
    delete tail;
    head = tail = 0;
    return result;
  }
  LinkNode<T>* temp = tail; // get reference to current tail node

  //detach tail and point tail to prior element
  tail->prev->next = 0; tail = tail->prev;
  delete temp;
  return result;
}

template <class T>
void List<T>::insert_at(size_t index, T* val){
  if (index > size || index < 0) return; //out of range
  if (index == size){ //end of list
    push_back(val); return;
  }
  if (index == 0){ //start of list
    push_front(val); return;
  }
  ++size;
  LinkNode<T>* link = head; 
  //traversing starting @ index 0
  for(unsigned i = 0; i < index; ++i){
    link = link->next;
  }
  //link now points to node to follow new node to be inserted
  LinkNode<T>* anchor = link->prev; // get reference to node to come before new element
  LinkNode<T>* temp = new LinkNode<T>(val); // allocate memory for new element
  anchor->next = temp; temp->prev = anchor; // attach new element to front of list
  temp->next = link; link->prev = temp; //atttach the rest of list to new element

}

//since I moved the functionality to a cpp file, these template lines must be placed here to deal with undefined reference issues
template class List<int>; 
template class List<double>;
template class List<std::string>;
