#include <iostream>
#include "vector.hpp"
#include "length.hpp"

using namespace std;

int main() {
    vector vec;
    vec.x = 1.0;
    vec.y = 1.0;
    vec.z = 1.0;
    cout << length(vec) << endl;
    return 0;
}
