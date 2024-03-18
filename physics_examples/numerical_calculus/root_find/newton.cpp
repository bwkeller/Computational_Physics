#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double newton(double x0, double (*f)(double), double (*df)(double), double tol) {
    int count=0;
    while(abs(f(x0)) > tol) {
        x0 -= f(x0)/df(x0);
        count++;
    }
    cout << "Converged after " << count << " iterations." << endl;
    return x0;
}

double func(double x) {
    return exp(x)*log(x) - x*x;
}

double dfunc(double x) {
    return exp(x)/x + exp(x)*log(x) - 2*x;
}

int main() {
    double root = newton(1.5, func, dfunc, 1e-6);
    cout << setprecision(16) << "The function has a root in [1,2] at " << root << endl;
    return 0;
}
