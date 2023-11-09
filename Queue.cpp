#include "Queue.h"

Queue::Queue() {
  head = NULL;
  tail = NULL;
}

Queue::~Queue() {
  Node* temp = head;

  while (head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
  }
}

void Queue::Enqueue(int item) {
  if (IsFull()) {
    return;
  }
  Node* Item = new Node();
  Item->info = item;
  if (IsEmpty()) {
    head = Item;
    tail = Item;
    return;
  }
  tail->next = Item;
  tail = Item;
}

void Queue::Dequeue(int& item) {
  if (IsEmpty()) {
    return;
  }

  item = head->info;
  Node* temp = head;
  head = head->next;
  delete temp;

  if (head == NULL) {
    tail = NULL;
  }
}

bool Queue::IsEmpty() {
  if (head == NULL) {
    return true;
  }
  return false;
}

bool Queue::IsFull() {
  try {
    Node* temp = new Node();
    delete temp;
    return false;
  }
  catch (std::bad_alloc exception) {
    return true;
  }
}

void Queue::MakeEmpty() {
  Node* temp = head;
  tail = NULL;
  while (head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
  }
}