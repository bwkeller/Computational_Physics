#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


double analytic(double omega, double x0, double v0, double t) {
    double A = sqrt(x0*x0 + v0*v0/(omega*omega));
    double phi = atan2(v0, omega*x0);
    return A*cos(omega*t - phi);
}

double dvdt(double omega, double x) {
    return -omega*omega*x;
}

int main() {
    ofstream outfile;
    outfile.open("rk2.txt");
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
    // RK2 terms
    double xk1,xk2;
    double vk1,vk2;

    for(double t=0;t<=100;t+=dt) {
        outfile << t << " " << x << " " << analytic(omega, x0, v0, t) << endl;
        xk1 = v;
        vk1 = dvdt(omega, x);
        xk2 = v+dt*vk1;
        vk2 = dvdt(omega, x+dt*xk1);

        v += (dt/2)*(vk1+vk2);
        x += (dt/2)*(xk1+xk2);
    }
    outfile.close();
    return 0;
}
