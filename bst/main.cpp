#include "BSTree.h"
#include <limits>
#include <iostream>
#include <string>

using namespace std;

void printOrders(BSTree *tree) {
cout << "Preorder = ";
tree->preOrder();

cout << endl;
cout << "Inorder = ";
tree->inOrder();

cout << endl;
cout << "Postorder = ";
tree->postOrder();

cout << endl;
}

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Remove" << endl
    << "3. Print" << endl
    << "4. Search" << endl
    << "5. Smallest" << endl
    << "6. Largest" << endl
    << "7. Height" << endl
    << "8. Quit" << endl;
  cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

int main() {

BSTree tree;
int choice = menu();

string entry;

while (choice != 8) {

  if (choice == 1) {
    cout << "Enter string to insert: ";
    getline(cin, entry);
    cout << endl;
    tree.insert(entry);
  }
  else if (choice == 2) {
    cout << "Enter string to remove: ";
    getline(cin, entry);
    cout << endl;
    tree.remove(entry);
  }
  else if (choice == 3) {
    printOrders(&tree);
  }
  else if (choice == 4) {
    cout << "Enter string to search for: ";
    getline(cin, entry);
    cout << endl;
  if (tree.search(entry)) {
    cout << "Found" << endl;
  }
  else {
    cout << "Not Found" << endl;
   }
  }
  else if (choice == 5) {
    cout << "Smallest: " << tree.smallest() << endl;
  }
  else if (choice == 6) {
    cout << "Largest: " << tree.largest() << endl;
  }
  else if (choice == 7) {
  cout << "Enter string: ";
  getline(cin, entry);
  cout << endl;
  cout << "Height of subtree rooted at " << entry << ": "
  << tree.height(entry) << endl;
  }
  // fix buffer just in case non-numeric choice entered
  choice = menu();

}

return 0;

}

//      OWN TESTS:
//     test insert on empty tree-> test thouroughly later
//     BSTree bst = BSTree();
//     bst.insert("cat");
//     bst.insert("dog");
//     bst.insert("cat"); //also tests search
//     bst.insert("apple");
// MY
//     bst.inOrder();

    //testing smallest and largest function
   //BSTree bst = BSTree(); 
    //test 1
        // bst.insert("cat");
        // bst.insert("dog");
        // bst.insert("apple"); 
        // cout << bst.smallest() << endl; //output apple
        // cout << bst.largest() << endl; //output dog
    //test2- empty list
    // BSTree bst = BSTree(); 
    // cout << bst.smallest() << endl; //output nothing

    //testing height function
    // BSTree bst = BSTree();
    // bst.insert("orange");
    // bst.insert("banana");
    // bst.insert("apple");
    // bst.insert("zoo");
    // cout << bst.height("apple") << endl; //output 0
    // cout << bst.height("orange") << endl; //output 2
    // return 0;

    //testing BST remove algorithm
    // BSTree bst = BSTree();
    // bst.insert("orange");
    // bst.insert("orange");
    // bst.insert("banana");
    // bst.insert("apple");
    // bst.insert("zoo");
    // bst.inOrder();
    // cout << endl;

    // //remove internal node
    // bst.remove("banana");
    // bst.inOrder();
    // cout << endl;

    // //remove leaf
    // bst.remove("apple");
    // bst.inOrder();
    // cout << endl;

    // //remove root-duplicate ONLY 
    // bst.remove("orange");
    // bst.inOrder();
    // cout << endl;

    // //remove root-duplicate ONLY 
    // bst.remove("orange");
    // bst.inOrder();
    // cout << endl;


    //testing preOrder print function
    // BSTree bst = BSTree();
    // bst.insert("orange");
    // bst.insert("banana");
    // bst.insert("apple");
    // bst.preOrder();