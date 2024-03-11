#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

float integral(float a, float b, float (*f)(float), int N) {
    float result=0;
    float h = (b-a)/N;
    for(float xi=a;xi<b;xi+=h) {
        result += f(xi)*h;
    }
    return result;
}

float func(float x) {
    return sin(x);
}

float ifunc(float a, float b) {
    return -cos(b) + cos(a);
}

int main() {
    float h=0.1;
    ofstream outfile;
    outfile.open("int.txt");
    for(float x=0;x<20*M_PI;x+=h) {
        outfile << x << " " << integral(0, x, func, 100) << " " << ifunc(0, x) << endl;
    }
    outfile.close();
    return 0;
}
