#include <iostream>

using namespace std;

int main() {
    int size=20;
    long fact[size];
    fact[0]=1;
    for(int i=1;i<=size;i++) {
        fact[i]=i*fact[i-1];
        cout<<fact[i]<<endl;
    }

    // Excercise: Calculate the Fibonnaci series to n=50
    return 0;
}
