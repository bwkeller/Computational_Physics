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
    int npart = 10000;
    struct particle myparts[npart];
    for(int i=0;i<npart;i++) {
        myparts[i].x = i;
        myparts[i].y = i;
        myparts[i].z = i;
        myparts[i].mass = 2;
    }
    ofstream outfile;
    outfile.open("myparticles.dat", ofstream::binary | ofstream::out);
    outfile.write((char *)&npart, sizeof(int));
    outfile.write((char *)myparts, npart*sizeof(struct particle));
    outfile.close();


    return 0;
}
