#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main(){
    string str, bomb;
    cin >> str >> bomb;
    string answer = "";

    int a_len = str.length();
    int b_len = bomb.length();
    for(int i = 0; i < str.length(); i++){
        answer += str[i];

        if(answer.length() >= b_len && answer.substr(answer.length() - b_len) == bomb){
            answer.erase(answer.length() - b_len, b_len);
        }
    }

    if(answer == ""){
        cout << "FRULA";
    }
    else{
        cout << answer;
    }
}