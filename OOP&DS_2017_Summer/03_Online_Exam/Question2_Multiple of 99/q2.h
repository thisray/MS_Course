#ifndef Q2_h
#define Q2_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigNumber
{
    private:
        vector<int> number;
    public:
        BigNumber();
        BigNumber(const BigNumber &);
        BigNumber(const string &);

        friend ostream & operator<<(ostream &, const BigNumber &);
        string result();
        bool determine(const int);
};


BigNumber::BigNumber(const BigNumber & b1){
    this->number = b1.number;
}

BigNumber::BigNumber(const string & s1){
    for(int i=s1.size()-1; i>=0; i--){
        int temp = (int) (s1[i] - '0');
        this->number.push_back(temp);
    }
}

ostream & operator<<(ostream & os, const BigNumber & b1){
    for(int i=0; i<b1.number.size(); i++){
        os << b1.number.at(i);
    }
    return os;
}

bool BigNumber::determine(const int n){
    int size = this->number.size();
    bool result;
    if(n == 9){
        long sum = 0;
        for(int i=0; i<size; i++){ sum = sum + this->number.at(i); }
        if(sum % 9 == 0){ result = true; }
        else{ result = false; }
    }
    else if(n == 11){
        long sum_1 = 0, sum_2 =0, sum;
        for(int i=1; i<size; i=i+2){ sum_1 = sum_1 + this->number.at(i); }
        for(int i=0; i<size; i=i+2){ sum_2 = sum_2 + this->number.at(i); }
        sum = sum_1 - sum_2;
        if(sum < 0){ sum = sum * -1;}
        if(sum % 11 == 0){ result = true; }
        else{ result = false; }
    }
    return result;
}

string BigNumber::result(){
/*
    Please print "Computer" if x is multiples of 9,
    print "Science" if x is mulltiples of 11,
    print "ComputerScience" if x is multiples of 99,
    and print "Bug" if otherwise.
*/

    string result;

    if(this->determine(9) == true && this->determine(11) == true){ result = "ComputerScience"; }
    else if(this->determine(9) == true){ result = "Computer"; }
    else if(this->determine(11) == true){ result = "Science"; }
    else{ result = "Bug"; }

    return result;
}


#endif