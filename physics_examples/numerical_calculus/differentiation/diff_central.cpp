#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

float deriv(float x0, float (*f)(float), float h) {
    return (f(x0 + h) - f(x0 - h))/ (2*h);
}

float func(float x) {
    return sin(x);
}

float dfunc(float x) {
    return cos(x);
}

int main() {
    for(float h=0.1;h>1e-3;h/=2) {
        cout << "Error @ x=1 when h=" << left << setw(10) <<  h << " : " << fabs(deriv(1, func, h)-dfunc(1)) << endl;
    }
    return 0;
}
