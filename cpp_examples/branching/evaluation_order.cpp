#include <iostream>

using namespace std;

bool printer() {
    cout << "printer has run" << endl;
    return false;
}

int main() {
    // swap the order of these
    if(printer() && false) {
        cout << "The expression above is true" << endl;
    }
}
