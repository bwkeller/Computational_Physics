#include <iostream>
#include <iomanip>

int main()
{
  float sum_float =0; 
  double sum_double =0;
  int sum_int =0;
  long sum_long =0;

  long n;
  long nmax;
 
  std::cout << "Enter a number to sum the natural numbers to (e.g. 1000000)\n";
  std::cin >> nmax;

  for (n=1;n<=nmax;n++) {
    sum_float = sum_float +  n;
    sum_double = sum_double +  n;
    sum_int = sum_int +  n;
    sum_long = sum_long +  n;
  }

  std::cout << "Sum of 1 to " << nmax << " = " << nmax*(nmax+1)/2 << "(Exact)\n";
  std::cout << std::setprecision(20) << "float  " << sum_float << "\n";
  std::cout << "double " << sum_double << "\n";
  std::cout << "int    " << sum_int << "\n";
  std::cout << "long   " << sum_long << "\n";
}
