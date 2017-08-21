
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ** use <string>.substr(start_point, substr_len) **

string token_reverse(string input_string){
    string output_string, temp_string;
    vector<string> string_vector;
    int start_point = 0, substr_len = 0;

    for(int i=0; i<input_string.size(); i++){
        if(i == input_string.size()-1){
            temp_string = input_string.substr(start_point, substr_len +1);
            string_vector.push_back(temp_string);
        }

        if(input_string.at(i) == ' '){
            temp_string = input_string.substr(start_point, substr_len);
            start_point = i +1;
            substr_len = 0;
            string_vector.push_back(temp_string);
        }
        else{                               // <-- important "else" !
            substr_len = substr_len +1;
        }
        
    }

    // for(int i=0; i<string_vector.size(); i++){
    //     cout << string_vector.at(i) << " ";
    // }

    for(int i=string_vector.size()-1; i>=0; i--){
        output_string = output_string + string_vector.at(i) + ' ';
    }

    return output_string;
}



int main(){

    string input_string, output_string;
    // while(cin >> input_string){
    while(getline(cin, input_string)){      // use getline() here
        cout << "input_string: " << input_string << endl;

        output_string = token_reverse(input_string);
        cout << "output_string: " << output_string << endl;
    }

}
