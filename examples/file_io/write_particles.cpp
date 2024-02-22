#include <iostream>
#include <cmath>
#include <fstream>

/*
 * This program is intended to show off the difference between writing outputs as text
 * and binary.  Text has the advantage of being human-readable, while binaries have the
 * advantage of being _identical_ to how the data is stored in memory, and are more disk
 * space efficient.
 */

using namespace std;

/*
 * Let's write out structs of particles with positions (x,y,z) and masses.  Could
 * be for a gravity solver, a molecular dynamics program, etc.  We'll use floats
 * for everything.
 */
typedef struct {
    float x;
    float y;
    float z;
    float mass;
} particle ;

/*
 * This function will write out all the particles as a text file.
 */
void write_text(particle parts[], int n) {
    ofstream outfile; 
    outfile.open("myparticles.txt", ofstream::out); 
    outfile << n << endl;
    for(int i=0;i<n;i++) {
        outfile << parts[i].x << " " << parts[i].y << " " << parts[i].z << " " << parts[i].mass << endl;
    }
    outfile.close();
}

/*
 * This function will write out all the particles as binary file.
 */
void write_binary(particle parts[], int n) {
    ofstream outfile;
    outfile.open("myparticles.dat", ofstream::binary | ofstream::out);
    outfile.write((char *)&n, sizeof(int));
    outfile.write((char *)parts , n*sizeof(particle));
    outfile.close();
}

int main() {
    int npart = 10000;
    particle myparts[npart];
    // We will place our particles on a diagonal
    // line going from 0 -> pi*npart for x,y,z.
    // We use pi here to take advantage of floats
    // and to show off one of the benefits of binary
    // outputs.
    for(int i=0;i<npart;i++) {
        myparts[i].x = i*M_PI;
        myparts[i].y = i*M_PI;
        myparts[i].z = i*M_PI;
        myparts[i].mass = M_PI;
    }

    write_binary(myparts, npart);

    write_text(myparts, npart);
    // After you've written these out, compare the size in bytes of
    // myparticles.txt and myparticles.dat with 
    //
    // du -b myparticles.dat
    // du -b myparticles.txt
    //
    // The text version should be ~3 times bigger

    return 0;
}
