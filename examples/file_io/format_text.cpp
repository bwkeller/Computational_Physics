#include <iostream>
#include <iomanip> // We need this for setw
#include <cmath>
#include <fstream>

/*
 * This program is intended to show off the different ways we can 
 * change how numbers are printed out (mostly floats).  Make sure
 * you mention everything we do here with files works with cout as
 * well (and vice versa).
 */

using namespace std;

/*
 * Just write a single floating point value to a file.
 * It should print ~5ish significant figures.  What if we want more?
 */
void write_pi() {
    ofstream outfile; 
    outfile.open("pi.txt"); 
    double pi = M_PI; // M_PI is the math library's macro for pi
    outfile << pi << endl;
    outfile.close();
}

/*
 * With precision(), we can choose how many digits we print.  
 * Try this with 2 digits, and then with 16 digits after the decimal.
 */
void write_pi_precision(int n) {
    ofstream outfile; 
    outfile.open("pi.txt"); 
    outfile.precision(n);
    double pi = M_PI; // M_PI is the math library's macro for pi
    outfile << pi << endl;
    outfile.close();
}

/*
 * With width we can control whitespace: handy for making nicely formatted
 * output.  The width is the number of characters each variable will "take up":
 * any extra space ends up being just whitespace.  This function also shows
 * that we can do the same thing we did with a file stream to cout.
 */
void table_without_width() {
    cout.precision(5);
    // This will look ugly!  The columns will not be aligned.
    // You could do the bonkers and labour-intensive thing of figuring out
    // by hand how much space is needed.  BUT THERE IS A BETTER WAY!
    cout << "Printing a table without setting the width:" << endl;
    cout << 1 << " " << M_PI << " " << 100 << endl;
    cout << 1 << " " << 2 << " " << 3 << endl;
    cout << 100 << " " << 200 << " " << 300 << endl;
}

void table_with_width() {
    cout.precision(5);
    // If we know none of our numbers will exceed 10 digits, we can set the width
    // of each stream element to be 10:  this will automatically add extra
    // space characters until we hit 10 characters.  
    cout << "Printing a table after setting the width and left aligning:" << endl;
    cout << left << setw(10) << 1 << setw(10) << M_PI << setw(10) << 100 << endl;
    cout << left << setw(10) << 1 << setw(10) << 2 << setw(10) << 3 << endl;
    cout << left << setw(10) << 100 << setw(10) << 200 << setw(10) << 300 << endl;
}

// By default, the standard library is smart enough to format big numbers with
// scientific notation (the e+43 here is 10^43).  We can force it to use fixed
// point as well
void big_number_print() {
    double bignum = exp(100);
    cout << bignum << endl;
    cout.setf(ios_base::fixed);
    cout << bignum << endl;
}

// We can also force numbers close to 1 that would be printed with fixed-point
// by default use scientific notation.
void small_number_print() {
    double smallnum = 0.001;
    cout << smallnum << endl;
    cout.setf(ios_base::scientific);
    cout << smallnum << endl;
}


int main() {
    write_pi();
    //write_pi_precision(2);
    //write_pi_precision(16);
    //table_without_width();
    //table_with_width();
    //big_number_print();
    //small_number_print();
    return 0;
}
