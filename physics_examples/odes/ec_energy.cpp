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
    outfile.open("ec_energy.txt");
    //timestep
    double dt=0.1;
    // angular frequency
    double omega = 1;
    // initial conditions
    double x0 = 1; 
    double v0 = 10;
    // dynamical variables
    double x = x0;
    double v = v0;

    for(int i=0;i<5e5;i++) {
        // Print out the total energy
        if (i % 100 == 0) {
            outfile << i*dt << " " << (x*x+v*v)/2 << endl;
        }

        v -= dt*x;
        x += dt*v;

    }
    outfile.close();
    return 0;
}
