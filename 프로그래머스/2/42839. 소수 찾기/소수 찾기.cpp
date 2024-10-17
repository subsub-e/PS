#include <string>
#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

unordered_set<int> s;
bool visited[10];

bool isPrime(int x){
    if(x < 2){
        return false;
    }
    for(int i = 2; i <= x / 2; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

void func(string x, int l, string numbers){
    if(x.length() == l){
        s.insert(stoi(x));
        return;
    }
    
    for(int i = 0; i < numbers.length(); i++){
        if(!visited[i]){
            visited[i] = 1;
            x += numbers[i];
            func(x, l, numbers);
            visited[i] = 0;
            x.pop_back();
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    for(int i = 1; i <= numbers.length(); i++){
        func("", i, numbers);
    }
    
    for(auto it : s){
        if(isPrime(it)){
            answer++;
        }
    }
    
    return answer;
}