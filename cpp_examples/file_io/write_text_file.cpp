#include <iostream>
#include <cmath>
#include <fstream>

/*
 * This program is intended to show the basics of writing text to files.  I've
 * arranged the functions in the basic order to introduce them.
 */

using namespace std;


/*
 * This function is here to show the simplest case: just write 1,2,3,4 to
 * separate lines in a textfile called four_ints.txt.  After you have
 * run it, use "cat four_ints.txt" to see the content.
 */
void write_ints() {
    // ofstream is short for "output file stream"
    ofstream outfile; // This object is our "file stream object": it has methods for writing to disk
    // When we call open below, the program will open
    // the file with the name passed as the string argument (in this case "four_ints.txt")
    // If the file doesn't exist, this will create it.
    outfile.open("four_ints.txt"); 
    for (int i=1;i<=4;i++) {
        // Look at this magic!  The ofstream object
        // we created (outfile) can be treated just like cout!
        outfile << i << endl; 
    }
    // Running close() ensures that the file is "flushed" to disk:
    // that all of the writes are complete before write_ints()
    // finishes.  This is generally good practice.
    outfile.close();
}

/*
 * This function here is to show what happens by default when we write to
 * a file that already exists (we should have created it when we ran with
 * write_ints()).  Show that four_ints.txt has been overwritten
 */
void overwrite() {
    ofstream outfile; 
    outfile.open("four_ints.txt"); 
    for (int i=1;i<=4;i++) {
        outfile << 10*i << endl; 
    }
    outfile.close();
}

/*
 * This shows how we can append: tack output to the end
 * of an existing file.  Show that four_ints.txt now has 8 lines
 */
void append() {
    ofstream outfile; 
    // that second argument is the "options" for open().
    // It configures how we want streams to behave with this file.
    outfile.open("four_ints.txt", ofstream::app); 
    for (int i=1;i<=4;i++) {
        outfile << 100*i << endl; 
    }
    outfile.close();
}

/*
 * This function is just to show that the outfile can be just like
 * cout, and we can print any fancy thing we want to it
 */
void fancy_line() {
    ofstream outfile; 
    outfile.open("four_ints.txt"); 
    for (int i=1;i<=4;i++) {
        outfile << "The value of " << i << " squared is: " << i*i << endl; 
    }
    outfile.close();
}

/*
 * Run only one of the functions called here per compile, in
 * the order they are in.
 */
int main() {

    write_ints();
    //overwrite();
    //append();
    //fancy_line();
    
    return 0;
}
