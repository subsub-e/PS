#include <string>
#include <vector>
#include <iostream>

using namespace std;

string toString(long long n){
    string str = "";
    while(n){
        str = to_string(n % 2) + str;
        n /= 2;
    }
    return str;
}

string padString(string str){
    int index = 2;
    string temp = str;
    while(temp.length() > (index - 1)){
        index *= 2;
    }
    
    for(int i = 0; i < index - 1 - str.length(); i++){
        temp = "0" + temp;
    }
    return temp;
}

bool isAllZero(string now){
    for(int i = 0; i < now.length(); i++){
        if(now[i] != '0'){
            return false;
        }
    }
    return true;
}

bool check(string str){
    if(str.length() == 1 || isAllZero(str)){
        return true;
    }
    
    int index = str.length() / 2;
    string left = str.substr(0, index);
    string right = str.substr(index + 1);
    
    if(str[index] == '1' && check(left) && check(right)){
        return true;
    }
    else{
        return false;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(auto now : numbers){
        string str = toString(now);
        string padStr = padString(str);
        if(check(padStr)){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
    }
    
    return answer;
}