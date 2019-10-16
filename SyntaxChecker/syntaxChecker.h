#include <iostream>
#include <fstream>

using namespace std;

class syntaxChecker{
private:
  GenStack<char> *stackPtr; // the stack
  int line; // keeps track of current line in the file
  bool inString; // decides whether the source file is in the middle of a string or not
  bool inComment; // decides whether the source file is in the middle of a commented line or not
  char charCache; // used to remember what the previous char was

public:
  syntaxChecker(); // Constructor

  // destructor is not needed, because stackPtr is not declared/destroyed in the creation/deletion of the class object

  // precondition: string is a readable source file that exists
  bool checkFile(string fileName);
  // postcondition: iterates through the file to check for syntax errors. returns true if there are none

  // precondition: c is a valid char
  bool errorCheck(char c);
  // postcondition: Checks to see if the character breaks syntax. Returns true if it doesn't break. Returns false if it does.

  // precondition: checkFile() is running
  bool stringCommentHandler(char c);
  //postcondition: based on current status and entered char, handles inString and inComment. returns true if inString or inComment are true

  // precondition: char is a delimiter [, (, {, ], ) or }
  const char oppositeDelimiter(char d);
  // postcondition: returns the mirrored version of the delimiter
};
