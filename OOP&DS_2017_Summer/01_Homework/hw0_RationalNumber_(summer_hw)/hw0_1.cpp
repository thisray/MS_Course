#include <iostream>
using namespace std;

int getGCD(int a, int b){
    if(b == 0 || a == 0){ return 1; }
    int c;
    c = a % b;
    if(c==0){ return b; }
    else{ return getGCD(b, c); }
}

int main(){
    cout << getGCD(10, 5) << endl;
    cout << getGCD(3, 5) << endl;
    cout << getGCD(5, 3) << endl;
    return 0;
}

