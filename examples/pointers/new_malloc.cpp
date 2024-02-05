#include <iostream>

using namespace std;

int main() {

    float * var = new float;
    *var = 3.14;
    cout << *var << " addr:" << (long) var << endl;

    // Delete to remove
    delete var;
    cout << *var << " addr:" << (long) var << endl;

    // Can't delete non-new (or malloc) variables
    
    float x;
    delete &x;

    return 0;
}


