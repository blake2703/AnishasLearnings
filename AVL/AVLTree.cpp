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
    else if (balance_factor < 1) {
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
    Node* curr = root;
    Node* parent = nullptr;
    

    // Traverse the tree to find the correct position to insert the new node
    while (curr != nullptr) {
        parent = curr;
        if (newString < curr->getWord()) {
            curr = curr->getLeft();
        } else if (newString > curr->getWord()) {
            curr = curr->getRight();
        } else {
            // If the string already exists in the tree, just increment the node's count and return
            curr->setCount(curr->getCount() + 1);
            return;
        }
    }
    // Create a new node and set its word and count
    Node* newNode = new Node();
    newNode->setWord(newString);
    newNode->setCount(1);

    // Set the new node's parent and insert it into the correct position
    newNode->setParent(parent);
    if (parent == nullptr) {
        root = newNode;
    } else if (newString < parent->getWord()) {
        parent->setLeft(newNode);
        root = balance(root);
    } else {
        parent->setRight(newNode);
        root = balance(root);
    } 

    //find nearest unbalanced node and rotate if needed 
    Node *unbalancedNode = findUnbalancedNode(newNode);
    //if no unbalanced node, simply return;
    if (unbalancedNode == nullptr) {
        return;
    }
}

//takes in the unbalanced node, which is the root of the subtree
void rotate(Node* node) {
   
} 

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





