#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
#include <iomanip> 

using namespace std;

struct Node {

    public: 
    Node();
    //getter functions 
    string getWord();
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    int getCount();
    //setter functions
    void setWord(const string& w);
    void setLeft(Node* userLeft);
    void setRight(Node* userRight);
    void setCount(int newCount);
    
    private:
        string word;
        int count;
        Node* left;
        Node* right;
        Node* parent;
    
};























#endif
