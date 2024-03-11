#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double rectangle(double a, double b, double (*f)(double), int N) {
    double result=0;
    double h = (b-a)/N;
    for(double xi=a;xi<b;xi+=h) {
        result += f(xi)*h;
    }
    return result;
}

double trapezoid(double a, double b, double (*f)(double), int N) {
    double result=0;
    double h = (b-a)/N;
    for(double xi=a;xi<b;xi+=h) {
        result += (f(xi)+f(xi+h))*h/2;
    }
    return result;
}

double simpson(double a, double b, double (*f)(double), int N) {
    double result=0;
    double h = (b-a)/N;
    for(double xi=a;xi<b;xi+=h) {
        result += (f(xi)+4*f(xi+0.5*h)+f(xi+h))*h/6;
    }
    return result;
}

double func(double x) {
    return sin(x);
}

double ifunc(double a, double b) {
    return -cos(b) + cos(a);
}

int main() {
    int N=100;
    cout << "Rectangle Rule Error: " << fabs(ifunc(0,1) - rectangle(0,1, func, N)) << endl;
    cout << "Trapezoid Rule Error: " << fabs(ifunc(0,1) - trapezoid(0,1, func, N)) << endl;
    cout << "Simpson's Rule Error: " << fabs(ifunc(0,1) - simpson(0,1, func, N)) << endl;
    return 0;
}
