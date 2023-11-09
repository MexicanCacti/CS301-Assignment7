/***************************************************************************************
*    Title: C++ Plus Data Structures SIXTH EDITION
*    Author: Nell Dale, Chip Weems
*    Date: 09/14/2023
*    Code version: C++11
*    Availability: Chapter 8
*
***************************************************************************************/

#pragma once
#ifndef BST_H
#define BST_H
#include <iostream>
#include "Queue.h"

struct Tree {
  Tree* right;
  Tree* left;
  int info;
};

enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };

class BST {
  private:
    Tree* root;
    Queue preQue;
    Queue inQue;
    Queue postQue;
  public:
    BST();
    ~BST();
    BST(const BST& originalTree);
    void operator=(const BST& originalTree);  // copy constructor
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int GetLength() const;
    int GetItem(int item, bool& found);
    void PutItem(int item);
    void DeleteItem(int item);
    void ResetTree(OrderType order);
    int GetNextItem(OrderType order, bool& finished);
    void Print(std::ostream& outFile);
};
#endif