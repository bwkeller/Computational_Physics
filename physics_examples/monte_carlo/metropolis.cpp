#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <time.h> 

using namespace std;

double truefunc(double x) {
    return 6.*exp(-4.*(x+4.)*(x+4.)) + 2.*exp(-0.2*(x+1.)*(x+1.)) + exp(-2.*(x-5.)*(x-5.));
}

double truenorm() {
    return sqrt(M_PI)*(6/sqrt(4) + 2/sqrt(0.2) + 1/sqrt(2));
}

double metropolis_step(double x, double (*f)(double), double step_size) {
    double x_trial = x + step_size*((2*(float) rand())/RAND_MAX-1);
    double p = f(x_trial)/f(x);
    //cout << p << " for " << x_trial << " " << x << endl;
    if(p >= (float)rand()/RAND_MAX) {
        return x_trial;
    }
    else {
        return x;
    }
}

void metropolis_iterate(double x, double (*f)(double), double step_size, int N_steps) { 
    int n_accept=0; 
    double x_new;
    ofstream outfile;
    outfile.open("metropolis.txt");
    for(int i=0;i<N_steps;i++) {
        x_new = metropolis_step(x, f, step_size);
        if (x != x_new) {
            n_accept++;
        }
        outfile << x << endl;
        x = x_new;
    }
    cout << "Accepted " << n_accept << " trials" << endl;
    outfile.close();
}

int main()
{
    srand(time(NULL));
    metropolis_iterate(0, truefunc, 1, 1e5);
    return 0;
}
