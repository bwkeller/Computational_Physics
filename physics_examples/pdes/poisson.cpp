#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <time.h> 

using namespace std;

double func(double x) {
    return sin(x);
}

double solution(double x) {
    return -sin(x) + x*sin(1);
}

double norm(double *grid, int N) {
    double norm = 0;
    for(int i=0;i<N;i++) {
        norm += grid[i]*grid[i];
    }
    return sqrt(norm);
}

double residual(double *grid, int N) {
    double res = 0;
    double dx = 1.0/N;
    for(int i=0;i<N;i++) {
        double x = (float) i / N;
        if(i == 0)
            res += func(x) - (grid[i+1] - 2*grid[i])/(dx*dx);
        else if(i == N-1)
            res += func(x) - (-2*grid[i] + grid[i-1])/(dx*dx);
        else 
            res += func(x) - (grid[i+1] - 2*grid[i] + grid[i-1])/(dx*dx);
    }
    return sqrt(res);
}

void gauss_seidel(double *grid, int N, int M) {
//void gauss_seidel(double *grid, int N, double eps) {
    double dx = 1.0/N;
    for(int i=0;i<M;i++) {
    //while(residual(grid, N) > eps*norm(grid, N)) {
        for(int j=0;j<N;j++) {
            double x = (float) j / N;
            // First order Dirichlet BCs 
            if (j == 0) 
                grid[j] = 0.5*(grid[j+1] + 0 - dx*dx *func(x));
            else if (j == N-1) 
                grid[j] = 0.5*(0 + grid[j-1] - dx*dx *func(x));
            else
                grid[j] = 0.5*(grid[j+1] + grid[j-1] - dx*dx *func(x));
        }
    }
}

int main()
{
    int N = 256;
    double grid[N] = {0};
    ofstream outfile;
    outfile.open("poisson.txt");
    gauss_seidel(grid, N, 10000);
    //gauss_seidel(grid, N, 5);
    for(int i=0;i<N;i++) {
        outfile << (float) i / N << " " << grid[i] << " " << solution((float) i / N) << endl;
    }
    outfile.close();
    return 0;
}
