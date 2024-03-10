#include <iostream>

using namespace std;

struct star {
    float mass;
    float x,y,z;
    float vx,vy,vz;
};

struct star_arrays {
    float mass;
    float pos[3];
    float vel[3];
};

int main() {
    star cluster[100];

    cluster[0].x = 10;

    cout << "one star takes up " << sizeof(star) << " bytes" << endl;
    cout << "our cluster takes up " << sizeof(cluster) << " bytes" << endl;

    // array version
    star_arrays cluster_arrays[100];

    cluster_arrays[0].pos[0] = 10;

    cout << "one star takes up " << sizeof(star_arrays) << " bytes" << endl;
    cout << "our cluster takes up " << sizeof(cluster_arrays) << " bytes" << endl;
    return 0;
}
