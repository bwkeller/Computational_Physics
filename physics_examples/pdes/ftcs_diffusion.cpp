#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <time.h> 

using namespace std;


void init_grid(double *grid, int N) {
    for(int i=0;i<N;i++) {
        if(i > N/4 && i < 3*N/4)
            grid[i] = 1;
        else
            grid[i] = 0;
    }
}

void ftcs(double *grid, int N, double k, double eta, double tf) {
    double dx = 1.0/N;
    double dt = eta/2 * dx * dx / k;
    for(double t=0;t<tf;t+=dt) {
        for(int i=0;i<N;i++) {
            // Left Periodic Boundary Condition
            if (i==0) {
                grid[i] += (dt*k/(dx*dx))*(grid[i+1] - 2*grid[i] + grid[N-1]);
            }
            // Right Periodic Boundary Condition
            else if (i==(N-1)) {
                grid[i] += (dt*k/(dx*dx))*(grid[0] - 2*grid[i] + grid[i-1]);
            }
            else {
                grid[i] += (dt*k/(dx*dx))*(grid[i+1] - 2*grid[i] + grid[i-1]);
            }
        }
    }
}

int main()
{
    int N=256;
    double grid[N];
    double IC[N];
    init_grid(grid, N);
    init_grid(IC, N);
    ftcs(grid, N, 0.01, 0.1, 1);
    ofstream outfile;
    outfile.open("ftcs_diffusion.txt");
    for(int i=0;i<N;i++) {
        outfile << (float) i / N << " " << grid[i] << " " << IC[i] << endl;
    }
    outfile.close();
    return 0;
}
