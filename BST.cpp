#include "BST.h"
void Delete(Tree*& tree, int item);

int CountNodes(Tree* tree) {
  if (tree == NULL) return 0;
  return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void GetPredecessor(Tree* tree, int& item) {
  while (tree->right != NULL) {
    tree = tree->right;
  }
  item = tree->info;
}

void Retrieve(Tree* tree, int& item, bool& found) {
  if (tree == NULL) {
    found = false;
  }
  else if (item < tree->info) {
    Retrieve(tree->left, item, found);
  }
  else if (item > tree->info) {
    Retrieve(tree->right, item, found);
  }
  else {
    found = true;
    item = tree->info;
  }
}

void Insert(Tree*& tree, int item) {
  if (tree == NULL) {
    tree = new Tree;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info) { // if you want to put into descending just switch boolean op
    Insert(tree->left, item);
  }
  else {
    Insert(tree->right, item);
  }
}

void DeleteNode(Tree* tree) {
  int data;
  Tree* temp;
  temp = tree;

  if (tree->left == NULL) {
    tree = tree->right;
    delete temp;
  }
  else if (tree->right == NULL) {
    tree = tree->left;
    delete temp;
  }
  else {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);
  }
}

void Delete(Tree*& tree, int item) {
  if (item < tree->info) {
    Delete(tree->left, item);
  }
  else if (item > tree->info) {
    Delete(tree->right, item);
  }
  else {
    DeleteNode(tree);
  }
}

void Destroy(Tree*& tree) {
  if (tree != NULL) {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

void PrintTree(Tree* tree, std::ostream& outFile) {
  if (tree != NULL) {
    PrintTree(tree->left, outFile);
    outFile << tree->info;
    PrintTree(tree->right, outFile);
  }
}

void CopyTree(Tree*& copy, const Tree* originalTree) {
  if (originalTree == NULL) copy = NULL;
  else {
    copy = new Tree;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}

BST::BST() {
  root = NULL;
}

BST::~BST() {
  Destroy(root);
}

BST::BST(const BST& originalTree) {
  CopyTree(root, originalTree.root);
}

void BST::operator=(const BST& originalTree) {
  if (&originalTree == this) {
    return;
  }
  Destroy(root);
  CopyTree(root, originalTree.root);
}

void BST::MakeEmpty() {
  Destroy(root);
  root = NULL;
}

bool BST::IsEmpty() const {
  return root == NULL;
}

bool BST::IsFull() const {
  Tree* location;
  try {
    location = new Tree;
    delete location;
    return false;
  }
  catch (std::bad_alloc exception) {
    return true;
  }
}

int BST::GetLength() const {
  return CountNodes(root);
}

int BST::GetItem(int item, bool& found) {
  Retrieve(root, item, found);
  return item;
}

void BST::PutItem(int item) {
  Insert(root, item);
}

void BST::DeleteItem(int item) {
  Delete(root, item);
}

// Enqueues tree items in preorder.
void PreOrder(Tree* tree, Queue& preQueue) {
  if (tree != NULL) {
    preQueue.Enqueue(tree->info);
    PreOrder(tree->left, preQueue);
    PreOrder(tree->right, preQueue);
  }
}


// Enqueues tree items in inorder.
void InOrder(Tree* tree, Queue& inQueue) {
  if (tree != NULL) {
    InOrder(tree->left, inQueue);
    inQueue.Enqueue(tree->info);
    InOrder(tree->right, inQueue);
  }
}


// Enqueues tree items in postorder.
void PostOrder(Tree* tree, Queue& postQueue) {
  if (tree != NULL)
  {
    PostOrder(tree->left, postQueue);
    PostOrder(tree->right, postQueue);
    postQueue.Enqueue(tree->info);
  }
}

void BST::ResetTree(OrderType order) {
  switch (order)
  {
  case PRE_ORDER: PreOrder(root, preQue);
    break;
  case IN_ORDER: InOrder(root, inQue);
    break;
  case POST_ORDER: PostOrder(root, postQue);
    break;
  }
}

int BST::GetNextItem(OrderType order, bool& finished) {
  finished = false;
  int item = 0;
  switch (order)
  {
  case PRE_ORDER: preQue.Dequeue(item);
    if (preQue.IsEmpty())
      finished = true;
    break;
  case IN_ORDER: inQue.Dequeue(item);
    if (inQue.IsEmpty())
      finished = true;
    break;
  case  POST_ORDER: postQue.Dequeue(item);
    if (postQue.IsEmpty())
      finished = true;
    break;
  }
  return item;
}

void BST::Print(std::ostream& outFile) {
  PrintTree(root, outFile);
}
