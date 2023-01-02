#include <stack>
#include <algorithm>
#include <iostream>

#include "stackADT.h"

using namespace std;

int main() {
    /*
    *   Utilize the STL stack
    */
   stack<int> myStack;      //create a STL stack
   myStack.push(5);         //add 5 to the stack
   myStack.push(7);         //add 7 to the stack
   myStack.push(3);         //add 3 to the stack
   myStack.pop();           //remove 3 from the stack
   myStack.top();           //return reference to top the of the stack, which is 7
   /*
   *    Print all elements in a stack
   */
   while(!myStack.empty()) {
        cout << myStack.top() << endl;
        myStack.pop();
   }
   
   /*
   *    Utilize array stackADT
   */
  stackADT<int> myStack2;
  myStack2.push(5);
  myStack2.push(7);
  myStack2.push(3);
  myStack2.pop();
  myStack2.top();
  while(!myStack2.empty()) {
        cout << myStack2.top() << endl;
        myStack2.pop();
  }



    return 0;
}