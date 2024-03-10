#include <iostream>

using namespace std;

int factorial(unsigned int n) {
    if(n == 1) {
        return 1;
    }
    else {
        return n*factorial(n-1);
    }
}

int main() {
    unsigned int n = 5;
    cout << n << "!=" << factorial(n) << endl;
    return 0;
}
