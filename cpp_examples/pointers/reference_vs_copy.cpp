#include <iostream>

using namespace std;

int main() {
  int var1;
  int var2;
  int *ptr;
  
  var1 = 8;

  ptr = &var1;
  var2 = var1;

  cout << "value of var1 " << var1 << " value of var2 " << var2 << " value of *ptr " << *ptr << endl;

  var1 = 16;

  cout << "value of var1 " << var1 << " value of var2 " << var2 << " value of *ptr " << *ptr << endl;


  return 0;
}


