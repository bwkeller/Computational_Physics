#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

double analytic(double omega, double x0, double v0, double t) {
    double A = sqrt(x0*x0 + v0*v0/(omega*omega));
    double phi = atan2(v0, omega*x0);
    return A*cos(omega*t - phi);
}
int main() {
    ofstream outfile;
    outfile.open("picard.txt");
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
    double dv;
    for(double t=0;t<=100;t+=dt) {
        double v_next = v;
        double x_next = x;
        for(int k=0;k<10;k++) {
            x_next = x + (dt/2)*(v + v_next);
            v_next = v - (dt/2)*omega*omega*(x + x_next);
        }
        x = x_next;
        v = v_next;
        outfile << t << " " << x << " " << analytic(omega, x0, v0, t) << endl;
    }
    outfile.close();
    return 0;
}
