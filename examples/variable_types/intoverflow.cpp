#include <iostream>

using namespace std;

int main()
{
  char i;
  int n;

  i=0;

  for (n=0;n<512;n++) {
    i=i+1;
    cout << n << "  i = " << 0+i << "\n";
  }

  unsigned int p;

  p=0;
  p--;
  cout << "int 0 - 1 = " << p << "\n";
}
