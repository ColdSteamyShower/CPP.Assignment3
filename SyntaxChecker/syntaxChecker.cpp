#include <iostream>
#include <fstream>
#include "../GenStack/GenStack.h"
#include "syntaxChecker.h"

using namespace std;

//constructor
syntaxChecker::syntaxChecker()
{
  inString = false;
  inComment = false;
  stackPtr = NULL;
  line = 0;
  charCache = ' ';
  cout << "syntaxChecker created" << endl;
}

void syntaxChecker::checkFile(string fileName)
{
  cout << "Checking File..." << endl;
  stackPtr = new GenStack<char>;
  ifstream inFile(fileName);
  line = 1;
  char c;
  bool stopped = false;
  while (inFile.get(c)) // check for every character
  {
    if (stringCommentHandler(c))
      continue;
    if (errorCheck(c)){
      stopped = true;
      break;
    }
    charCache = c; // charCache = previous character
    if (c == '\n')
    {
      inComment = false;
      ++line;
    }
  }

  while (!stopped && !stackPtr->empty()) // if there are delimiters that have not been closed, notify user
  {
    cout << "Reached end of file: Missing " << oppositeDelimiter(stackPtr->pop()) << endl;
  }

  //cleanup
  delete stackPtr;
  stackPtr = NULL;
  inFile.close();

  cout << "Done!" << endl;
}

bool syntaxChecker::stringCommentHandler(char c)
{
  if ((c == '/' && charCache == '/')) // if it comes across //
  {
    if (!inString)
      inComment = true;
    return true;
  }
  else if (c == '"') // if it comes across "
  {
    cout << "a string character was found!" << endl;
    inString = (!inString);
    return true;
  }
  else if (inString || inComment) // if it is a normal char, but the program is in a string or comment, continue without checking
  {
    return true;
  } else
  {
    return false;
  }
}

bool syntaxChecker::errorCheck(char c)
{

  if ( c == '[' || c == '{' || c == '(' ) // is an opening delimiter
  {
    cout << "Found " << c << ". Pushing..." << endl;
    stackPtr->push(c);
    return false;
  }
  else if ( c == ']' || c == '}' || c == ')' ) // is a closing delimiter
  {
    cout << "Found " << c << "..." << endl;
    try
    {
      char popped = stackPtr->pop();
      if (popped == oppositeDelimiter(c)) // if the delimiter is closed correctly
      {
        cout << "Delimiters Closed Correctly" << endl;
        return false;
      }
      else // if the delimiter is not closed correctly
      {
        cout << "Line " << line << ": Expected " << oppositeDelimiter(popped) << " but found " << c << endl;
        return true;
      }
    }
    catch (GenStackEmptyException e) // if there is one more closing delimiter than there should be
    {
      cout << "Line " << line << ": Found stray " << c << " that does not follow an opening delimiter" << endl;
      return true;
    }
  }
  else
  {
    return false;
  }
}


// precondition: char is a delimiter [, (, {, ], ) or }
const char syntaxChecker::oppositeDelimiter(char d)
{
  switch (d)
  {
    case '[': return ']';
    case '{': return '}';
    case '(': return ')';
    case ']': return '[';
    case '}': return '{';
    case ')': return '(';
    default: return ' ';
  }
}
