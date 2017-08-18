#include <iostream>
#include "Fraction.h"
using namespace std;   

int main() 
{
	int times;
	cin >> times;
	
	for(int i=0; i<times; i++){
		Fraction f1, f2;
		cin >> f1 >> f2;

		cout << f1+f2 << endl;
		cout << f1*f2 << endl;
		cout << f1/f2 << endl;
	}
	return 0;
}
