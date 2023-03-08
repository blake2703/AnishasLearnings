#pragma once

#include <iostream>
#include <iomanip> 

using namespace std;

struct Node {
    public: 
    /*
    *   The constructor of the node struct.
    *   It creates an empty node with all private members empty, nullptr, or 0
    * 
    *   Params:
    *       None
    * 
    *   Return:
    *       None
    */
    Node();
    /*
    *   Getter functions.
    *   It will return the private member variable
    */
    string getWord();
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    int getCount();
    int getBalanceFactor();
    /*
    *   Setter functions.
    *   It will set the private member variable to a passed in parameter that matches the data type of that private 
    *   member variable
    */
    void setWord(const string& w);
    void setLeft(Node* userLeft);
    void setRight(Node* userRight);
    void setCount(int newCount);
    void setParent(Node* userParent); 
    void setBalanceFactor(int num);
        
    private:
        string word;    //a string that contains the word 
        int count;      //an int that displays how much of a given word is in the tree
        int bFactor;    //an int that shows the balance factor(left height - right height)
        Node* left;     //a node that points to the left of the current node
        Node* right;    //a node that points to the right of the current node
        Node* parent;   //a node that points to the parent of the current node
};