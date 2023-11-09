#pragma once
/***************************************************************************************
*    Title: C++ Plus Data Structures SIXTH EDITION
*    Author: Nell Dale, Chip Weems
*    Date: 09/14/2023
*    Code version: C++11
*    Availability: Chapter 5
*
***************************************************************************************/
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H
struct Node {
  Node* next;
  int info;
};

class Queue {
private:
  Node* head;
  Node* tail;

public:
  Queue();
  ~Queue();
  void Enqueue(int);
  void Dequeue(int&);
  bool IsFull();
  bool IsEmpty();
  void MakeEmpty();
};

#endif