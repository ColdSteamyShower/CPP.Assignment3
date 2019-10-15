#include <iostream>
#include <fstream>
#include "./GenStack/GenStack.h"
#include "./SyntaxChecker/syntaxChecker.h"

using namespace std;

int main(int argc, char *argv[]){

  //initialize
  string file = argv[1];
  syntaxChecker checker;

  while (true)
  {
    ifstream inFile(file);
    if (!inFile)
    { // If the file doesn't exist, notify the user
      cout << "File '" << file << "' cannot be read or does not exist" << endl;
    }
    else
    { // If the file exists, check the file
      inFile.close();
      if (checker.checkFile(file)){ // if there were no errors, continue
        cout << "No Errors were found" << endl;
      } else { // if there were errors, quit
        break;
      }
    }
    cout << "Enter a file name or enter 'e' to exit the program" << endl;
    cin >> file;
    if (file == "e")
      break;
  }
}
