#include <iostream>
#include <cmath>

using namespace std;

struct particle{
    float vel[3];
    float mass;
};

float* momentum(particle a) {
    float *p = new float[3];
    for(int i=0;i<3;i++) {
        p[i] = a.vel[i]*a.mass;
    }
    return p;
}

void inelastic_collide(particle *primary, particle *secondary) {
    float *p_tot = new float[3];
    float *p_primary = momentum(*primary);
    float *p_secondary = momentum(*secondary);
    for(int i=0;i<3;i++) {
        p_tot[i] = p_primary[i] + p_secondary[i];
    }
    primary->mass += secondary->mass;
    for(int i=0;i<3;i++) {
        primary->vel[i] = p_tot[i]/primary->mass;
    }
}

int main() {
    particle a;
    particle b;
    a.mass = 1;
    b.mass = 2;
    a.vel[0] = 1;
    a.vel[1] = 1;
    a.vel[2] = 4;
    b.vel[0] = -1;
    b.vel[1] = 1;
    b.vel[2] = 2;
    cout << "Old velocity: (" << a.vel[0] << ", " << a.vel[1] << ", " << a.vel[2] << ")" << endl; 
    inelastic_collide(&a, &b);
    cout << "New velocity: (" << a.vel[0] << ", " << a.vel[1] << ", " << a.vel[2] << ")" << endl; 
    return 0;
}
