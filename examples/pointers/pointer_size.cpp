#include <iostream>

using namespace std;

int main() {
  int a=1;
  double r;
  float x[3];

  x[0]=2.0;
  r=x[0]*x[0];

  cout << "size of pointer for    a " <<  sizeof(&a) << endl;
  cout << "size of pointer for    r " <<  sizeof(&r) << endl;
  cout << "size of pointer for x[0] " <<  sizeof(&x[0]) << endl;
  cout << "size of pointer for x[1] " <<  sizeof(&x[1]) << endl;
  cout << "size of pointer for x[2] " <<  sizeof(&x[2]) << endl;
  return 0;
}


