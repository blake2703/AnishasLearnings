#include <iostream>
#include "AVLTree.h"
#include "Node.h"

using namespace std;

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Print" << endl
    << "3. Quit" << endl;
  cin >> choice;

  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(256, '\n');
  return choice;
}

int main( ) {

  AVLTree tree;

  int choice = menu();

  string entry;

  while (choice != 3) {

    if (choice == 1) {
      cout << "Enter string to insert: ";
      getline(cin, entry);
      cout << endl;

      tree.insert(entry);

    } else if (choice == 2) {
      tree.printBalanceFactors();

    } 
    //fix buffer just in case non-numeric choice entered
    choice = menu();
  }


//MY OWN TESTBENCHES: 

// //testing insert();----------------------------------------------------------------------------------------------------------
// AVLTree tree1;
// tree1.insert("panda");
// tree1.insert("banana");
// tree1.insert("apple");
// tree1.preOrder();

//testing balanceFactor()----------------------------------------------------------------------------------------------------------
  //testing on leaf
  // AVLTree tree2;
  // tree2.insert("panda");
  // tree2.printBalanceFactors(); //should output 0

  //testing on longer tree
  //AVLTree tree3;
  // tree3.insert("panda");
  // tree3.insert("quirk");
  // tree3.insert("rawr");
  // tree3.insert("zoo");
  // tree3.printBalanceFactors(); //balance factor = panda(-3)

  // AVLTree tree4;
  // tree4.insert("moth");
  // tree4.insert("banana");
  // tree4.insert("duck");
  // tree4.printBalanceFactors();








  
  





  return 0;
}