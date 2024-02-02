#include <iostream>

using namespace std;

int main() {
    int a[3];

    a[0] = 420;
    a[1] = 69;
    a[2] = 1337;

    cout << "address of a[0] " <<  (long) &a[0] << " value of a[0] " << a[0] << endl;
    cout << "address of a[1] " <<  (long) &a[1] << " value of a[1] " << a[1] << endl;
    cout << "address of a[2] " <<  (long) &a[2] << " value of a[2] " << a[2] << endl << endl;

    cout << "address of a " <<  (long) &a << " value of *a " << *a << endl;
    cout << "(address of a)+1 " <<  (long) &a+1 << " value of *(a+1) " << *(a+1) << endl;


    return 0;
}


