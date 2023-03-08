#include "Node.h"
#include "AVLTree.h"
#include <ostream>
#include <iostream>
#include <iomanip> 


Node::Node() {
    word = "";
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    bFactor = 0;
    count = 0;
}
//getters
string Node::getWord() {
    return word;
}
Node* Node::getLeft() {
    return left;
}
Node* Node::getRight(){
    return right;
}

Node* Node::getParent() {
    return parent;
}

int Node::getCount() {
    return count;
}
int Node::getBalanceFactor() {
    return bFactor;
}


//setters

void Node::setWord(const string& w) {
    word = w;
}
void Node::setLeft(Node* userLeft) {
    left = userLeft;
}
void Node::setRight(Node* userRight) {
    right = userRight;
}
void Node::setCount(int newCount) {
    count = newCount;
}
void Node::setParent(Node* userParent) {
    parent = userParent;
}

void Node::setBalanceFactor(int num) {
    bFactor = num;
}
