#include "Node.h"
#include <ostream>
#include <iostream>
#include <iomanip> 


Node::Node() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

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
