#pragma once

#include "Node.h"
#include "AVLTree.h"
#include <iomanip> 
#include <stdexcept>


class AVLTree {

    private:
    Node *root;
    Node* findUnbalancedNode(Node* newNode);
    void rotate(Node* node, bool rightOrLeft);
    Node* rotateLeftRight(Node* node);
    Node* rotateRightLeft(Node* node);
    Node* rotateRightRight(Node* node);
    Node* rotateLeftLeft(Node* node);
    void printBalanceFactors(Node *userNode);
    void visualizeTree(ofstream &, Node *);


    //destructor helper function
    void deleteTree(Node *userNode);
    //helper print function 
    void preOrderRecursive(Node *keyNode) const;
    //helper function for the balance factor function 
    int height(Node *node);
    int getBalanceFactor(Node * node);
    void setBalanceFactor(Node *node);
    

    public:
    //Constructor
    AVLTree();
    //Destructor
    ~AVLTree();
    //insert function
    void insert(const string & newString);
    int balanceFactor(Node* node);
    
    void printBalanceFactors();
    void visualizeTree(const string &);
    //print function
    void preOrder() const;

    Node* balance(Node* node);
    Node* insertRec(Node* node, string val);


};
