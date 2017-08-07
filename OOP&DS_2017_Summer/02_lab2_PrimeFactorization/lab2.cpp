#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// intput: two integers (less than 2^31)
// output: Greatest Common Divisor = prime factorization of GCD

int GCD(int a, int b){
    if(b > a){ return GCD(b, a); }
    int c;
    c = a % b;
    if(c == 0){ return b; }
    else{ return GCD(b, c); }
}

int pow(int a, int x){
    int result = 1;
    for(int i=0; i<x; i++){ result = result * a; }
    return result;
}

bool check_prime(int a){
    int upper_bound = 1;
    if(a == 2){ return true; }
    for(int i=2; i<a; i++){ if(i*i >= a) { upper_bound = i; break; } }
    for(int i=2; i<upper_bound+1; i++){ if(a % i == 0){ return false; } }
    return true;
}

char int2char(int & a){ return (char)(a+'0'); }

string prime_factorization(vector<int> prime_list, int a){
    int target_int = a;
    if(target_int == 1){ return string("1"); }
    vector<int> factor_list(0), order_list(0);

    // finish factor_list, order_list
    for(int i=0; i<prime_list.size(); i++){
        int factor = 0, order = 0;
        int prime_int = prime_list[i];

        while(target_int % prime_int == 0){
            factor = prime_int;
            order = order +1;
            target_int = (int) target_int / prime_int;
        }

        if(factor != 0){
            factor_list.push_back(factor);
            order_list.push_back(order);
        }
    }

    // // for check
    // for(int i=0; i<factor_list.size(); i++){cout << factor_list[i] << ' ';}
    // cout << endl;
    // for(int i=0; i<order_list.size(); i++){cout << order_list[i] << ' ';}
    // cout << endl;

    // result string
    string result = "";
    for(int i=0; i<factor_list.size(); i++){
        string temp_str = to_string(factor_list[i]);
        // temp_str.push_back(to_string(factor_list[i]));
        if(order_list[i] > 1){ temp_str = temp_str + '^' + to_string(order_list[i]); }
        result = result + temp_str + '*';
    }
    result.pop_back();   // remove the last '*'
    return result;
}


int main(int argc, char **argv){
    fstream input_file;
    input_file.open(argv[1], ios::in);

    int input_numbers, a, b;
    input_file >> input_numbers;
    // cout << "input_numbers: " << input_numbers << endl;

    // build prime list array
    int upper_bound = pow(2, 31-1), list_size = 10000;
    vector<int> prime_list(0);

    for(int i=2; i<upper_bound; i++){
        if(check_prime(i)==true){ prime_list.push_back(i); }
        if(prime_list.size() >= list_size){ break; }
    }

    cout << "prime_list array: ok, the last element: " << prime_list.back() << endl;

    // calculate
    while(input_numbers--){
        input_file >> a >> b;
        // cout << "a: " << a << ", b: " << b << endl;
        int gcd = GCD(a, b);
        string pf = prime_factorization(prime_list, gcd);
        cout << gcd << '=' << pf << endl;
    }
}


/*

// ans

prime_list array: ok, the last element: 104729
360=2^3*3^2*5
2=2
784=2^4*7^2
20=2^2*5
1=1
14095=5*2819
1=1
2800282=2
3612571=97*37243



*/


