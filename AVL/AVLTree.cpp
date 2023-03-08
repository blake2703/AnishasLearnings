#include "AVLTree.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <iomanip> 
#include <stdexcept>
#include <algorithm>

using namespace std;


AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    //call delete function
    deleteTree(root);
}

void AVLTree::deleteTree(Node *userNode) {
    //traverse thru tree and delete
    if ( userNode == nullptr) {  //if empty return 
        return;
    }
    deleteTree(userNode->getLeft());
    deleteTree(userNode->getRight());
    delete userNode;
}

Node* AVLTree::balance(Node* node) {
    int balance_factor = getBalanceFactor(node);
    if(balance_factor > 1) {
        if(getBalanceFactor(node->getLeft()) > 0) {
            node = rotateLeftLeft(node);
        }
        else {
            node = rotateLeftRight(node);
        }
    }
    else if(balance_factor < -1) {
        if(getBalanceFactor(node->getRight()) > 0) {
            node = rotateRightLeft(node);
        }
        else {
            node = rotateRightRight(node);
        }
    }
    return node;
}


void AVLTree::insert(const string& newString) {
    root = insertRec(root, newString);
}

Node* AVLTree::insertRec(Node* node, string val) {
    if (search(val)) {
        node->setCount(node->getCount() + 1);
        return node;
    }
   // node->setCount(node->getCount() + 1);
    if(node == nullptr) {
        node = new Node();
        node->setWord(val);
        node->setLeft(nullptr);
        node->setRight(nullptr);
        return node;
    }
    else if (val < node->getWord()) {
        node->setLeft(insertRec(node->getLeft(), val));
        node = balance(node);
    }
    else if(val >= node->getWord()) {
        node->setRight(insertRec(node->getRight(), val));
        node = balance(node);
    }
    else {
        return node;
    }
    return node;
}

bool AVLTree::search(const string& key) const {
    if (root == nullptr) {
        return false; // tree is empty, so we return false 
    }
    Node* curr = root;
    while (curr != nullptr) {
        if (key == curr->getWord()) {
            return true; // found 
        }
        else if (key < curr->getWord()) {
            curr = curr->getLeft();
        }
        else {
            curr = curr->getRight();
        }
    }
    return false; //not found 
}
//takes in the unbalanced node, which is the root of the subtree
// void rotate(Node* node) {
   
// } 

Node* AVLTree::rotateRightRight(Node* node) {
    Node* temp = node->getRight();
    node->setRight(temp->getLeft());
    temp->setLeft(node);
    return temp;
}
Node* AVLTree::rotateLeftLeft(Node* node) {
    Node* temp = node->getLeft();
    node->setLeft(temp->getRight());
    temp->setRight(node);
    return temp;
}
Node* AVLTree::rotateLeftRight(Node* node) {
    Node* temp = node->getLeft();
    node->setLeft(rotateRightRight(temp));
    return rotateLeftLeft(node);
}
Node* AVLTree::rotateRightLeft(Node* node) {
    Node* temp = node->getRight();
    node->setRight(rotateLeftLeft(temp));
    return rotateRightRight(node);
}


int AVLTree::getBalanceFactor(Node * node) {
    return balanceFactor(node);
}

void AVLTree::setBalanceFactor(Node* node) {
    node->setBalanceFactor(balanceFactor(node));
}




int AVLTree::balanceFactor(Node* node) {
    int rHeight;
    int lHeight;
    //if node does not exist return 0 
    if (node == nullptr) {
        return 0;
    }
    //if it is a leaf node, return 0
    if (node->getLeft() == nullptr && node->getRight() == nullptr) {
        return 0;
    }
    //find the heights of the branches
    lHeight = height(node->getLeft());
    rHeight = height(node->getRight());
    //the balance bactor of a node is it's left height minus right height
    return lHeight - rHeight;
}

//helper function for balance factor
int AVLTree::height(Node *node) {
    int leftH;
    int rightH;
    //if node does not exist return 0
    if (node == nullptr) {
        return 0;
    }
    //find the heights of the left and right branches recursively
    leftH = height(node->getLeft());
    rightH = height(node->getRight());
    //find the higher value between 
    return max(leftH, rightH )+ 1;
}

//return the closest unbalanced node (with a balance factor of 2 or -2)
Node* AVLTree::findUnbalancedNode(Node* newNode) {
    int nodeBalanceFactor = balanceFactor(newNode);
    if (nodeBalanceFactor > -1 || nodeBalanceFactor > 1) {
        //closest unbalanced node because it is the node itself 
        return newNode;
    }
    //check if the parent is unbalanced
    if (newNode->getParent() != nullptr) {
        if (newNode->getParent()->getBalanceFactor() > 1 || newNode->getParent()->getBalanceFactor() < -1) {
            //return parent node
            return newNode->getParent();
        }
        else {
            return findUnbalancedNode(newNode->getParent()); 
        }
    }
    return nullptr;
}

//print function 
void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
    cout << endl;
}

//helper function
void AVLTree::printBalanceFactors(Node *userNode) {   //print balance factors in inOrder notation
     //if empty, return 
    if(userNode == nullptr) {
        return;
    }
    printBalanceFactors(userNode->getLeft()); 
    cout << userNode->getWord() << "(" << getBalanceFactor(userNode) << ")" << ", ";

    printBalanceFactors(userNode->getRight());
}

//my own print function to test
 void AVLTree::preOrder() const {
    preOrderRecursive(root);
 }

 void AVLTree::preOrderRecursive(Node *keyNode) const {
    if (keyNode == nullptr) {
        return;
    }
    //visit node 
    cout << keyNode->getWord() << "(" << keyNode->getCount() << ")" << ", ";
   
    preOrderRecursive(keyNode->getLeft());
    preOrderRecursive(keyNode->getRight());
 }





