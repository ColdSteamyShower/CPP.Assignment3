#include <iostream>
#include <fstream>
#include "./GenStack/GenStack.h"
#include "./SyntaxChecker/syntaxChecker.h"

using namespace std;

int main(int argc, char *argv[]){
  string file = argv[1];                                                        //
  ifstream inFile(file);                                                        // Make sure that the file exists
  if (!inFile)                                                                  //
  {                                                                             //
    cout << "File '" << file << "' cannot be read or does not exist" << endl;   //
  } else {
    inFile.close();             //
    syntaxChecker checker;      // if it does, we're allowed to run the program
    checker.checkFile(file);    //
  }
}
