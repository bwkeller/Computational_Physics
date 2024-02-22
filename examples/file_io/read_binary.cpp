#include <iostream>
#include <fstream>

using namespace std;

struct particle {
    float x;
    float y;
    float z;
    float mass;
};

int main() {
    int npart;
    struct particle myparts[npart];
    ifstream infile;
    infile.open("myparticles.dat", ofstream::binary | ofstream::in);
    infile.read((char *)&npart, sizeof(int));
    cout << "number of particles: " << npart << endl;
    infile.read((char *)myparts, npart*sizeof(struct particle));
    float total_mass=0;
    for(int i=0;i<npart;i++) {
        total_mass += myparts[i].mass;
    }
    cout << "total mass of all particles: " << total_mass << endl;
    infile.close();
    return 0;
}
