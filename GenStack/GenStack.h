// Ayden Best
// 2317839

#include <iostream>
#include "GenStackEmptyException.h"

using namespace std;

template <typename T>
class GenStack {
private:
  int maxSize;                // Maximum number of elements allowed in stackArray
  int t;                    // The index of the top element in stackArray
  T* stackArray;             // The array that holds all items in the stack

  void grow();              // Doubles the size of the stack, in case the stack is full and needs more room

public:

    GenStack();               // Default Constructor
    GenStack(int startSize);  // Overloaded Constructor
    ~GenStack();                // Destructor

    T pop() throw(GenStackEmptyException);                  // Removes and returns the top element

    T top();                  // Returns the top element

    void push(T element);     // Pushes an element to the top of the stack

    int size();               // Returns the number of items in the stack

    bool empty();             // Returns true if the stack is empty


};

#include "GenStackImplementation.h"
