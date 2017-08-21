
#include <iostream>
#include "Q1_Fraction.h"
using namespace std;

int main(){
    int times;
    cin >> times;

    for(int i=0; i<times; i++){
        Fraction f1, f2;
        cin >> f1 >> f2;

        // // for test
        // cout << "f1: "<< f1 << endl;
        // cout << "f2: "<< f2 << endl;

        cout << f1+f2 << endl;
        cout << f1*f2 << endl;
        cout << f1/f2 << endl;
    }
    return 0;
}

