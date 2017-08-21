#ifndef BigNum_h
#define BigNum_h

/*

The BigNum class contains following member function:
● BigNum(​????​);
The constructor.
● BigNum(​????​);
The copy constructor.
● BigNum operator+(​????​);
● BigNum operator-(​????​);
● BigNum operator*(​????​);
● BigNum operator/(​????​);
● ostream& operator<<(​????​);
output “one” big number
● istream& operator>>(​????​);
input “one” big number
????​= your parameter(s)

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BigNum{
    private:
        vector<int> number;
        int sign;
    public:
        BigNum();
        BigNum(int);
        BigNum(const BigNum &);
        // ~BigNum();

        friend istream & operator>>(istream &, BigNum &);
        friend ostream & operator<<(ostream &, const BigNum &);

        friend BigNum operator+(const BigNum &, const BigNum &);
        friend BigNum operator-(const BigNum &, const BigNum &);
        friend BigNum operator*(const BigNum &, const BigNum &);
        friend BigNum operator/(const BigNum &, const BigNum &);
};

BigNum::BigNum(){
    vector<int> temp;
    this->number = temp;
    this->sign = +1;
}

BigNum::BigNum(int n){
    BigNum temp;
    temp.number.push_back(n);
    this->number = temp.number;
    this->sign = temp.sign;
}

BigNum::BigNum(const BigNum & big_n){
    this->number = big_n.number;
    this->sign = big_n.sign;
}

// BigNum::~BigNum(){
//     delete this->number;
// }


istream & operator>>(istream & is, BigNum & big_n){
    string input;
    // getline(is, input, ' ');
    // cout << "input: " << input << endl;  // for check

    is >> input;

    int start_point = input.size() -1, end_point = 0;

    if(input.at(0) == '\n'){
        end_point = end_point +1;
    }

    if(input.at(end_point) == '-'){
        big_n.sign = -1;
        end_point = end_point +1;
    }

    for(int i=start_point; i>=end_point; i--){
        int value = (int)(input.at(i) - '0');
        big_n.number.push_back(value);
    }
    return is;
}

ostream & operator<<(ostream & os, const BigNum & big_n){
    if(big_n.sign == -1){
        os << "-";
    }
    for(int i=big_n.number.size()-1; i>=0; i--){
        os << big_n.number.at(i);
    }
    // os << endl;  // no need
    return os;
}

BigNum operator+(const BigNum & big_n1, const BigNum & big_n2){
    BigNum result;

    if(big_n1.sign == -1 && big_n2.sign == +1){
        result = big_n1;
        result.sign = +1;
        return (big_n2 - result);
    }
    else if(big_n1.sign == +1 && big_n2.sign == -1){
        result = big_n2;
        result.sign = +1;
        return (big_n1 - result);
    }
    else if(big_n1.sign == -1 && big_n2.sign == -1){
        result.sign = -1;
    }

    int n1 = 0, n2 = 0, size1 = big_n1.number.size(), size2 = big_n2.number.size(), big_size = 0;
    if(size1 > size2){ big_size = size1; }
    else{ big_size = size2; }

    for(int i=0; i<big_size; i++){      // add here
        n1 = 0; n2 = 0;
        if(i < size1){ n1 = big_n1.number.at(i); }
        if(i < size2){ n2 = big_n2.number.at(i); }
        result.number.push_back(n1 + n2);
    }

    for(int i=0; i<big_size; i++){
        if(result.number.at(i) >= 10){
            result.number.at(i) = result.number.at(i) - 10;
            if(i+1 == big_size){ result.number.push_back(1); }
            else{ result.number.at(i+1) = result.number.at(i+1) + 1; }
        }
    }
    return result;
}


BigNum operator-(const BigNum & big_n1, const BigNum & big_n2){
    BigNum result;

    if(big_n1.sign == +1 && big_n2.sign == -1){
        result = big_n2;
        result.sign = +1;
        return (big_n1 + result);
    }
    else if(big_n1.sign == -1 && big_n2.sign == +1){
        result = big_n1;
        result.sign = +1;
        return (big_n2 - result);
    }
    else if(big_n1.sign == -1 && big_n2.sign == -1){
        result = big_n2;
        result.sign = +1;
        return (big_n1 + result);
    }

    int n1, n2, size1 = big_n1.number.size(), size2 = big_n2.number.size(), big_size;

    if(size1 < size2){ 
        result = (big_n2 - big_n1);
        result.sign = -1;
        return result;
    }

    if(size1 == size2){
        for(int i=size1-1; i>=0; i--){
            if(big_n1.number.at(i) == big_n2.number.at(i)){
                continue;
            }
            else if(big_n1.number.at(i) > big_n2.number.at(i)){
                break;
            }
            else if(big_n1.number.at(i) < big_n2.number.at(i)){
                result = (big_n2 - big_n1);
                result.sign = -1;
                return result; 
            }
        }
    }

    big_size = size1;
    for(int i=0; i<big_size; i++){
        n1 = big_n1.number.at(i);
        n2 = 0;
        if(i < size2){ n2 = big_n2.number.at(i); }
        result.number.push_back(n1 - n2);
    }

    for(int i=0; i<big_size; i++){
        if(result.number.at(i) < 0){
            result.number.at(i) = result.number.at(i) + 10;
            result.number.at(i+1) = result.number.at(i+1) -1;
        }
    }

    int check_size = result.number.size() -1;
    while(result.number.at(check_size) == 0){
        result.number.pop_back();
        check_size = check_size -1;

        if(check_size == 0){
            break;
        }
    }

    return result;
}


BigNum operator*(const BigNum & big_n1, const BigNum & big_n2){
    BigNum result;

    for(int i=0; i<big_n1.number.size(); i++){
        BigNum temp_n;
        int padding_zero = i;
        while(padding_zero > 0){
            temp_n.number.push_back(0);
            padding_zero = padding_zero -1;
        }

        for(int j=0; j<big_n2.number.size(); j++){
            int val = big_n1.number.at(i) * big_n2.number.at(j);
            temp_n.number.push_back(val);
        }

        result = result + temp_n;
    }

    for(int i=0; i<result.number.size()-1; i++){
        if(result.number.at(i) > 10){
            int carry_number = result.number.at(i) / 10;
            result.number.at(i) = result.number.at(i) % 10;
            result.number.at(i+1) = result.number.at(i+1) + carry_number;
        }
    }

    int check_size = result.number.size() -1;
    while(result.number.at(check_size) > 10){
        int carry_number = result.number.at(check_size) / 10;
        result.number.at(check_size) = result.number.at(check_size) % 10;
        result.number.push_back(carry_number);
        check_size = check_size +1;
    }

    result.sign = big_n1.sign * big_n2.sign;
    return result;
}

// dividend / divisor = quotient + remainder
BigNum operator/(const BigNum & big_n1, const BigNum & big_n2){
    BigNum result;
    BigNum dividend = big_n1, divisor = big_n2, temp_divisor;
    int temp_divisor_size = dividend.number.size() - divisor.number.size();

    while(temp_divisor_size >= 0){
        temp_divisor = divisor;
        for(int i=0; i<temp_divisor_size; i++){
            temp_divisor.number.insert(temp_divisor.number.begin(), 0);
        }

        int quotient_here = 0;
        while((dividend - temp_divisor).sign > 0){
            dividend = dividend - temp_divisor;
            quotient_here = quotient_here +1;
        }

        result.number.insert(result.number.begin(), quotient_here);
        quotient_here = 0;
        temp_divisor_size = temp_divisor_size -1;
    }

    if(result.number.size() == 0){
        result.number.push_back(0);
    }

    int check_size = result.number.size() -1;
    while(result.number.at(check_size) == 0){
        result.number.pop_back();
        check_size = check_size -1;

        if(check_size == 0){
            break;
        }
    }

    return result;
}





#endif



/*

a: 9866124
b: 9876
c: 9876

9876000
9856248
97437840624
999
9866124

*/


