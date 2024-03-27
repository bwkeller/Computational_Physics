#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

double analytic(double x0, double t) {
    return exp(-18*t);
}
int main() {
    ofstream outfile;
    outfile.open("stiff.txt");
    //timestep
    double dt=0.1;
    // initial conditions
    double x0 = 1; 
    // dynamical variables
    double x = x0;
    double x_euler = x0;
    for(double t=0;t<=1;t+=dt) {
        outfile << t << " " << x << " " << x_euler << " " << analytic(x0, t) << endl;
        /*
        double x_next = x;
        for(int k=0;k<10;k++) {
            x_next = x + (dt/2)*(-18*x + -18*x_next);
        }
        x = x_next;
        */
        double x_next = x;
        double x_next_old;
        int count=0;
        do {
            x_next_old = x_next;
            x_next = x + (dt/2)*(-18*x + -18*x_next);
            count++;
            cout << count << endl;
        } while (abs(x_next - x_next_old) > 1e-6*x_next_old);
        x = x_next;
        x_euler += dt*(-18*x_euler);
    }
    outfile.close();
    return 0;
}
