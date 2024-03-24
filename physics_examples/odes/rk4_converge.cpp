#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long double analytic(long double omega, long double x0, long double v0, long double t) {
    long double A = sqrt(x0*x0 + v0*v0/(omega*omega));
    long double phi = atan2(v0, omega*x0);
    return A*cos(omega*t - phi);
}

long double dvdt(long double omega, long double x) {
    return -omega*omega*x;
}

long double rk4(long double omega, long double x, long double v, long double tf, long double dt) {
    // RK4 terms
    long double xk1,xk2,xk3,xk4;
    long double vk1,vk2,vk3,vk4;
    for(long double t=0;t<=tf;t+=dt) {
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
    return x;
}

int main() {
    // angular frequency
    long double omega = 1;
    // initial conditions
    long double x0 = 1; 
    long double v0 = 10;
    long double tf = 100;

    long double err;
    for(long double dt=0.1;dt>5e-6;dt/=10) {
        err = abs(analytic(omega, x0, v0, tf)-rk4(omega*omega, x0, v0, tf, dt));
        cout << std::scientific << "dt: " << dt << " error: " << err << endl;
    }
    return 0;
}
