#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// input: (a/b,c/d)   ->  A = a/b, B = c/d
// output: x / y //   ->  A*B + A/B = x / y

// need to do: +, *, /, <<

// ** note: I use 'long' instead of 'int' to avoid number > 2^32-1

long gcd(long, long);
long lcm(long, long);

class Fraction{
    private:
        long son, mother;
    public:
        Fraction();
        Fraction(const Fraction &);
        Fraction(const long, const long);

        friend Fraction operator+(const Fraction &, const Fraction &);
        friend Fraction operator*(const Fraction &, const Fraction &);
        friend Fraction operator/(const Fraction &, const Fraction &);
        friend ostream & operator<<(ostream &, const Fraction &);
};

Fraction::Fraction(){
    this->son = 0; 
    this->mother = 1;
}

Fraction::Fraction(const Fraction & f1){
    this->son = f1.son; 
    this->mother = f1.mother;
}

Fraction::Fraction(long son, long mother){
    long _gcd = gcd(son, mother);
    son = son / _gcd;
    mother = mother / _gcd;
    this->son = son; 
    this->mother = mother;
}

Fraction operator+(const Fraction & f1, const Fraction & f2){
    Fraction result;
    long lcm_mother = lcm(f1.mother, f2.mother);
    long f1_need = lcm_mother / f1.mother, f2_need = lcm_mother / f2.mother;;
    result.son = f1.son * f1_need + f2.son * f2_need;
    result.mother = lcm_mother;
    return result;
}

Fraction operator*(const Fraction & f1, const Fraction & f2){
    Fraction result;
    long gcd_1 = gcd(f1.son, f2.mother), gcd_2 = gcd(f2.son, f1.mother);
    result.son = (f1.son/gcd_1) * (f2.son/gcd_2);
    result.mother = (f1.mother/gcd_2) * (f2.mother/gcd_1);

    long _gcd = gcd(result.son, result.mother);
    result.son = result.son / _gcd;
    result.mother = result.mother / _gcd;
    return result;
}

Fraction operator/(const Fraction & f1, const Fraction & f2){
    Fraction temp(f2.mother, f2.son);
    return f1 * temp;
}

ostream & operator<<(ostream & os, const Fraction & fra){
    if(fra.mother == 1 || fra.son == 0){ os << fra.son << endl; }
    else{ os << fra.son << '/' << fra.mother << endl; }
    return os;
}

long gcd(long a, long b){
    if(b > a){ return gcd(b, a); }
    if(b == 0){ return 1; }
    long c = a % b;
    if(c == 0){ return b; }
    else{ return gcd(b, c); }
}

long lcm(long a, long b){
    return a*b / gcd(a,b);
}


int main(int argc, char **argv){

    // // get input from file
    fstream input_file;
    input_file.open(argv[1], ios::in);

    int input_numbers;    // assume a < 2^31, use int 
    input_file >> input_numbers;

    long a = 1647483648, b = 23, c = 2, d = 1;
    // for test
    // Fraction A(a, b), B(c, d);
    // cout << a << ' ' << b << ' '  << c << ' '  << d << ' '  << endl;
    // cout << A + B << endl;
    // cout << A * B << endl;
    // cout << A / B << endl;
    // cout << "a * 2 = " << a*2 << endl;

    char temp;
    while(input_numbers--){
        input_file >> temp >> a >> temp >> b >> temp >> c >> temp >> d >> temp;
        cout << a << ' ' << b << ' '  << c << ' '  << d << ' '  << endl;

        Fraction A(a, b), B(c, d), B_(d, c);
        // cout << A*B + A/B << endl;
        cout << A * (B + B_) << endl;
    }

}


/*
$ g++ lab4.cpp
$ ./a.out test.txt

3 5 5 3
34/25

20 2 10 2
52

0 7 17 23
0

310217 320224 32 31
1985/1024

1647483648 23 1 1
3294967296/23

2027 2017 10007 10009
406048903510/202022847071
*/

