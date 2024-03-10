#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

float second_deriv(float x0, float (*f)(float), float h) {
    return (f(x0-h) - 2*f(x0) + f(x0+h))/(h*h);
}

float func(float x) {
    return sin(x);
}

float d2func(float x) {
    return -sin(x);
}

int main() {
    float h=0.1;
    ofstream outfile;
    outfile.open("second_diff.txt");
    for(float x=0;x<20*M_PI;x+=h) {
        outfile << x << " " << second_deriv(x, func, h) << " " << d2func(x) << endl;
    }
    outfile.close();
    return 0;
}
