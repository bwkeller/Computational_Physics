#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void accel(double r[2], double a[2]) {
    double invr2 = 1/(r[0]*r[0]+r[1]*r[1]);
    a[0] = -invr2 * r[0]/sqrt(invr2);
    a[1] = -invr2 * r[1]/sqrt(invr2);
}

void euler_step(double r[2], double v[2], double dt) {
    double a[2];
    // Get acceleration
    accel(r, a);
    // Update Positions
    r[0] += v[0]*dt;
    r[1] += v[1]*dt;
    // Update Velocities
    v[0] += a[0]*dt;
    v[1] += a[1]*dt;

}

void rk4_step(double r[2], double v[2], double dt) {
    double rk1[2], rk2[2], rk3[2], rk4[2];
    double vk1[2], vk2[2], vk3[2], vk4[2];
    double rtmp[2];
    rk1[0] = v[0];
    rk1[1] = v[1];
    accel(r, vk1);

    rk2[0] = v[0] + dt*vk1[0]/2;
    rk2[1] = v[1] + dt*vk1[1]/2;
    rtmp[0] = r[0]+dt*rk1[0]/2;
    rtmp[1] = r[1]+dt*rk1[1]/2;
    accel(rtmp, vk2);

    rk3[0] = v[0] + dt*vk2[0]/2;
    rk3[1] = v[1] + dt*vk2[1]/2;
    rtmp[0] = r[0]+dt*rk2[0]/2;
    rtmp[1] = r[1]+dt*rk2[1]/2;
    accel(rtmp, vk3);

    rk4[0] = v[0] + dt*vk3[0]/2;
    rk4[1] = v[1] + dt*vk3[1]/2;
    rtmp[0] = r[0]+dt*rk3[0];
    rtmp[1] = r[1]+dt*rk3[1];
    accel(rtmp, vk4);

    r[0] += (dt/6)*(rk1[0] + 2*rk2[0] + 2*rk3[0] + rk4[0]);
    r[1] += (dt/6)*(rk1[1] + 2*rk2[1] + 2*rk3[1] + rk4[1]);
    v[0] += (dt/6)*(vk1[0] + 2*vk2[0] + 2*vk3[0] + vk4[0]);
    v[1] += (dt/6)*(vk1[1] + 2*vk2[1] + 2*vk3[1] + vk4[1]);
}


int main() {
    ofstream outfile;
    outfile.open("orbits.txt");
    double dt=0.01;
    double r[2] = {0,1};
    double v[2] = {1,0};
    int n_years = 10000;
    for(int i=0; i<n_years/dt; i++) {
        if(i % 10 == 0) { 
            outfile << r[0] << " " << r[1] << endl;
        }
        //euler_step(r,v, dt);
        rk4_step(r,v, dt);
    }
    return 0;
}
