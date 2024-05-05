#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    
    stack<char> q;
    q.push(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(q.empty()){
            q.push(s[i]);
            continue;
        }
        if(q.top() == s[i]){
            q.pop();
        }
        else{
            q.push(s[i]);
        }
    }
    
    if(q.empty()){
        return 1;
    }
    else{
        return 0;
    }
}