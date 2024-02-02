#include <iostream>

using namespace std;

int main() {
    int a;
    int *b;

    a = 1337;

    cout << "value of a " << (long) a << " address of a " <<  (long) &a << endl;
    cout << "value of b " << (long) b << " address of b " <<  (long) &b << endl << endl;

    b = &a;
    cout << "value of a " << (long) a << " address of a " <<  (long) &a << endl;
    cout << "value of b " << (long) b << " address of b " <<  (long) &b << endl << endl;

    cout << "value of a " << (long) a << " value referenced by b " <<  (long) *b << endl;


    return 0;
}


