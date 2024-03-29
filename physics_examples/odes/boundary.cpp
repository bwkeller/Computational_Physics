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



int main(int argc, const char* argv[]) {
    if(argc != 2) {
        cout << "Please specify the intial guess for z" << endl;
    }
    double zguess = stod(argv[1]);
    // Boundary Conditions
    double x_left = 0;
    double y_left = 0;
    double x_right = 1;
    double y_right = 1;

    ofstream outfile;
    outfile.open("boundary.txt");

    // initial guesses
    double y = y_left; // this must remain true, u(0) = 0
    double z = zguess;

    double dx=0.01; // Step size
    for(double x=x_left;x<=x_right;x+=dx) {
        rk4_step(&y, &z, dx);
        outfile << x << " " << analytic(x) << " " << y << endl;
    }
    cout << "True y_right: " << y_right << " Integration guess y_right: " << y << endl;
    outfile.close();
    return 0;
}
