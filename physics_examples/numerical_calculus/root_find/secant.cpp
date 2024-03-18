#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double secant(double x0, double x1, double (*f)(double), double tol) {
    int count=0;
    double x_old;
    while(abs(f(x0)) > tol) {
        x_old = x0;
        x0 -= f(x0)*(x0-x1)/(f(x0)-f(x1));
        x1 = x_old;
        count++;
    }
    cout << "Converged after " << count << " iterations." << endl;
    return x0;
}

double func(double x) {
    return exp(x)*log(x) - x*x;
}

int main() {
    double root = secant(1, 2, func, 1e-6);
    cout << setprecision(16) << "The function has a root in [1,2] at " << root << endl;
    return 0;
}
