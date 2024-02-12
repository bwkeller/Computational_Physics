#include <iostream>

using namespace std;

int multiply(int x, int y) {
    return x*y;
}

int add(int x, int y) {
    return x+y;
}

// Show a function that takes a function!
int reduce(int arr[], int N, int (*fun)(int, int)) {
    int output = arr[0];
    for(int i=1;i<N;i++) {
        output = fun(output, arr[i]);
    }
    return output;
}

int main() {
    int (*math_doer)(int, int) = add;
    cout << math_doer(2,5) << endl;
    int x[5] = {1,2,3,4,5};
    cout << reduce(x, 5, multiply) << endl;
    return 0;
}
