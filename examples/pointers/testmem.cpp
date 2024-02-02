#include <iostream>

using namespace std;

// Try compiling with -Os
int main() {
  int a=1;
  double r;
  float x[3];

  x[0]=2.0;
  r=x[0]*x[0];

  // Check what happens when the cast is removed
  cout << "address of    a " <<  (long) &a << endl;
  cout << "address of    r " <<  (long) &r << endl;
  cout << "address of x[0] " <<  (long) &x[0] << endl;
  cout << "address of x[1] " <<  (long) &x[1] << endl;
  cout << "address of x[2] " <<  (long) &x[2] << endl;
  return 0;
}


