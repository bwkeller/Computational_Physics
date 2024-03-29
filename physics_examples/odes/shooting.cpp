#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct bvp
{
    double dx;
    double x_left;
    double y_left;
    double x_right;
    double y_right;
};

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

double rk4_integrate(double zguess, bvp bounds) {

    double y = bounds.y_left; // this must remain true, u(0) = 0
    double z = zguess;


    for(double x=bounds.x_left;x<=bounds.x_right;x+=bounds.dx) {
        rk4_step(&y, &z, bounds.dx);
    }
    return y-bounds.y_right;
}

double secant(double x0, double x1, double (*f)(double, bvp), bvp bounds, double tol) {
    int count=0;
    double x_old;
    while(abs(f(x0, bounds)) > tol) {
        x_old = x0;
        x0 -= f(x0, bounds)*(x0-x1)/(f(x0, bounds)-f(x1, bounds));
        x1 = x_old;
        count++;
    }
    cout << "Converged after " << count << " iterations." << endl;
    return x0;
}

int main() {
    bvp bounds;
    // Boundary Conditions
    bounds.x_left = 0;
    bounds.y_left = 0;
    bounds.x_right = 1;
    bounds.y_right = 1;
    bounds.dx=0.01; // Step size

    ofstream outfile;
    outfile.open("shooting.txt");

    // initial guesses
    double y = bounds.y_left; // this must remain true, u(0) = 0
    double z = secant(0, 3, rk4_integrate, bounds, 1e-6);

    cout << "z(0) = " << z << endl;

    for(double x=bounds.x_left;x<=bounds.x_right;x+=bounds.dx) {
        rk4_step(&y, &z, bounds.dx);
        outfile << x << " " << analytic(x) << " " << y << endl;
    }
    outfile.close();
    return 0;
}
