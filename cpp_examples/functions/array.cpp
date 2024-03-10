#include <iostream>

using namespace std;


// Ask: what does this mean if we change the values?
// Protect with const
int sum(int nums[], int N) {
    int sum=0;
    for(int i=0;i<N;i++) {
        sum += nums[i];
        nums[i] = 0;
    }
    return sum;
}

int main() {
    int example[5] = {0,1,2,3,4};
    for(int i=0;i<5;i++) {
        cout << example[i] << endl;
    }
    cout << "sum is: " << sum(example, 5) << endl;
    for(int i=0;i<5;i++) {
        cout << example[i] << endl;
    }
}
