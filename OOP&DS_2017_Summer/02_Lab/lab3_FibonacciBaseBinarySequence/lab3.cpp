#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string find_seq(vector<int> & Fibonacci_table, int input_number){

    // find max_index
    int max_index = 0;
    for(int i=0; i<Fibonacci_table.size(); i++){ 
        if(Fibonacci_table.at(i) > input_number){ 
            max_index = i -1; 
            break; 
        } 
    }

    // Go
    int now_index = max_index;
    string result;
    while(now_index > 0){
        if(input_number >= Fibonacci_table.at(now_index)){
            input_number = input_number - Fibonacci_table.at(now_index);
            result = result + "1";
            now_index = now_index -1;
        }else{
            result = result + "0";
            now_index = now_index -1;
        }
        // if(input_number <= 0){ break; }
        if(now_index == 1){ break; }    // don't use Fibonacci_table[1] 
    }
    return result;
}



int main(int argc, char **argv){

    // 1. build Fibonacci-Table
    int table_size = 100;
    vector<int> Fibonacci_table(2);
    Fibonacci_table.at(0) = 0;
    Fibonacci_table.at(1) = 1;
    for(int i=2; i<table_size; i++){
        int temp_n = Fibonacci_table.at(i-1) + Fibonacci_table.at(i-2);
        if(temp_n < 0){ break; }
        Fibonacci_table.push_back(temp_n);
    }

    // 2. deal -> find_seq()

    // // for test
    // cout << "result: " << find_seq(Fibonacci_table, 6) << endl;
    // cout << "result: " << find_seq(Fibonacci_table, 10) << endl;
    // cout << "result: " << find_seq(Fibonacci_table, 17) << endl;

    // get input from file
    fstream input_file;
    input_file.open(argv[1], ios::in);

    int input_numbers, a;    // assume a < 2^31, use int 
    input_file >> input_numbers;

    // calculate
    while(input_numbers--){
        input_file >> a;
        cout << "a: " << a << ", result: " << find_seq(Fibonacci_table, a) << endl;
    }

}


/*

// test1.txt

a: 165580140, result: 101010101010101010101010101010101010101
a: 111561621, result: 100001000000000000000000000000000000001
a: 122967395, result: 100010100000000000000000000000000000001
a: 111758128, result: 100001000000010000000000000001000000001
a: 123406798, result: 100010100000101000000000000010100000001
a: 112151053, result: 100001000001000100000000000010010000001
a: 102923677, result: 100000000001000100000000000100010000001
a: 102923698, result: 100000000001000100000000000100100000001
a: 102969977, result: 100000000001001000000000000010100000001
a: 102533247, result: 100000000000010000000010000001000000001
a: 102335753, result: 100000000000000000000001000000000000001
a: 102339934, result: 100000000000000000000101000000000000001
a: 102654606, result: 100000000000100000000010000000100000001
a: 102848419, result: 100000000001000000000000000000010000001
a: 103484083, result: 100000000010100000000000000000101000001
a: 103998194, result: 100000000100010101010101010101000100001
a: 102530489, result: 100000000000001010101010101010000001000
a: 102334167, result: 100000000000000000000000000000000010101
a: 102334161, result: 100000000000000000000000000000000001001
a: 165580140, result: 101010101010101010101010101010101010101



// test2.txt

a: 1, result: 1
a: 4, result: 101
a: 12, result: 10101
a: 33, result: 1010101
a: 88, result: 101010101
a: 232, result: 10101010101
a: 609, result: 1010101010101
a: 1596, result: 101010101010101
a: 4180, result: 10101010101010101
a: 1836288719, result: 10101010101010101010100100100100100100100101
a: 1835699464, result: 10101010101010100010000100100100100100100100
a: 1834335485, result: 10101010101010000010000000100100100100100101
a: 1830806725, result: 10101010101000000010000000000100100100100100
a: 1821578274, result: 10101010100000000010000000000000100100100101
a: 1797420223, result: 10101010000000000010000000000000000100100100
a: 1734174183, result: 10101000000000000010000000000000000000100101
a: 1568594028, result: 10100000000000000010000000000000000000000100
a: 1135099589, result: 10000000000000000010000000000000000000000001


*/



