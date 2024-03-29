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

double bisect(double xl, double xr, double (*f)(double, bvp), bvp bounds, double tol) {
    double xm = 0.5*(xl+xr);
    double fl = f(xl, bounds);
    double fm = f(xm, bounds);
    double fr = f(xr, bounds);
    int count = 0;
    while(abs(fm) > tol) {
        fm = f(xm, bounds);
        if(fm > 0) {
            xr = xm;
            fr = fm;
        }
        else {
            xl = xm;
            fl = fm;
        }
        xm = 0.5*(xl+xr);
        count++;
    }
    cout << "Converged after " << count << " iterations." << endl;
    return xm;
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
    double z = bisect(0, 10, rk4_integrate, bounds, 1e-6);

    cout << "z(0) = " << z << endl;

    for(double x=bounds.x_left;x<=bounds.x_right;x+=bounds.dx) {
        outfile << x << " " << analytic(x) << " " << y << endl;
        rk4_step(&y, &z, bounds.dx);
    }
    outfile.close();
    return 0;
}
