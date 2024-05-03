#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    //cout << (int) 'a' << ' ' << (int) 'z';
    int flag = 0;
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            answer += temp;
            answer += ' ';
            temp = "";
            continue;
        }
        if(temp == ""){
            if((int) s[i] >= 97 && (int) s[i] <= 122){
                s[i] = (char) ((int) s[i] - 32);
                temp += s[i];
            }
            else{
                temp += s[i];
            }
        }
        else{
            if((int) s[i] >= 65 && (int) s[i] <= 90){
                s[i] = (char) ((int) s[i] + 32);
                temp += s[i];
            }
            else{
                temp += s[i];
            }
        }
    }
    answer += temp;
    
    return answer;
}