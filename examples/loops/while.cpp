#include <iostream>

using namespace std;

int main() {
    int i=0;
    while(i < 10) {
        cout << i << endl;
        i++;
    }

    // Do-while: test _after_ loop body!

    i=0; // Show with i=11
    do {
        cout << i << endl;
        i++;
    }
    while (i < 10);
}
