#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h> 

using namespace std;

int main()
{
    srand(time(NULL));
    float x,y;
    int in_circle = 0;
    int N = (int) 1e5;
    for(int i=0; i<N; i++) {
        x = (float) rand()/RAND_MAX; // uniform random number between 0 and 1
        y = (float) rand()/RAND_MAX; // uniform random number between 0 and 1
        if(sqrt(x*x + y*y) < 1) {in_circle++;}
    }
    cout << "Fraction of points inside circle quadrant: " << ((float) in_circle)/N << endl;
    cout << "Estimate of Pi: " << 4*((float) in_circle)/N << endl;
    return 0;
}
