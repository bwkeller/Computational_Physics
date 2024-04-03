#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <time.h> 

using namespace std;

// Our function is f = x_1*x_2*x_3...x_n
double func(double *x, int D) {
    double result=1;
    for(int i=0; i<D;i++) {
        result *= x[i]*x[i];
    }
    return result;
}

// To give us a simpler result that's easy
// to get the analytic value of, integrate from 0 to b
double ifunc(double b, int D) {
    return pow(b*b*b/3, D);
}

double rectangle(double b, int D, double (*f)(double*, int), int N) {
    double result=0;
    double xi[D] = {0};
    double h = b/N;
    // Let's use the midpoint rule instead of the left-rule, it's a bit more
    // accurate
    for(int j=0; j<D; j++) {
        xi[j] += h/2;
    }
    for(int i=0; i<pow(N, D); i++)
    {
        result += f(xi, D)*pow(h, D); // We need to multiply by h^D, not just h here
        for(int j=0; j<D; j++) {
            if(xi[j]+h < b) {
                xi[j] += h;
                break;
            }
            xi[j] = 0;
        }
    }

    return result;
}

double mc_int(double b, int D, double (*f)(double*, int), int N) {
    double vol=1;
    double result=0;
    double randx[D];
    for(int i=0; i<N;i++) {
        for(int j=0; j<D; j++) {
            randx[j] = b*((float) rand())/RAND_MAX;  
        }
        result += func(randx, D);
    }
    // Calculate the volume element for our N-dimensional cube
    vol = pow(b, D);
    return vol*result/N;
}

int main()
{
    srand(time(NULL));
    int N = 16; // Number of steps 
    int D = 2; // Dimensionality of the problem
    double lim = 2; // Upper limit of integration
    cout << "Estimating with Monte Carlo..." << endl;
    double MC_result = mc_int(lim, D, func, N);
    cout << "Done!" << endl << "Estimating with Quadrature..." << endl << endl;
    double quad_result = rectangle(lim, D, func, N);
    cout << "True: " << ifunc(lim, D) << " MC Estimate:         " <<  MC_result << endl;
    cout << "True: " << ifunc(lim, D) << " Quadrature Estimate: " <<  quad_result << endl;
    cout << "MC Error:         " << fabs(ifunc(lim, D)-MC_result) << endl;
    cout << "Quadrature Error: " << fabs(ifunc(lim, D)-quad_result) << endl;
    return 0;
}
