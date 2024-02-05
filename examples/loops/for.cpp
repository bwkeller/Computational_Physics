#include <iostream>

using namespace std;

int main() {
    int i;
    // for(INITIATE; STOP CONDITION; UPDATE)
    for (i=0; i<10; i++) 
        cout << "Better to let a machine do repetitive work" << endl;
    

    // Show why we need curly braces
    for (i=0; i<10; i++) 
        cout << "Better to let a machine do repetitive work" << endl;
        cout << i << endl;

    // We can instantiate new variables in the for()
    // But it only exists in the loop!
    for(int j=0;j<10; j++) {
        cout << j << endl;
    }
    // cout << j << endl;
    
    // ALL variables in the braces are in that scope
    for(int j=0;j<10; j++) {
        int var;
        cout << j << endl;
    }
    // cout << var << endl;

    // Relational operators
    // ==
    // <
    // >
    // >=
    // <=
    // !=
    for(int j=0;j==0; j++) 
        cout << j << endl;

    // Unary increment
    int x = 5;
    int y = x++;
    cout << "y: " << y << " x: " << x << endl;

    // ANY expression works!
    for(int j=0; j<100; j=j*j+1) 
        cout << j << endl;


    // Combine assignment and arithmetic
    // +=
    // -= 
    // *=
    // /=
    // %=
    for(int j=0; j<100; j+=j+1) 
        cout << j << endl;

    // Comma lets you put multiple expressions in there
    for(int j=0,k=0; j<100; j++, k--)
        cout << j << " " << k << endl;
    return 0;

} 
