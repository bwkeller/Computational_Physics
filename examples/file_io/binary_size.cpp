#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    int num = 10000;
    float numbers[num];
    for(int i=0;i<num;i++) {
        numbers[i] = sqrt(i);
    }
    ofstream outfile;
    outfile.open("numbers.dat", ofstream::binary | ofstream::out);
    outfile.write((char *)&num, sizeof(int));
    outfile.write((char *)&numbers, num*sizeof(float));
    outfile.close();

    ofstream textfile;
    textfile.open("numbers.txt", ofstream::out);
    for(int i=0;i<num;i++) {
        textfile << numbers[i] << endl;
    }
    textfile.close();

    return 0;
}
