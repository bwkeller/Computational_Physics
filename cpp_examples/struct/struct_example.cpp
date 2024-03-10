#include <iostream>
#include <string>

using namespace std;

struct student {
    string name;
    int age;
    float grade;
};

int main() {
    // show initialization
    //student ben = {
    //"Ben K",
    //35,
    //95,
    //};
    student ben;
    ben.name = "Ben K";
    ben.age = 35;
    ben.grade = 95;
    cout << ben.name << " is " << ben.age << " years old" << endl;
    return 0;
}
