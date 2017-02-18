#include <iostream>
#include <exception>

class DivideByZeroException : public std::exception {
public:
  virtual const char* what() const throw() {
    return "Tried to divide by zero.";
  }
};

class SillyNumeratorException : public std::exception {
public:
  virtual const char* what() const throw() {
    return "Why would you want to divide that?";
  }
};

float divide(float numerator, float denominator) {
  if (denominator == 0) {
    // throw "Trying to divide by zero.";
    // throw 20;
    // throw 'a';
    throw DivideByZeroException();
  }
  if (numerator == 10) {
    throw SillyNumeratorException();
  }
  std::cout << "Finishing inside divide()." << std::endl;
  return numerator / denominator;
}

int main() {
  try {
    float result = divide(8, 0);
    std::cout << "Continuing after call to divide()." << std::endl;
  } catch (const std::exception& e) {
    std::cout << "Error trying to divide: " << e.what() << std::endl;
  }
  // } catch (const DivideByZeroException& e) {
  //   std::cout << "Error trying to divide: " << e.what() << std::endl;
  // } catch (const SillyNumeratorException& e) {
  //   std::cout << "Error trying to divide: " << e.what() << std::endl;
  // }
  // } catch (const char* e) {
  //   std::cout << "String error trying to divide: " << e << std::endl;
  // } catch (int e) {
  //   std::cout << "Int error trying to divide: " << e << std::endl;
  // } catch (...) {
  //   std::cout << "Unexpected error trying to divide." << std::endl;
  // }

  std::cout << "Done with program." << std::endl;
}
