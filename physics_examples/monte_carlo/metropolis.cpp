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

double metropolis_iterate(double x, double (*f)(double), double step_size, int N_steps) { 
    double sum=f(x);
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
        sum += f(x);
    }
    cout << "Accepted " << n_accept << " trials" << endl;
    outfile.close();
    return sum/N_steps;
}

int main()
{
    srand(time(NULL));
    cout << metropolis_iterate(0, truefunc, 3, 1e5) << endl;
    cout << truenorm() << endl;
    cout << truenorm()/metropolis_iterate(0, truefunc, 3, 1e5) << endl;
    return 0;
}
