#include <iostream>
#include <fstream>

using namespace std;

struct particle {
    float x;
    float y;
    float z;
    float mass;
};


particle* read_binary(int *npart) {
    ifstream infile;
    infile.open("myparticles.dat", ofstream::binary | ofstream::in);
    infile.read((char *)npart, sizeof(int));
    particle* particles = new particle[*npart];
    cout << particles << endl;
    cout << "number of particles: " << *npart << endl;
    infile.read((char *)particles, (*npart)*sizeof(particle));
    infile.close();
    return particles;
}

particle* read_text(int *npart) {
    ifstream infile;
    infile.open("myparticles.txt", ofstream::in);
    infile >> *npart;
    particle* particles = new particle[*npart];
    cout << particles << endl;
    cout << "number of particles: " << *npart << endl;
    for(int i=0;i<*npart;i++) {
        infile >> particles[i].x;
        infile >> particles[i].y;
        infile >> particles[i].z;
        infile >> particles[i].mass;
    }
    infile.close();
    return particles;
}

void compare_particles(particle a, particle b) {
    cout.setf(ios_base::scientific);
    cout << "Difference in x: "     << a.x-b.x          << endl;
    cout << "Difference in y: "     << a.y-b.y          << endl;
    cout << "Difference in z: "     << a.z-b.z          << endl;
    cout << "Difference in mass: "  << a.mass-b.mass    << endl;
}

int main() {
    int binary_npart, text_npart;
    particle *binary_parts;
    particle *text_parts;
    binary_parts = read_binary(&binary_npart);
    text_parts = read_text(&text_npart);
    cout << text_parts << endl;
    cout << binary_parts << endl;
    cout << "Difference in particle number: " << binary_npart-text_npart << endl;
    for(int i=0;i<binary_npart;i++) {
        compare_particles(binary_parts[i], text_parts[i]);
    }
    return 0;
}
