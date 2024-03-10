#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

double second_deriv(double x0, double (*f)(double), double h) {
    return (f(x0-h) - 2*f(x0) + f(x0+h))/(h*h);
}

double func(double x) {
    return sin(x);
}

double d2func(double x) {
    return -sin(x);
}

int main() {
    for(double h=0.1;h>1e-3;h/=2) {
        cout << "Error @ x=1 when h=" << left << setw(10) <<  h << " : " << fabs(second_deriv(1, func, h)-d2func(1)) << endl;
    }
    return 0;
}
