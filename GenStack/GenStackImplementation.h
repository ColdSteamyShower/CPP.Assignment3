#include <iostream>

using namespace std;

// Default Constructor
template <typename T>
GenStack<T>::GenStack()
{
  maxSize = 1;
  t = -1;
  stackArray = new T[1];
}

// Overloaded Constructor
template <typename T>
GenStack<T>::GenStack(int startSize)
{
  maxSize = startSize;
  t = -1;
  stackArray = new T[startSize];
}

// Destructor
template <typename T>
GenStack<T>::~GenStack()
{
  delete[] stackArray;
  stackArray = NULL;
}

// Removes and returns the top element
template <typename T>
T GenStack<T>::pop() throw(GenStackEmptyException)
{
  if (empty())
    throw GenStackEmptyException();
  --t;
  return stackArray[t+1];
}

// Returns the top element
template <typename T>
T GenStack<T>::top()
{
  if (empty())
    throw GenStackEmptyException();
  return stackArray[t];
}

// Pushes an element to the top of the stack
template <typename T>
void GenStack<T>::push(T element)
{
  if (t+1 == maxSize)
    grow();
  ++t;
  stackArray[t] = element;
}

// Returns the number of items in the stack
template <typename T>
int GenStack<T>::size()
{
  return (t+1);
}

// Returns true if the stack is empty
template <typename T>
bool GenStack<T>::empty()
{
  return (t == -1);
}

// Doubles the size of the stack, in case the stack is full and needs more room
template <typename T>
void GenStack<T>::grow()
{
  T *temp = new T[maxSize*2]; // new array twice the size
  for (int i=0 ; i<maxSize ; ++i){ // fill new array with old information
    temp[i] = stackArray[i];
  }
  delete[] stackArray; // clean up
  stackArray = temp;
  temp = NULL;
}
