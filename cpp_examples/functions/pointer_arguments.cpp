#include <iostream>

using namespace std;

// Show scope: cannot access y
// Show that x is a different variable inside function
int square(int x) {
    cout << &x << endl;
    x = x*x;
    return x;
}

// This is called "pass-by-reference"
void square_ptr(int *x) {
    *x = (*x) * (*x);
}

void square_cube(int *x, int *y) {
    *x = (*x) * (*x);
    *y = (*y) * (*y) * (*y);
}

int main() {
    int x = 3;
    cout << &x << endl;
    cout << square(x) << endl;
    cout << x << endl;
    square_ptr(&x);

    int y=4;
    cout << x  << " " << y << endl;
    square_cube(&x, &y);
    cout << x  << " " << y << endl;

    return 0;
}
