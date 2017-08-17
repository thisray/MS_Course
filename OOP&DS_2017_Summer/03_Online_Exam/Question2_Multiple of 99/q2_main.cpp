
/*

2.(15%)
Given a series of big numbers, and for each big number x is in the range: 0 <= x <= 10^20000.
Please print "Computer" if x is multiples of 9,
print "Science" if x is mulltiples of 11,
print "ComputerScience" if x is multiples of 99,
and print "Bug" if otherwise.

Please use standard input and standard output to finish this question.

example:

    input: 594
            87
            88
            9

    output: ComputerScience
                        Bug
                    Science
                   Computer

*/


#include <iostream>
#include <string>

#include "q2.h"
using namespace std;


// note: 'standard input' & 'standard output' means 'cin' & 'cout' 

int main(){

    // // for test
    // string input = "111111";
    // BigNumber bn(input);
    // cout << bn << endl;
    // cout << bn.result() << endl;

    while(1){
        string input;
        cout << "key-in some number: " << endl;
        cin >> input;

        if(input == "x"){ break; }

        BigNumber bn(input);
        // cout << "output: " << input << endl;
        cout << "result: " << bn.result() << "\n" << endl;
    }

}


/*

key-in some number:
594
result: ComputerScience

key-in some number:
87
result: Bug

key-in some number:
88
result: Science

key-in some number:
9
result: Computer

key-in some number:
x


*/













