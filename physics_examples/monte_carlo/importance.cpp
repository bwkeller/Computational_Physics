#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <time.h> 

using namespace std;

double prob(double x, double a, double b) {
    double norm = pow(b,20)/20 - pow(a,20)/20; 
    if (x < a || x > b) 
        return 0; 
    return pow(x,19)/norm;
}

double func(double x) {
    return pow(x,20);
}

double ifunc(double a, double b) {
    return pow(b, 21)/21 - pow(a, 21)/21;
}

double metropolis_step(double x, double a, double b, double (*f)(double), double step_size) {
    double x_trial = x + step_size*((2*(float) rand())/RAND_MAX-1);
    double p = prob(x_trial,a,b)/(prob(x,a,b));
    if(p > (float)rand()/RAND_MAX) {
        return x_trial;
    }
    else {
        return x;
    }
}

double metropolis_iterate(double x, double a, double b, double (*f)(double), double step_size, int N_steps) { 
    double sum=0;
    int n_accept=0; 
    double x_new;
    for(int i=0;i<N_steps;i++) {
        x_new = metropolis_step(x, a, b, f, step_size);
        if (x != x_new) {
            n_accept++;
        }
        x = x_new;
        sum += f(x)/prob(x,a,b);
    }
    return sum/N_steps;
}

double mc_int(double a, double b, double (*f)(double), int N) {
    double result=0;
    double randx;
    for(int i=0; i<N;i++) {
        randx = (b-a)*((float) rand())/RAND_MAX + a;  // We need random numbers between a and b
        result += f(randx);
    }
    return (b-a)*result/N;
}

int main()
{
    int N = 1e5;
    double a = 0;
    double b = 10;
    double step_size = 0.5;
    srand(time(NULL));
    cout << "Naive Monte-Carlo Estimated Integral:  " << mc_int(a, b, func, N) << endl;
    cout << "Error: " << 100*fabs(mc_int(a, b, func, N)-ifunc(a,b))/ifunc(a,b) << "%" << endl;
    cout << "Importance Sampled Estimated Integral: " << metropolis_iterate(1, a, b, func, step_size, N) << endl;
    cout << "Error: " << 100*fabs(metropolis_iterate(1, a, b, func, step_size, N)-ifunc(a,b))/ifunc(a,b) << "%" << endl;
    return 0;
}
