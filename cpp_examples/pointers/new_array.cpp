#include <iostream>

using namespace std;

int main() {

    float * var = new float[3];
    var[0] = 2;
    var[1] = 4;
    var[2] = 8;
    cout << "var array: " << var[0] << " " << var[1] << " " << var[2] << endl;
    delete [] var;
    cout << "var array: " << var[0] << " " << var[1] << " " << var[2] << endl;
    return 0;
}


