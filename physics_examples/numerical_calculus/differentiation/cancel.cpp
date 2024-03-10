#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float h = 0.0125;
    cout << "float" << endl;
    cout << "--------------------------------" << endl;
    cout << "sin(1-h)-2sin(1) : " << setprecision(9) << sin(1-h)-2*sin(1) << endl;
    cout << "sin(1+h)         :  " << sin(1+h) << endl;
    cout << "sum              : " << sin(1-h) - 2*sin(1) + sin(1+h) << endl;
    cout << "2diff            : " << (sin(1-h) - 2*sin(1) + sin(1+h))/(h*h) << endl;
    cout << "true             : " << -sin(1) << endl;
    double dh = 0.0125;
    cout << "double" << endl;
    cout << "--------------------------------" << endl;
    cout << "sin(1-h)-2sin(1) : " << sin(1-h)-2*sin(1) << endl;
    cout << "sin(1+h)         :  " << sin(1+dh) << endl;
    cout << "sum              : " << sin(1-dh) - 2*sin(1) + sin(1+dh) << endl;
    cout << "2diff            : " << (sin(1-dh) - 2*sin(1) + sin(1+dh))/(dh*dh) << endl;
    cout << "true             : " << -sin(1) << endl;
    return 0;
}
