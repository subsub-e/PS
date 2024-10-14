#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    
    for(int i = 0; i < s.length(); i++){
        if(st.empty() && s[i] == ')'){
            answer = false;
            break;
        }
        if(s[i] == ')' && !st.empty()){
            st.pop();
        }
        if(s[i] == '('){
            st.push('(');
        }
    }
    
    if(!st.empty()){
        return false;
    }

    return answer;
}