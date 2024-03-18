#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double bisect(double xl, double xr, double (*f)(double), double tol) {
    double xm = 0.5*(xl+xr);
    double fl = f(xl);
    double fm = f(xm);
    double fr = f(xr);
    int count = 0;
    while(abs(fm) > tol) {
        fm = f(xm);
        if(fm > 0) {
            xr = xm;
            fr = fm;
        }
        else {
            xl = xm;
            fl = fm;
        }
        xm = 0.5*(xl+xr);
        count++;
    }
    cout << "Converged after " << count << " iterations." << endl;
    return xm;
}

double func(double x) {
    return exp(x)*log(x) - x*x;
}

int main() {
    double root = bisect(1,2,func, 1e-6);
    cout << setprecision(16) << "The function has a root in [1,2] at " << root << endl;
    return 0;
}
