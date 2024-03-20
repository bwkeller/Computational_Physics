#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double analytic(double omega, double x0, double v0, double t) {
    double A = sqrt(x0*x0 + v0*v0/(omega*omega));
    double phi = atan2(v0, omega*x0);
    return A*cos(omega*t - phi);
}

int main() {
    // angular frequency
    double omega = 1;
    // initial conditions
    double x0 = 10; 
    double v0 = -1;
    double tf = 20*M_PI;
    double dt = 0.1;
    double v_next = v0;
    double x_next = x0;
    for(int k=0;k<50;k++) {
        x_next = x0 + (dt/2)*(v0 + v_next);
        v_next = v0 - (dt/2)*omega*omega*(x0+x_next);
        cout << (x_next - analytic(omega, x0, v0, dt))/analytic(omega, x0, v0, dt) << endl;
    }

    return 0;
}
