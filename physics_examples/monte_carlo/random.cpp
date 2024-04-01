#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h> // Don't include this until we need it.

using namespace std;

int main()
{
    int num = rand();
    cout << num << endl; // not very random is it?
    // At least the next numbers seem unconnected to the previous ones.
    cout << num << " " << rand() << " " << rand() << endl;
    srand(420); // seed the RNG
    cout << num << " " << rand() << " " << rand() << endl;

    srand(time(NULL)); // seed the RNG using the current time
    cout << num << " " << rand() << " " << rand() << endl;

    // How big can the random number be?
    cout << "Maximum random int: " << RAND_MAX << endl;

    // How do we get a random float?
    cout << ((float) num)/RAND_MAX << " " << ((float) rand())/RAND_MAX << " " << ((float) rand())/RAND_MAX << endl;

    // How do we get a random float between A and B
    float min = 3;
    float max = 4;
    cout << (max-min)*((float) num)/RAND_MAX + min << " " << (max-min)*((float) rand())/RAND_MAX + min << " " << (max-min)*((float) rand())/RAND_MAX + min << endl;
    return 0;
}
