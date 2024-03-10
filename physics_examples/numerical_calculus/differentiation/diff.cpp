#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

float deriv(float x0, float (*f)(float), float h) {
    return (f(x0 + h) - f(x0))/ h;
}

float func(float x) {
    return sin(x);
}

float dfunc(float x) {
    return cos(x);
}

int main() {
    float h=0.1;
    ofstream outfile;
    outfile.open("diff.txt");
    for(float x=0;x<20*M_PI;x+=h) {
        outfile << x << " " << deriv(x, func, h) << " " << dfunc(x) << endl;
    }
    outfile.close();
    return 0;
}
