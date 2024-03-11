#include <iostream>
#include <iomanip>
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
    cout << "N | Rectangle Error | Trapezoid Error | Simpson Error" << endl;
    for(int N=8;N<256;N*=2) {
    cout << left << setw(4) << N;
    cout << left << setw(18) << fabs(ifunc(0,1) - rectangle(0,1, func, N));
    cout << left << setw(18) << fabs(ifunc(0,1) - trapezoid(0,1, func, N));
    cout << left << setw(18) << fabs(ifunc(0,1) - simpson(0,1, func, N));
    cout << endl;
    }
    return 0;
}
