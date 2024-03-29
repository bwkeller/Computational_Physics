#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


double analytic(double x) {
    return cos(M_PI*x/2) + 2*sin(M_PI*x/2) - 1;
}

double dzdx(double y) {
    return -0.25*M_PI*M_PI*(y+1);
}

void rk4_step(double *y, double *z, double dx) {
    // RK4 terms
    long double yk1,yk2,yk3,yk4;
    long double zk1,zk2,zk3,zk4;
    yk1 = *z;
    zk1 = dzdx(*y);
    yk2 = *z+dx*zk1/2;
    zk2 = dzdx(*y+dx*yk1/2);
    yk3 = *z+dx*zk2/2;
    zk3 = dzdx(*y+dx*yk2/2);
    yk4 = *z+dx*zk3;
    zk4 = dzdx(*y+dx*yk3);

    *z += (dx/6)*(zk1+2*zk2+2*zk3+zk4);
    *y += (dx/6)*(yk1+2*yk2+2*yk3+yk4);
}

double rk4_integrate(double zguess) {
    // Boundary Conditions
    double x_left = 0;
    double y_left = 0;
    double x_right = 1;
    double y_right = 1;

    double y = y_left; // this must remain true, u(0) = 0
    double z = zguess;

    double dx=0.01; // Step size

    for(double x=x_left;x<=x_right;x+=dx) {
        rk4_step(&y, &z, dx);
    }
    return y-y_right;
}

double secant(double x0, double x1, double (*f)(double), double tol) {
    int count=0;
    double x_old;
    while(abs(f(x0)) > tol) {
        x_old = x0;
        x0 -= f(x0)*(x0-x1)/(f(x0)-f(x1));
        x1 = x_old;
        count++;
    }
    cout << "Converged after " << count << " iterations." << endl;
    return x0;
}

int main() {
    // Boundary Conditions
    double x_left = 0;
    double y_left = 0;
    double x_right = 1;
    double y_right = 1;

    ofstream outfile;
    outfile.open("shooting.txt");

    // initial guesses
    double y = y_left; // this must remain true, u(0) = 0
    double z = secant(0, 3, rk4_integrate, 1e-6);

    double dx=0.01; // Step size
    for(double x=x_left;x<=x_right;x+=dx) {
        rk4_step(&y, &z, dx);
        outfile << x << " " << analytic(x) << " " << y << endl;
    }
    outfile.close();
    return 0;
}
