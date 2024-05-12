#include <string>
#include <vector>
#include <stack>
using namespace std;

string func(string str){
    str.erase(str.begin());
    str.erase(str.end() - 1);
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ')'){
            str[i] = '(';
        }
        else{
            str[i] = ')';
        }
    }
    return str;
}

bool correct(string s) // "올바른 괄호 문자열"인지 판별
{
    stack<int> st;

    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        
        if (s[i] == ')')
            if (!st.empty())
                st.pop();
    }
    
    if (st.empty()) return true;
    else return false;
}

string convert(string str){
    if(str == ""){
        return str;
    }
    
    int openCnt = 0;
    int closeCnt = 0;
    int index = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            openCnt++;
        }
        else{
            closeCnt++;
        }
        if(openCnt == closeCnt){
            index = i + 1;
            break;
        }
    }
    
    string u = str.substr(0, index);
    string v = str.substr(index);
    
    string result = "";
    
    if(correct(u)){
        result = u + convert(v);
    }
    else{
        result = "(" + convert(v) + ")" + func(u);
    }
    
    return result;
}

string solution(string p) {
    string answer = convert(p);
    return answer;
}