#include <iostream>
#include <cmath>

using namespace std;

class particle{
public:
    float vel[3];
    float mass;
    float* momentum();
    void inelastic_collide(particle *secondary);
    particle(float vx, float vy, float vz, float massin);
    ~particle();
private:
    int num_collisions;
};

particle::particle(float vx, float vy, float vz, float massin) {
    mass = massin;
    vel[0] = vx;
    vel[1] = vy;
    vel[2] = vz;
    num_collisions = 0;
}


float* particle::momentum() {
    float *p = new float[3];
    for(int i=0;i<3;i++) {
        p[i] = vel[i]*mass;
    }
    return p;
}

void particle::inelastic_collide(particle *secondary) {
    float *p_tot = new float[3];
    float *p_primary = this->momentum();
    float *p_secondary = secondary->momentum();
    for(int i=0;i<3;i++) {
        p_tot[i] = p_primary[i] + p_secondary[i];
    }
    mass += secondary->mass;
    for(int i=0;i<3;i++) {
        vel[i] = p_tot[i]/mass;
    }
    delete secondary;
    num_collisions++;
}

particle::~particle() {
    cout << "bye bye particle" << endl;
}

int main() {
    particle *a = new particle(1,1,4,1);
    particle *b = new particle(-1,1,1,2);
    cout << "Old velocity: (" << a->vel[0] << ", " << a->vel[1] << ", " << a->vel[2] << ")" << endl; 
    a->inelastic_collide(b);
    cout << "New velocity: (" << a->vel[0] << ", " << a->vel[1] << ", " << a->vel[2] << ")" << endl; 
    //cout << a->num_collisions;
    return 0;
}
