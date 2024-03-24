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
    outfile.open("rk4.txt");
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
    // RK4 terms
    double xk1,xk2,xk3,xk4;
    double vk1,vk2,vk3,vk4;

    for(double t=0;t<=100;t+=dt) {
        outfile << t << " " << x << " " << analytic(omega, x0, v0, t) << endl;
        xk1 = v;
        vk1 = dvdt(omega, x);
        xk2 = v+dt*vk1/2;
        vk2 = dvdt(omega, x+dt*xk1/2);
        xk3 = v+dt*vk2/2;
        vk3 = dvdt(omega, x+dt*xk2/2);
        xk4 = v+dt*vk3;
        vk4 = dvdt(omega, x+dt*xk3);

        v += (dt/6)*(vk1+2*vk2+2*vk3+vk4);
        x += (dt/6)*(xk1+2*xk2+2*xk3+xk4);
    }
    outfile.close();
    return 0;
}
