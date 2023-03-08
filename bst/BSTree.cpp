#include "BSTree.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <iomanip> 
#include <stdexcept>
#include <algorithm>

using namespace std;

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    //call delete function
    deleteTree(root);
}

void BSTree::deleteTree(Node *userNode) {
    //traverse thru tree and delete
    if ( userNode == nullptr) {  //if empty return 
        return;
    }
    deleteTree(userNode->getLeft());
    deleteTree(userNode->getRight());
    delete userNode;
}

bool BSTree::isEmpty() {
    if (root == nullptr) {
        return true;
    }
    return false;
}

void BSTree::setRoot(const string &userWord) {
    //if empty, we create a new root
    if (isEmpty()) {
    Node *newRoot = new Node();
    //set root to new root
    root = newRoot;
    //set the variables inside of it 
    newRoot->setWord(userWord);
    newRoot->setLeft(nullptr);
    newRoot->setRight(nullptr);
    }
}

void BSTree::setNode(Node *userNode) {
    Node *currNode = root;
    while (currNode != nullptr) {
        //if what we are trying to insert is less than curr, go left
        if (userNode->getWord() < currNode->getWord()) {
            //if left is empty, then insert 
            if (currNode->getLeft() == nullptr) {
                currNode->setLeft(userNode);
                //set currNode to null so we dont have any dangling pointers
                currNode = nullptr;
            }
            else {
                //if left is not empty, go down left
                currNode = currNode->getLeft();
            }
        }
        else {
            //if what we are trying to insert is bigger, we go right and if its empty, insert
            if (currNode->getRight() == nullptr) {
                currNode->setRight(userNode);
                currNode = nullptr;
            }
            // if right is not empty
            else {
                currNode = currNode->getRight();
            }
        }
    }
}




void BSTree::insert(const string &newString) {
    if (!search(newString)) {
        if (isEmpty()) {
            setRoot(newString);

        }
        else {
            Node *newNode = new Node();
            newNode->setWord(newString);
            setNode(newNode);

        }
    }
    //update counter (just update counter if key is in the tree)
   retrieveNode(newString)->setCount(retrieveNode(newString)->getCount() + 1);
}

void BSTree::remove(const string &key) {
    bool searchResult = search(key);
    if (root == nullptr) {
        return;
    }
    if(searchResult == false) {
        return;
    }
    keyRemove(retrieveNode(key));
}

void BSTree::keyRemove(Node* keyNode) {
    // if its in the list multiple times, just decrement 
    if (keyNode->getCount() > 1) {
        keyNode->setCount(keyNode->getCount() - 1);
        return;
    }

    //if in list, decrement count 
    if (search(keyNode->getWord())) {
        keyNode->setCount(keyNode->getCount() - 1);
    }


    
    Node *parent = nullptr;
    Node *curr = root;
    Node *suc = nullptr;
    Node *pred = nullptr;
    string sucData;
    string predData;
    while (curr != nullptr) { //search for node
        if (curr->getWord() == keyNode->getWord()) {   
            //remove leaf node
            if (curr->getLeft() == nullptr && curr->getRight() == nullptr) {
                if (parent == nullptr) {
                    root = nullptr;
                }
                else if (parent->getLeft() == curr) {
                    parent->setLeft(nullptr);
                }
                else {
                    parent->setRight(curr->getLeft());
                }
            }
            else if (curr->getLeft() == nullptr) { //if it has only right child ->find leftmost in right subtree and replace
                //if we are deleting the root, simply replace with the node to the right
                if (parent == nullptr) {
                    root = curr->getRight();
                }
                //redirect parent pointer to node AFTER curr on right side
                else if (parent->getRight() == curr) {
                    parent->setRight(curr->getRight());
                }
                //MIGHT BE WRONG -> fix!
                // else {
                //     parent->setLeft(curr->getRight());
                // }
            }

            else if (keyNode->getLeft() == nullptr) {
                // //find the successor ->rightmost child of left subtree- cases: two children OR node to remove has one left child
                if (curr->getRight() != nullptr) {
                suc = curr->getRight();
                while (suc->getLeft() != nullptr) {
                    suc = suc->getLeft();
                    sucData = suc->getWord(); //create a copy of suc's string
                }
                keyRemove(suc); //remove successor
                    //assign cur's data with successorData
                curr->setWord(sucData);
                //node to remove HAS a left child only OR two children 
                }
                else { //if node to remove only has a left child
                    if (parent == nullptr) {
                        root = curr->getLeft();
                    }
                    else if (parent->getLeft() == curr) {
                        parent->setLeft(curr->getLeft());
                    }
                    else {
                        parent->setRight(curr->getLeft());
                    }
                }
            }
            else {
                // //find the pred
                if (curr->getLeft() != nullptr) {
                    pred = curr->getLeft();
                    while (pred->getRight() != nullptr) {
                        pred = pred->getRight();
                        predData = pred->getWord(); //create a copy of suc's string
                    }
                keyRemove(pred); //remove successor
                    //assign cur's data with successorData
                curr->setWord(predData);
                //node to remove HAS a left child only OR two children 
                }
                else { //if node to remove only has a right child
                    if (parent == nullptr) {
                        root = curr->getRight();
                    }
                    else if (parent->getRight() == curr) {
                        parent->setRight(curr->getRight());
                    }
                    else {
                        parent->setLeft(curr->getRight());
                    }
                }
            }
            return; //node found and removed 
        }
        else if (curr->getWord() < keyNode->getWord()) { //search right
            parent = curr;
            curr = curr->getRight();
        }
        else {  //search left
            parent = curr;
            curr = curr->getLeft();
        }
    }
    return; //node not found 

}

//like search function but you stop before desired node 
// Node* BSTree::getParent(Node* keyNode) const {
//     Node* curr = root;
//     //traverse through the list to find the key
//     while (curr != nullptr) {
//         if (userString == curr->getWord()) {
//             return curr; // found 
//         }
//         //if key is less than parent, shift left
//         else if (userString < curr->getWord()){
//             curr = curr->getLeft();
//         }
//         //if key is greater than parent, shift right
//         else {
//             curr = curr->getRight();
//         }
// }

//find smallest
string BSTree::smallest() const {
    Node *curr = root;
    //case #1: if list empty
    if (curr == nullptr) {
        return "";
    }
    //case #2: if there is only one item in the list
    if (curr->getLeft() == nullptr) {
        return root->getWord();
    }
    //more than one item in the list
    while (curr->getLeft() != nullptr) {
        curr = curr->getLeft();
    }
    return curr->getWord();
}

//find largest
string BSTree::largest() const {
    Node *curr = root;
    //case #1: if list empty
    if (curr == nullptr) {
        return "";
    }
    //case #2: if there is only one item in the list
    if (curr->getRight() == nullptr) {
        return root->getWord();
    }
    //more than one item in the list
    while (curr->getRight() != nullptr) {
        curr = curr->getRight();
    }
    return curr->getWord();
}

//helper function for insert- search but returns the node
Node* BSTree::retrieveNode(const string &userString) const {
      Node* curr = root;
    //traverse through the list to find the key
    while (curr != nullptr) {
        if (userString == curr->getWord()) {
            return curr; // found 
        }
        //if key is less than parent, shift left
        else if (userString < curr->getWord()){
            curr = curr->getLeft();
        }
        //if key is greater than parent, shift right
        else {
            curr = curr->getRight();
        }
    }

    return nullptr; //not found 
}

 bool BSTree::search(const string &key) const {
    Node* curr = root;
    //traverse through the list to find the key
    while (curr != nullptr) {
        if (key == curr->getWord()) {
            return true; // found 
        }
        //if key is less than parent, shift left
        else if (key < curr->getWord()){
            curr = curr->getLeft();
        }
        //if key is greater than parent, shift right
        else {
            curr = curr->getRight();
        }
    }

    return false; //not found 
 }

//height 
int BSTree::height(const string& key) const {
  return findHeight(retrieveNode(key));
}

int BSTree::findHeight(Node* keyNode) const {
    int leftHeight;
    int rightHeight;
    //if node does not exist
    if (keyNode == nullptr) {
        return -1;
    }
    leftHeight = findHeight(keyNode->getLeft());
    rightHeight = findHeight(keyNode->getRight());
    return 1 + max(leftHeight, rightHeight);
}


 Node* BSTree::getRoot() {
    return root;
 }
 //print in order 
 void BSTree::inOrder() const {
    inOrder(root);
 }

void BSTree::inOrder(Node *userNode)const {
    //if empty, return 
    if(userNode == nullptr) {
        return;
    }
    inOrder(userNode->getLeft()); 
    cout << userNode->getWord() << "(" << userNode->getCount() << ")" << ", ";

    inOrder(userNode->getRight());
}

void BSTree::postOrder() const { //left to right starting from bottom
    postOrderRecursive(root);
} 

 void BSTree::preOrder() const {
    preOrderRecursive(root);
 }

 void BSTree::preOrderRecursive(Node *keyNode) const {
    if (keyNode == nullptr) {
        return;
    }
    //visit node 
    cout << keyNode->getWord() << "(" << keyNode->getCount() << ")" << ", ";
   
    preOrderRecursive(keyNode->getLeft());
    preOrderRecursive(keyNode->getRight());
 }

 void BSTree::postOrderRecursive(Node *keyNode) const {
    if (keyNode == nullptr) {
        return;
    }
    postOrderRecursive(keyNode->getLeft());
    postOrderRecursive(keyNode->getRight());
    cout << keyNode->getWord() << "(" << keyNode->getCount() << ")" << ", ";
    
 }

