#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

double pc(double omega, double x, double v, double tf, double dt) {
    double x_pred, v_pred;
    double x_old;
    for(double t=0;t<=tf;t+=dt) {
        // Predict values with Euler's method
        x_pred = x + dt*v;
        v_pred = v - dt*omega*omega*x;

        // Correct the predictions using the trapezoid rule
        x_old = x;
        x = x + 0.5*dt*(v + v_pred);
        v = v - 0.5*dt*omega*omega*(x_old + x_pred);
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
    double tf = 100;

    double err;
    for(double dt=0.1;dt>5e-6;dt/=10) {
        err = abs(analytic(omega, x0, v0, tf)-pc(omega*omega, x0, v0, tf, dt));
        cout << std::scientific << "dt: " << dt << " error: " << err << endl;
    }
    return 0;
}
