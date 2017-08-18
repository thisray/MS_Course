#ifndef Polinomil_h
#define Polinomil_h

/*
4.(20%)
Polynomial operation – please implement the following operator:
(a) Polynomial operator+() – Add 2 polynomials
(b) Polynomial operator-() – Subtract 2 polynomials
(c) Polynomial operator~() – Differential a polynomial
(d) istream & operator>>() – Read a polynomial from cin
(e) int get_value(int v) – compute the value of this polynomial with x-value v

Input – first line is number of testing data, and the following lines are consist of 2
polynomials and 2 integers
Each polynomials is ended with “!”
Each polynomial is represented as “coefficient degree coefficient degree...” and
separated by space, eg, 1x^2+2x^1+1x^0 is represented as 1 2 2 1 1 0 !
The range of coefficient is -2^31 ~ 2^31
The range of degree is 0~20000, and the degree is in descending order
The number of terms will be less than 100
TA will use this main.cpp to test your code, please make sure your code can run with
this main function.(Do not write any main function in your hand in code)
Input.txt 1
1 2 2 1 1 0 ! -1 2 1 1 ! 2 3
command ./a.out < input.txt
cout 7
22
6
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
int SIZE = 20001;

int pow(int input, int degree){
    int result = 1;
    for(int i=0; i<degree; i++){
        result = result * input;
    }
    return result;
}

class Polynomial{
    private:
        vector<int> polymember;
    public:
        Polynomial();
        Polynomial(const Polynomial &);

        friend Polynomial operator+(const Polynomial &, const Polynomial &);
        friend Polynomial operator-(const Polynomial &, const Polynomial &);
        friend Polynomial operator~(const Polynomial &);
        friend istream & operator>>(istream &, Polynomial &);   // here can't add 'const'
        int get_value(int);
};

Polynomial::Polynomial(){
    vector<int> _polymember(SIZE, 0);
    this->polymember = _polymember;
}

Polynomial::Polynomial(const Polynomial & poly){
    this->polymember = poly.polymember;
}

Polynomial operator+(const Polynomial & poly_1, const Polynomial & poly_2){
    Polynomial result;
    for(int i=0; i<SIZE; i++){
        result.polymember.at(i) = poly_1.polymember.at(i) + poly_2.polymember.at(i);
    }
    return result;
}

Polynomial operator-(const Polynomial & poly_1, const Polynomial & poly_2){
    Polynomial result;
    for(int i=0; i<SIZE; i++){
        result.polymember.at(i) = poly_1.polymember.at(i) - poly_2.polymember.at(i);
    }
    return result;
}

Polynomial operator~(const Polynomial & poly){
    Polynomial result;
    for(int i=0; i<SIZE; i++){
        int coef = poly.polymember.at(i);
        if(coef != 0 && i > 0){
            result.polymember.at(i-1) = coef * i;
        }
    }
    return result;
}


istream & operator>>(istream & is, Polynomial & poly){
    string input;
    stringstream ss;
    getline(is, input, '!');
    ss.str(input);

    size_t n = count(input.begin(), input.end(), ' ');  // need to learn this
    for(int i = 0; i < n/2; i++){
        int coef, deg;
        ss >> coef >> deg;
        poly.polymember.at(deg) = coef;
    }

    // // for check
    // for(int i=0; i<poly.polymember.size(); i++){
    //     int val = poly.polymember.at(i);
    //     if(val != 0){
    //         cout << "coef: " << val << ", deg: " << i << endl;
    //     }
    // }
    return is;
}

int Polynomial::get_value(int input){
    int result = 0;
    for(int i=0; i<SIZE; i++){
        int coef = this->polymember.at(i);
        if(coef != 0){
            result = result + coef * pow(input, i) ;
        }
    }
    return result;
}



#endif



/*

99800000
100200000
80000000
70
-90
0
-62
24622
40
0
26334
1959612
6006021
39360
24387237
135
35
10100
20198
-2020
-99009899
2
0
1

*/






