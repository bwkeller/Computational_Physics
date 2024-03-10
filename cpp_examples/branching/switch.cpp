#include <iostream>

using namespace std;

int main() {
    int choice;
    cin >> choice;
    // If choice can be one of many options, we could have a long branching series of if..else
    // OR we could use switch
    switch(choice) {
        case 1:
            cout << "You input one" << endl;
            break;
        case 2:
            cout << "You input two" << endl;
            break;
        case 3:
            cout << "You input three" << endl;
            break;
        default:
            cout << "You input ~a different number~" << endl;
            break;
    }
}
