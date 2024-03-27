#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double dvdt(double omega, double x) {
    return -omega*omega*x;
}

int main() {
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
    double x_ec = x0;
    double v_ec = x0;
    double x_kdk = x0;
    double v_kdk = v0;
    // RK4 terms
    double xk1,xk2,xk3,xk4;
    double vk1,vk2,vk3,vk4;

    for(int i=0;i<5e5;i++) {
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

        v_ec -= dt*x_ec;
        x_ec += dt*v_ec;

        v_kdk -= 0.5*dt*x_kdk;
        x_kdk += dt*v_kdk;
        v_kdk -= 0.5*dt*x_kdk;
    }
    // Reverse time!
    dt = -dt;
    for(int i=0;i<5e5;i++) {
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

        v_ec -= dt*x_ec;
        x_ec += dt*v_ec;

        v_kdk -= 0.5*dt*x_kdk;
        x_kdk += dt*v_kdk;
        v_kdk -= 0.5*dt*x_kdk;
    }
    cout << "Initial Conditions:      x=" << x0 << " v=" << v0 << endl;
    cout << "Runge-Kutta Returns to : x=" << x << " v=" << v << endl;
    cout << "Euler-Cromer Returns to: x=" << x_ec << " v=" << v_ec << endl;
    cout << "Leapfrog Returns to :    x=" << x_kdk << " v=" << v_kdk << endl;
    return 0;
}
