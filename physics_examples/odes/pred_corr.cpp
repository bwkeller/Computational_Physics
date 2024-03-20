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
    ofstream outfile;
    outfile.open("pred_corr.txt");
    //timestep
    double dt=0.01;
    // angular frequency
    double omega = 1;
    // initial conditions
    double x0 = 1; 
    double v0 = 10;
    // dynamical variables
    double x = x0;
    double v = v0;
    // temporary variable
    double x_old, x_pred, v_pred;
    for(double t=0;t<=100;t+=dt) {
        // Predict values with Euler's method
        x_pred = x + dt*v;
        v_pred = v - dt*omega*omega*x;

        // Correct the predictions using the trapezoid rule
        x_old = x;
        x = x + 0.5*dt*(v + v_pred);
        v = v - 0.5*dt*omega*omega*(x_old + x_pred);
        outfile << t << " " << x << " " << analytic(omega, x0, v0, t) << endl;
    }
    outfile.close();
    return 0;
}
