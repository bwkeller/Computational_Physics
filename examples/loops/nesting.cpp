#include <iostream>

using namespace std;

int main() {
    int identity[3][3] = {0};
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(j == i) {
                identity[i][j] = 1;
            }
        }
    }

    for(int i=0; i<3; i++) {
        cout << identity[i][0] << identity[i][1] << identity[i][2] << endl;
    }
}
