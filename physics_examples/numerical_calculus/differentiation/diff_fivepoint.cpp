#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

double deriv(double x0, double (*f)(double), double h) {
    return (f(x0-2*h) - 8*f(x0-h) + 8*f(x0+h) - f(x0+2*h))/(12*h);
}

double func(double x) {
    return sin(x);
}

double dfunc(double x) {
    return cos(x);
}

int main() {
    for(double h=0.1;h>1e-3;h/=2) {
        cout << "Error @ x=1 when h=" << left << setw(10) <<  h << " : " << fabs(deriv(1, func, h)-dfunc(1)) << endl;
    }
    return 0;
}
