
/*
3.(20%)
First line is the input case number , which is less than 100.
Given a line of words, reverse the words position in the line.
Each word is separated by a space or more.
Each line will less than 1000000 characters.
The answer of each word is separated by a single space, each answer is in a line.
Please use standard input and standard output to finish this question.

example:
    input:  
            3
            You are smart
            long Time no seE
            TA’s ars some beautiful.
    output: 
            smart are You
            seE no Time long
            beautiful. some ars TA’s
*/

// file: "question3_testfile_mod.txt"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string deal_string(string &);

int main(int argc, char ** argv){

    fstream input_file;
    string file_name;
    // file_name = argv[1];
    file_name = "question3_testfile_mod.txt";
    input_file.open(file_name, ios::in);

    int input_numbers;    // assume a < 2^31, use int 
    string input_string, output_string;
    input_file >> input_numbers;
    getline(input_file, input_string);  //  get the remain string of the first line

    // loop here
    // input_file >> input_string;
    while(input_numbers--){
        getline(input_file, input_string);
        cout << "input_string: " << input_string << endl;
        output_string = deal_string(input_string);
        cout << "output_string: " << output_string << endl;
    }
}


string deal_string(string & str){
    vector<string> str_vector;
    string result = "";
    int start_point = 0, end_point = 0;

    for(int i=0; i<str.size(); i++){
        if(str[i] == ' '){
            end_point = i -1;
            str_vector.push_back(str.substr(start_point, (end_point-start_point+1)));
            start_point = i +1;
        }
        if(i == str.size() -1){
            end_point = i;
            str_vector.push_back(str.substr(start_point, (end_point-start_point+1)));
        }
    }

    for(int i=str_vector.size()-1; i>=0; i--){
        result = result + str_vector.at(i) + " ";
    }

    return result;
}


/*

result e.g.

input_string: 1 2 3 4 5 6 7 8 9
output_string: 9 8 7 6 5 4 3 2 1

input_string: a ab abc abcd abcde abcdef abcdefg abcdef abcde abcd abc ab
output_string: ab abc abcd abcde abcdef abcdefg abcdef abcde abcd abc ab a

*/



