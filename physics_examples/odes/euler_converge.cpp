#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double euler(double omega, double x, double v, double tf, double dt) {
    double dv;
    for(double t=0;t<=20*M_PI;t+=dt) {
        dv = -omega*x*dt;
        x += v*dt;
        v += dv;
    }
    return x;
}

double analytic(double omega, double x0, double v0, double t) {
    double A = sqrt(x0*x0 + v0*v0/(omega*omega));
    double phi = atan2(v0, omega*x0);
    return A*cos(omega*t - phi);
}

int main() {
    // angular frequency
    double omega = 1;
    // initial conditions
    double x0 = 1; 
    double v0 = 10;
    double tf = 20*M_PI;

    double err;
    for(double dt=0.1;dt>1e-6;dt/=10) {
        err = abs(analytic(omega, x0, v0, tf)-euler(omega*omega, x0, v0, tf, dt));
        cout << std::scientific << "dt: " << dt << " error: " << err << endl;
    }
    return 0;
}
