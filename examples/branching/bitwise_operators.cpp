#include <iostream>

using namespace std;

int main() {

    // Show and vs. or vs. xor
    // and -> &
    // or -> |
    // xor -> ^
    int a = 3;
    int b = 1;
    int c = a ^ b;
    cout << c << endl;

    // Show bitwise shifts
    a = 1;
    b = a >> 3;
    cout << b << endl;
}
