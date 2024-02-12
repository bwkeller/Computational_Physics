#include <iostream>

using namespace std;

// Show that we cannot return when void
int testfunc() {
    return 5;
}

// One argument (can be variable)
int square(int x) {
    return x*x;
}

// Two arguments
int multiply(int x, int y) {
    return x*y;
}

// Show that you can skip the name for prototype
int cube(int);

int main() {
    float a = 3.0;
    cout << multiply(2,a) << endl;
    return 0;
}

int cube(int x) {
    return x*x*x;
}
