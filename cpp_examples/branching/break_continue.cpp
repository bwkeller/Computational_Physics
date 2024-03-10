#include <iostream>

using namespace std;

int main() {
    for(int i=0;i<10;i++)
    {
        // Show how continue can "skip" an iteration
        if(i > 3 && i < 6)
            continue;
        cout << i << endl;
    }

    for(int i=0;i<10;i++)
    {
        // Show how break ends the loop
        if(i > 3)
            break;
        cout << i << endl;
    }
}
