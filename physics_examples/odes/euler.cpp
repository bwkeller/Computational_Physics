#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


double analytic(double omega, double x0, double v0, double t) {
    double A = sqrt(x0*x0 + v0*v0/(omega*omega));
    double phi = atan2(v0, omega*x0);
    return A*cos(omega*t - phi);
}

int main() {
    ofstream outfile;
    outfile.open("euler.txt");
    //timestep
    double dt=0.001;
    // angular frequency
    double omega = 1;
    // initial conditions
    double x0 = 1; 
    double v0 = 10;
    // dynamical variables
    double x = x0;
    double v = v0;
    // temporary variable
    double dv;
    for(double t=0;t<=20*M_PI;t+=dt) {
        dv = -omega*omega*x*dt;
        x += v*dt;
        v += dv;
        outfile << t << " " << x << " " << analytic(omega, x0, v0, t) << endl;
    }
    outfile.close();
    return 0;
}
