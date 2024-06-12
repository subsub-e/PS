#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int answer;

bool ischeck(long long x){
    if(x < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

void func(string str){
    string temp = "";
    for(int i = 0; i < str.length(); i++){
        if(i != 0 && str[i] == '0' && temp != ""){
            if(ischeck(stoll(temp))){
                answer++;
            }
            temp = "";
        }
        else{
            temp += str[i];
        }
    }
    if(temp != ""){
        if(ischeck(stoll(temp))){
            answer++;
        }
    }
}

int solution(int n, int k) {
    
    string str = "";
    while(n > 0){
        char c = (char) (n % k + 48);
        n /= k;
        str.push_back(c);
    }
    reverse(str.begin(), str.end());
    func(str);
    return answer;
}