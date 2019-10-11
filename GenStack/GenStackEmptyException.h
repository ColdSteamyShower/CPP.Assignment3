#include <exception>

using namespace std;

class GenStackEmptyException {
private:
  string errorMessage;
public:
  GenStackEmptyException() //constructor
  {
    errorMessage = "The stack is empty. Cannot pop item";
  }

  GenStackEmptyException(string err) //constructor
  {
    errorMessage = err;
  }

  string getError() // accessing the error message
  {
    return errorMessage;
  }
};
