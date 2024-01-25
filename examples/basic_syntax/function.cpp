#include <iostream>

int AddTwo(int initial) {
	return (initial+2);
}

int main() {    
	using namespace std;
	cout <<"How many carrots do you have?" << endl;
	int a,carrots;    
	cin >> a;    
	cout <<"Here are two more." << endl;    
	carrots=AddTwo(a);  
	cout <<"Now you have "  << carrots << " carrots." << endl;
	return 0;
}
