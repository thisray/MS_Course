#include <iostream>
#include <vector> 
#include <string>
#include <fstream>
using namespace std;

#define SIZE 30000

// 0 < x < 10^20000 and 0 < y < 10^20000

class BigNumber{
    private:
        vector<int> number;
        int sign;

    public:
        int size() const {return this->number.size();}

        BigNumber(){number=vector<int>(); sign=+1;}
        BigNumber(const BigNumber & B1){this->number=B1.number; this->sign=B1.sign;}
        BigNumber(string s){
            sign=+1;
            if(s.back() == '-'){ sign = -1; s.pop_back();}
            else{ sign = +1; }
            number=vector<int>(); 
            for(int i = s.size()-1; i >=0; i--){ number.push_back((int)(s.at(i)-'0')); }
            // int:   9527
            // index: 3210, size = 4
        }

        // overload '+'
        friend BigNumber operator+(const BigNumber & B1, const BigNumber & B2){
            BigNumber result;
            int big_size = B1.size(), temp_int, carry_int = 0;
            if(B2.size() > big_size){big_size = B2.size();}
            for(int i = 0; i < big_size +1; i++){
                int n1 = 0, n2 = 0;
                if(i < B1.size()){ n1 = B1.number.at(i); }
                if(i < B2.size()){ n2 = B2.number.at(i); }
                temp_int = n1 + n2 + carry_int;
                if(temp_int >= 10){
                    temp_int = temp_int - 10;
                    carry_int = +1;
                }
                else{ carry_int = 0; }
                result.number.push_back(temp_int);
            }
            if(result.number.back() == 0){result.number.pop_back();}
            return result;
        }


        // overload '>' (bigger than)
        friend bool operator>(const BigNumber & B1, const BigNumber & B2){
            if(B1.size() > B2.size()){ return true; }
            else if(B1.size() == B2.size()){
                for(int i=B1.size()-1; i>=0; i--){
                    if(B1.number.at(i) > B2.number.at(i)){ return true; }
                    if(B1.number.at(i) < B2.number.at(i)){ return false; }
                }
            }
            return false;
        }

        // overload '>=' (bigger than)
        friend bool operator>=(const BigNumber & B1, const BigNumber & B2){
            if(B1.size() > B2.size()){ return true; }
            else if(B1.size() == B2.size()){
                for(int i=B1.size()-1; i>=0; i--){
                    if(B1.number.at(i) > B2.number.at(i)){ return true; }
                    if(B1.number.at(i) < B2.number.at(i)){ return false; }
                }
                return true;    // equal
            }
            return false;   
        }        

        // overload '-',  ** must bigger - smaller
        friend BigNumber operator-(const BigNumber & B1, const BigNumber & B2){

            // cout << "B1 first: " << B1.number.back() << ", B1.number.at(B1.size()-1): " << B1.number.at(B1.size()-1) << ", len: " << B1.size() << endl;
            // cout << "B2 first: " << B2.number.back() << ", B2.number.at(B2.size()-1): " << B2.number.at(B2.size()-1) << ", len: " << B2.size() << endl;

            // B_big - B_small
            BigNumber result, B_big, B_small;
            // check B1 > B2, of add '-'
            if(B2 > B1){ B_big = B2; B_small = B1; result.sign = -1; }
            else{ B_big = B1; B_small = B2; }

            // cout << "view: " << B1.number.back() << " "  << B2.number.back() << " " << B_big.number.back()  << " "  << B_small.number.back() << endl;

            int carry_int = 0;
            for(int i = 0; i < B_big.size(); i++){
                int n1 = 0, n2 = 0, temp_int = 0;
                if(i < B_big.size()){ n1 = B_big.number.at(i); }
                if(i < B_small.size()){ n2 = B_small.number.at(i); }
                temp_int = n1 - n2 + carry_int;
                if(temp_int < 0){ temp_int = temp_int + 10; carry_int = -1; }
                else{ carry_int = 0; }
                result.number.push_back(temp_int);
            }
            while(result.number.back() == 0){
                result.number.pop_back();
                if(result.number.size() == 1){break;}
            }
            return result;
        }


        // overload '*'
        friend BigNumber operator*(const BigNumber & B1, const BigNumber & B2){
            BigNumber result;
            result.number.resize(B1.size() + B2.size() + 1);
            for(int i = 0; i<B1.size() ; i++){
                for(int j = 0; j<B2.size() ; j++){
                    result.number.at(i+j) = result.number.at(i+j) + B1.number.at(i) * B2.number.at(j);
                }
            }

            for(int i = 0; i<result.size()-1 ; i++){
                result.number.at(i+1) = result.number.at(i+1) + result.number.at(i) / 10;
                result.number.at(i) = result.number.at(i) % 10;
            }

            int final_int = result.number.back();
            while(final_int > 0){
                result.number.back() = result.number.back() % 10;
                final_int = final_int / 10;
                result.number.push_back(final_int);
            }

            return result;
        }

        // overload '/', dividend / divisor = quotient + remainder
        friend BigNumber operator/(const BigNumber & B1, const BigNumber & B2){
            BigNumber dividend = B1, divisor = B2, quotient;
            int digit_dif = 0, times = 0;

            digit_dif = dividend.size() - divisor.size();
            if(digit_dif < 0){ quotient.number.resize(1); return quotient; }
            quotient.number.resize(digit_dif+1);    // [0, 0, 0, ...]

            while(1){
                BigNumber temp_divisor;
                times = 0;
                if(digit_dif < 0){ break; }
                // e.g. 5487/32 -> 5487/3200
                temp_divisor.number.resize(divisor.size() + digit_dif);
                for(int i=0; i<divisor.size(); i++){ temp_divisor.number.at(i+digit_dif) = divisor.number.at(i); }

                while(dividend >= temp_divisor){
                    dividend = dividend - temp_divisor;
                    times = times +1;
                }
                quotient.number.at(digit_dif) = times;
                digit_dif = digit_dif -1;
                if(divisor>dividend){ break; }
            }
            return quotient;
        }

        // overload '<<'
        friend ostream & operator<<(ostream & os, const BigNumber & B1){
            if(B1.sign == -1){ os << '-'; }
            for(int i = B1.size() -1; i >= 0; i--){ os << B1.number.at(i); }
            // os << endl;
            return os;
        }

        // print from i to j
        void print_ij(int ii, int jj){
            if(this->sign == -1){ cout << '-';}
            if(jj>=this->number.size()){ jj=this->number.size()-1; }
            if(ii>=this->number.size()){ ii=this->number.size()-1; }
            for(int i = jj; i >= ii; i--){ cout << this->number.at(i); }
            cout << endl;
        }

};


// Use command line to read the input file xxx.txt (argv[1])
// example command: $ ./a.out test1.txt
int main(int argc, char* argv[]){
    // std::cout << argv[0] << std::endl;  --> './a.out' 
    // std::cout << argv[1] << std::endl;  --> 'test1.txt'

    string input_file_name = "None";
    if(argc==2){ input_file_name = argv[1]; }

    // input '.txt' files in './data/' dir
    string input_file_path = "./data/" + input_file_name;
    fstream input_file;

    string a, b;
    char input_operator;
    int input_numbers, i, j;
    
    // read file
    input_file.open(input_file_path, ios::in);
    cout << "open file: " << input_file_path << endl;
    input_file >> input_numbers;
    cout << "input_numbers: " << input_numbers << endl;

    while(input_numbers--){
        input_file >> a >> input_operator >> b >> i >> j;

        // // for check input
        // cout << "a: " << a << endl;
        // cout << "input_operator: " << input_operator << endl;
        // cout << "b: " << b << endl;
        // cout << "i: " << i << endl;
        // cout << "j: " << j << endl;

        BigNumber x(a), y(b);

        if(input_operator == '+'){ (x + y).print_ij(i, j); }
        else if(input_operator == '-'){ (x - y).print_ij(i, j); }
        else if(input_operator == '*'){ (x * y).print_ij(i, j); }
        else if(input_operator == '/'){ (x / y).print_ij(i, j); }

        if(input_numbers <1){break;}
    }


    return 0;    
}

/*
// check answer
    add1, add2 ok
    sub1, sub2 ok
    mul1, mul2 ok
    div1, div2 ok
*/







