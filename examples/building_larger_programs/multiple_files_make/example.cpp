#include <iostream>
#include "header.hpp"

using namespace std;

int main() {
    struct vector vec;
    vec.x = 1.0;
    vec.y = 1.0;
    vec.z = 1.0;
    cout << length(vec) << endl;
    return 0;
}
