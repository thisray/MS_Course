#include <iostream>
#include "Polynomial.h"		// please change to your student id
// student id: A052582
using namespace std;

int main()
{
	int number;
	int v1, v2;

	cin >> number;
	for(int i = 0; i < number; i++)
	{
		Polynomial a, b, t1, t2, t3;
		cin >> a >> b >> v1 >> v2;
		t1 = a + b;
		t2 = a - b;
		t3 = ~a;
		cout << t1.get_value(v1) << endl;
		cout << t2.get_value(v2) << endl;
		cout << t3.get_value(v1) << endl;
		
	}
	return 0;
}
