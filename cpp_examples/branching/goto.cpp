#include <iostream>

using namespace std;

int main() {
    int i;
MK1: goto MK2;
    for(i=0;i<10;i++)
    {
        // Show how break ends the loop
        if(i > 3)
            goto MK1;
        cout << i << endl;
        MK2: break;
    }
}
