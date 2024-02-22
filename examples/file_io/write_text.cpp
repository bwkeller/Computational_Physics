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
    outfile.open("myparticles.txt", ofstream::out);
    outfile << npart << endl;
    for(int i=0;i<npart;i++) {
        outfile << myparts[i].x << " " << myparts[i].y << " " << myparts[i].z << " " << myparts[i].mass << endl;
    }
    outfile.close();


    return 0;
}
