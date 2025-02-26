#include <string>
#include <vector>
#include <set>
#include <stack>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> prev(n), next(n);

    stack<int> st;
    for (int i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;
    
    int cur = k;
    
    for(int i = 0; i < cmd.size(); i++){
        string str = cmd[i];
        if(str.length() > 1){
            int x = stoi(str.substr(2));
            
            if(str[0] == 'D'){
                while(x--){
                    cur = next[cur];
                }
            }
            else{
                while(x--){
                    cur = prev[cur];
                }
            }
        }
        else{
            if(str == "C"){
                st.push(cur);
                if (prev[cur] != -1) next[prev[cur]] = next[cur];
                if (next[cur] != -1) prev[next[cur]] = prev[cur];
            
                cur = (next[cur] != -1) ? next[cur] : prev[cur];
                
            }
            else{
                int restore = st.top();
                st.pop();
                if (prev[restore] != -1) next[prev[restore]] = restore;
                if (next[restore] != -1) prev[next[restore]] = restore;
            }
        }
    }
    
    string answer(n, 'O');
    while (!st.empty()) {
        answer[st.top()] = 'X';
        st.pop();
    }
    return answer;
}