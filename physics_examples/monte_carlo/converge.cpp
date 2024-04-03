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

void test_converge(int D, double lim) {
    cout << "D=" << D  << " case:"<< endl;
    for(int N=8; N<128; N *= 2) {
        double MC_result = mc_int(lim, D, func, pow(N, D));
        double quad_result = rectangle(lim, D, func, N);
        double analytic = ifunc(lim, D);
        cout << "N^D:\t" << pow(N, D) << "\tMC error: " << fabs(MC_result - analytic) << 
            "\tQuadrature error: " << fabs(quad_result - analytic) << endl;
    }
}

int main()
{
    srand(time(NULL));
    double lim = 2;
    for(int D=1; D<4; D++) {
        test_converge(D, lim);
    }
    return 0;
}
