#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


int n, m, cnt;
string str;
stack<char> s;

int main(){
    cin >> n >> m >> str;
    for(int i = 0; i < str.length(); i++){

        while(!s.empty() && s.top() < str[i] && cnt < m){
            s.pop();
            cnt++;
        }
        s.push(str[i]);
        
    }

    while(cnt != m){
        s.pop();
        cnt++;
    }
    vector<char> v;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << v[i];
    }
}