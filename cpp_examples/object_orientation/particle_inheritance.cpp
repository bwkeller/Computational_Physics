#include <iostream>

using namespace std;

// What if we have two different kinds of particles, like
// stars and planets, with different properties?
// Do we add everything?

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

// How about a better way: inheritance

class star: public particle {
public:
    // Quantities for a star
    float luminosity;
    star(float vx, float vy, float vz, float massin, float lin);
};

class planet: public particle {
public:
    // Quantities for a planet
    bool rocky;
    planet(float vx, float vy, float vz, float massin, bool rin);
};

star::star(float vx, float vy, float vz, float massin, float lin):particle(vx,vy,vz,massin) {
}

planet::planet(float vx, float vy, float vz, float massin, bool rin):particle(vx,vy,vz,massin) {
}

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
    star *a = new star(1,1,4,1,4e26);
    planet *b = new planet(-1,1,1,2,1);
    cout << "Old velocity: (" << a->vel[0] << ", " << a->vel[1] << ", " << a->vel[2] << ")" << endl; 
    a->inelastic_collide(b);
    cout << "New velocity: (" << a->vel[0] << ", " << a->vel[1] << ", " << a->vel[2] << ")" << endl; 
    return 0;
}
