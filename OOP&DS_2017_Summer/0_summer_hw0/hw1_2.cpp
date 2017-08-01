#include <iostream>
using namespace std;

class RationalNumber{
    private:
        int son, mother;
        int pos_neg;  // 1:+, -1:-
        
        void check_pos_neg(){
            pos_neg = 1;
            if(son < 0){son = -1 * son; pos_neg = -1 * pos_neg;}
            if(mother < 0){mother = -1 * mother; pos_neg = -1 * pos_neg;}
        }

        int getGCD(int a, int b){
            if(b > a){ return getGCD(b, a); }
            int c;
            c = a % b;
            if(c==0){ return b; }
            else{ return getGCD(b, c); }
        }

        void devideGCD(){
            int GCD = getGCD(son, mother);
            son = son / GCD;
            mother = mother / GCD;
        }

    public:
        // set the RationalNumber of 1
        RationalNumber(){ son = 1; mother = 1; }

        // initialize the RationalNumber to 𝑛𝑢𝑚𝑒𝑟𝑎𝑡𝑜𝑟 / 𝑑𝑒𝑛𝑜𝑚𝑖𝑛𝑎𝑡𝑜𝑟
        // you can assume that denominator will not be 0
        RationalNumber(int numerator, int denominator){
            son = numerator;
            mother = denominator;
            check_pos_neg();
            devideGCD();
        }

        // use cout to print the RationalNumber in the form of 𝑝 / 𝑞
        // where p and q are coprime.
        void toCompact(void){
            if(pos_neg == -1){ son = -1 * son; }
            cout << son << " / " << mother << endl; 
        }

        // use operator overloading to that RationalNumber can be used in
        // addition(+), deletion(-), multiplication (*)

        friend RationalNumber operator+(const RationalNumber & R1, const RationalNumber & R2){
            RationalNumber R;
            if(R1.mother == R2.mother){ R.mother = R1.mother; R.son = R1.son + R2.son; }
            else{
                R.son = R1.son * R2.mother + R2.son * R1.mother;
                R.mother = R1.mother * R2.mother;
            }
            return RationalNumber(R.son, R.mother);
        }

        friend RationalNumber operator-(const RationalNumber & R1, const RationalNumber & R2){
            RationalNumber R;
            if(R1.mother == R2.mother){ R.mother = R1.mother; R.son = R1.son - R2.son; }
            else{
                R.son = R1.son * R2.mother - R2.son * R1.mother;
                R.mother = R1.mother * R2.mother;
            }
            return RationalNumber(R.son, R.mother);
        }

        friend RationalNumber operator*(const RationalNumber & R1, const RationalNumber & R2){
            RationalNumber R;
            R.son = R1.son * R2.son;
            R.mother = R1.mother * R2.mother;
            return RationalNumber(R.son, R.mother);
        }

};

// Can I write "void main()"?
// -> http://www.stroustrup.com/bs_faq2.html#void-main

// RationalNumber should be able to be used in the following code segment.
int main()
{
    RationalNumber r1, r2(2,3), r3(6,4);
    r1.toCompact();
    r2.toCompact();
    r3.toCompact();

    r1 = r2 + r3;
    r1.toCompact();

    r1 = r2 - r3;
    r1.toCompact();

    r1=(r2+r3)*r2-r3;
    r1.toCompact();
}