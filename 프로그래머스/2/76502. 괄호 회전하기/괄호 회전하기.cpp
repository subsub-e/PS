#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(string str){
    stack<char> s;
    for(int i = 0; i < str.length(); i++){
        if(s.empty() && (str[i] == ']' || str[i] == ')' || str[i] == '}')){
            return false;
        }
        if(str[i] == ']'){
            if(s.top() == '['){
                s.pop();
            }
            else{
                return false;
            }
        }
        else if(str[i] == '}'){
            if(s.top() == '{'){
                s.pop();
            }
            else{
                return false;
            }
        }
        else if(str[i] == ')'){
            if(s.top() == '('){
                s.pop();
            }
            else{
                return false;
            }
        }
        else{
            s.push(str[i]);
        }
    }
    if(!s.empty()){
        return false;
    }
    else{
        return true;
    }
}

int solution(string s) {
    int answer = 0;
    string temp = s;
    for(int i = 0; i < s.length(); i++){
        //cout << temp << '\n';
        if(check(temp)){
            answer++;
        }
        char c = temp[0];
        temp = temp.substr(1);
        temp.push_back(c);
    }
    return answer;
}