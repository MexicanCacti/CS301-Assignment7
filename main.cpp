#include "BST.h"

#include <fstream>
#include <ctime>
#include <string>
using namespace std;

void generateNumbers(int amount, string textFile);

int main() {
  srand(time(NULL));        // random # generation
  BST Tree;
  ifstream fin;
  string number, textFile;  // string number to get from textfile (atoi to convert), textFile is the file name to fout & fin.
  int numbers;    // user provides amount of #s to generate
  int count = 0;  // to count # of numbers displayed. Creates a new lines to create based on % == 0
  bool check = false;
  
  // driver asks user to provide a textfile to generate n amount of numbers into... comment code block out if want to provide own text file
  cout << "Enter Textfile to generate numbers into and read from: ";
  getline(cin, textFile);
  cout << "\nAmount of numbers to generate: ";
  cin >> numbers;
  generateNumbers(numbers, textFile);

  // from textfile, takes numbers and builds a tree
  fin.open(textFile);
  while (fin.good()) {
    getline(fin, number, ',');
    Tree.PutItem(atoi(number.c_str()));
  }
  fin.close();
  
  // Sets tree to order want tree in... see BST.h for options
  Tree.ResetTree(IN_ORDER);
  
  // Dequeues numbers in blocks of 5
  cout << "\n\nDequeuing numbers..." << endl;
  while (!check) {
    numbers = Tree.GetNextItem(IN_ORDER, check);
    if (count % 5 == 0 && count != 0) cout << "\n";
    count++;
    cout << numbers << " ";
  }
}

void generateNumbers(int amount, string textFile) {
  ofstream fout;
  int number;
  
  // generates [amount] of numbers in range 0 -> 100. Displays & Stores #s generated in blocks of 5
  cout << "\nGenerating Numbers...\n";
  fout.open(textFile);
  for (int i = 0; i < amount - 1; i++) {
    number = rand() % 100;
    if (i % 5 == 0 && i != 0) {
      fout << "\n";
      cout << "\n";
    }
    cout << number << " ";
    fout << number << ", ";
  }
  number = rand() % 100;
  cout << number;
  fout << number;
  fout.close();
}