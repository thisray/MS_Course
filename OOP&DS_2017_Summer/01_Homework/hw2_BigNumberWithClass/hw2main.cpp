#include <iostream>                                                                                                                                                                                                                                                                                   
#include "bignum.h"   

using namespace std;                                                                                                                                                                    
                                                                                                                                                                                        
int main(int argc, char **argv)                                                                                                                                                                              
{                                                                                                                                                                                       
	
	char op;
	int times;
	cin>>times;
	
	for(int i = 0; i < times; i++)
	{
		BigNum a, b; 
		cin>>a>>b;
		BigNum c(b);

        // // // for test
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;

		cout<<a+c<<endl;
		cout<<a-c<<endl;
		cout<<a*c<<endl;
		cout<<a/c<<endl;
		cout<<a*c/b<<endl;
	}
	                                                                                                                           
}
