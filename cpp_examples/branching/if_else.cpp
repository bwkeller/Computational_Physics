#include <iostream>

using namespace std;

int main() {
    string course;
    cout << "What course is this?" << endl;
    cin >> course;
    if(course == "PHYS4420")
        cout << "That is correct." << endl;
    else if(course == "PHYS6420") // add this third.
        cout << "That is correct Kenny." << endl;
    else // add this later (else not mandatory)
        cout << "Incorrect." << endl; 


    // Show caveat: why we need else if
    // Determine if a number is between -5 and -9
    int i;
    cin >> i;
    if(i < -9)
        cout << "The number is below -9" << endl;
    else if(i < -5)
        cout << "The number is between -9 and -5" << endl;
    else
        cout << "The number is above -5" << endl;

    // exercise: write some code that reads an integer in from the user and prints out
    // whether or not it is odd or even.
}
