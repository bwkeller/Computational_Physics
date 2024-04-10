#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <time.h> 

using namespace std;

double truefunc(double x) {
    return 6.*exp(-4.*(x+4.)*(x+4.)) + 2.*exp(-0.2*(x+1.)*(x+1.)) + exp(-2.*(x-5.)*(x-5.));
}


int main()
{
    return 0;
}
