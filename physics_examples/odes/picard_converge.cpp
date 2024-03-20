#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double analytic(double omega, double x0, double v0, double t) {
    double A = sqrt(x0*x0 + v0*v0/(omega*omega));
    double phi = atan2(v0, omega*x0);
    return A*cos(omega*t - phi);
}

double picard(double omega, double x, double v, double tf, double dt) {
    double x0 = x;
    double v0 = v;
    for(double t=0;t<=tf;t+=dt) {
        double v_next = v;
        double x_next = x;
        for(int k=0;k<10;k++) {
            x_next = x + (dt/2)*(v + v_next);
            v_next = v - (dt/2)*omega*omega*(x + x_next);
        }
        x = x_next;
        v = v_next;
    }
    return x;
}

int main() {
    // angular frequency
    double omega = 1;
    // initial conditions
    double x0 = 1; 
    double v0 = 10;
    double tf = 100;

    double err;
    for(double dt=0.1;dt>5e-6;dt/=10) {
        err = abs(analytic(omega, x0, v0, tf)-picard(omega*omega, x0, v0, tf, dt));
        cout << std::scientific << "dt: " << dt << " error: " << err << endl;
    }
    return 0;
}
