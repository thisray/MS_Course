#ifndef Fraction_h
#define Fraction_h

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a==0 || b==0){ return 1; }
    int c = a % b;
    if(c == 0){ return b; }
    else{ return gcd(b, c); }
}

class Fraction{
    private:
        int numerator, denominator;
    public:
        Fraction();
        Fraction(const Fraction &);

        friend istream & operator>>(istream &, Fraction &);
        friend ostream & operator<<(ostream &, const Fraction &);

        friend Fraction operator+(const Fraction &, const Fraction &);
        friend Fraction operator*(const Fraction &, const Fraction &);
        friend Fraction operator/(const Fraction &, const Fraction &);
};

Fraction::Fraction(){
    this->numerator = 0;
    this->denominator = 0;
}

Fraction::Fraction(const Fraction & fraction){
    this->numerator = fraction.numerator;
    this->denominator = fraction.denominator;    
}

istream & operator>>(istream & is, Fraction & fraction){
    // char space;
    // is >> fraction.numerator >> space >> fraction.denominator >> space; // >> endl;
    int numerator, denominator;
    is >> numerator >> denominator; // >> endl;
    fraction.numerator = numerator / gcd(numerator, denominator);
    fraction.denominator = denominator / gcd(numerator, denominator);
    return is;
}

ostream & operator<<(ostream & os, const Fraction & fraction){
    int numerator = fraction.numerator / gcd(fraction.numerator, fraction.denominator);
    int denominator = fraction.denominator / gcd(fraction.numerator, fraction.denominator);
    // cout << "numerator: " << numerator << ", denominator: " << denominator << ", gcd(): " << gcd(fraction.numerator, fraction.denominator) << endl;

    if(numerator == 0){
        os << 0; // << endl;
    }
    else if(denominator == 1){
        os << numerator; // << endl;
    }
    else if(numerator > denominator){
        int _integer = numerator / denominator;
        int _numerator = numerator % denominator;
        os << _integer << "(" << _numerator << "/" << denominator << ")"; // << endl;
    }
    else{
        os << numerator << "/" << denominator; // << endl;
    }
    return os;
}

Fraction operator+(const Fraction & fraction_1, const Fraction & fraction_2){
    Fraction result;
    result.denominator = fraction_1.denominator * fraction_2.denominator;
    result.numerator = fraction_1.numerator * fraction_2.denominator + fraction_2.numerator * fraction_1.denominator;
    return result;
}

Fraction operator*(const Fraction & fraction_1, const Fraction & fraction_2){
    Fraction result;

    int numerator_1, numerator_2, denominator_1, denominator_2;
    numerator_1 = fraction_1.numerator / gcd(fraction_1.numerator, fraction_2.denominator);
    numerator_2 = fraction_2.numerator / gcd(fraction_2.numerator, fraction_1.denominator);
    denominator_2 = fraction_2.denominator / gcd(fraction_1.numerator, fraction_2.denominator);
    denominator_1 = fraction_1.denominator / gcd(fraction_2.numerator, fraction_1.denominator);

    result.numerator = numerator_1 * numerator_2;
    result.denominator = denominator_1 * denominator_2;

    return result;
}

Fraction operator/(const Fraction & fraction_1, const Fraction & fraction_2){
    Fraction temp_f;
    temp_f.numerator = fraction_2.denominator;
    temp_f.denominator = fraction_2.numerator;
    return (fraction_1 * temp_f);
}

#endif



/*

1(4/5)
81/100
1
1/2
0
0
6
8
1/2

*/