#ifndef Fraction_h
#define Fraction_h

/*

1.(15%)
Compute the fraction operations with operator overloading. ( + , * , / , >> , <<)
First line is the number of testing data.
From the second line, each line contains 4 numbers (A, B, C, D), and each number
is separated by space.
These 4 numbers, A B C D, represent 2 fractions (A/B) and (C/D).
A, B, C, D are in the range of (0~2^32-1), but B and D will not be zero.
Please compute (a/b)+(c/d), (a/b)*(c/d), and (a/b)/ (c/d).
Please print the fraction in lowest term.
The output format of a fraction is numerator/denominator,
but if the denominator of the answer is 1 or numerator of the answer is 0, please do
not print out the denominator.
TAs will use this main to run your code, you don’t need to have main function in your
code

sample input: 
3
3 2 2 3
0 2 1 2
4 2 12 3

sample output: 
13/6 1 9/4
1/2 0 0
6 8 1/2

*/

#include <iostream>
using namespace std;

long gcd(long, long);

class Fraction{
    private:
        long numerator, denominator;
    public:
        Fraction();
        Fraction(const Fraction &);
        Fraction(long, long);

        friend istream & operator>>(istream &, Fraction &);
        friend ostream & operator<<(ostream &, const  Fraction &);

        friend Fraction operator+(const Fraction &, const Fraction &);
        friend Fraction operator*(const Fraction &, const Fraction &);
        friend Fraction operator/(const Fraction &, const Fraction &);

        Fraction reduction();
};

Fraction::Fraction(){
    this->numerator = 0;
    this->denominator = 1;
}

Fraction::Fraction(const Fraction & fraction){
    this->numerator = fraction.numerator;
    this->denominator = fraction.denominator;
}

Fraction::Fraction(long a, long b){
    this->numerator = a;
    this->denominator = b;
    this->reduction();
}

Fraction Fraction::reduction(){
    long _gcd = gcd(this->numerator, this->denominator);
    this->numerator = (this->numerator / _gcd);
    this->denominator = (this->denominator / _gcd);
    return *this;
}

istream & operator>>(istream & is, Fraction & fraction){
    is >> fraction.numerator >> fraction.denominator;   // it seems don't need 'char space'
    return is;
}

ostream & operator<<(ostream & os, const Fraction & fraction){
    if(fraction.denominator == 1 || fraction.numerator == 0){ os << fraction.numerator; }
    else{ os << fraction.numerator << "/" << fraction.denominator; }
    return os;
}

Fraction operator+(const Fraction & fra_1, const Fraction & fra_2){
    Fraction result;
    long denominator_gcd = gcd(fra_1.denominator, fra_2.denominator);
    result.numerator = fra_1.numerator * (fra_2.denominator / denominator_gcd) + fra_2.numerator * (fra_1.denominator / denominator_gcd);
    result.denominator = fra_1.denominator * fra_2.denominator / denominator_gcd;
    return result.reduction();
}

Fraction operator*(const Fraction & fra_1, const Fraction & fra_2){
    Fraction result;
    long gcd_1 = gcd(fra_1.numerator, fra_2.denominator), gcd_2 = gcd(fra_1.denominator, fra_2.numerator);
    result.numerator = (fra_1.numerator / gcd_1) * (fra_2.numerator / gcd_2);
    result.denominator = (fra_1.denominator / gcd_2) * (fra_2.denominator / gcd_1);
    return result.reduction();
}

Fraction operator/(const Fraction & fra_1, const Fraction & fra_2){
    Fraction temp_fra;
    temp_fra.numerator = fra_2.denominator;
    temp_fra.denominator = fra_2.numerator;
    return (fra_1 * temp_fra);
}

long gcd(long a, long b){
    if(a < 0 || b < 0){ return 1; }   // avoid strange input // ****** don't use 'a*b' ******
    long c = a % b;
    if(c == 0){ return b; }
    else{ return gcd(b, c); }
}

#endif


/*

5/6
1/6
3/2
5/14
3/98
3/2
20201/10100
1
10000/10201
9
20
4/5
1/97
0
0
290/17
1
289
3/34
1/578
2
80/534847
51/9864183221
29/51
3965344/146439
207425/146439
3957669/7675
155/416179
399800021/11529214960169124
19997/19993

*/




