#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h> 

using namespace std;

double func(double x) {
    return sin(x);
}

double ifunc(double a, double b) {
    return -cos(b) + cos(a);
}

double mc_int(double a, double b, double (*f)(double), int N) {
    double result=0;
    double randx;
    for(int i=0; i<N;i++) {
        randx = (b-a)*((float) rand())/RAND_MAX + a;  // We need random numbers between a and b
        result += f(randx);
    }
    return (b-a)*result/N;
}

int main()
{
    srand(420);
    cout << "True Integral: " << ifunc(0,1) << " Monte Carlo Estimate: " << mc_int(0,1, func, 100) << endl;
    return 0;
}
