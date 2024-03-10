#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    int n; cin >> n;
    stack<char> l;
    stack<char> r;

    for(int i = 0; i < str.length(); i++){
        l.push(str[i]);
    }

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'L'){
            if(l.size() == 0){
                continue;
            }
            r.push(l.top());
            l.pop();
        }
        else if(c == 'D'){
            if(r.size() == 0){
                continue;
            }
            l.push(r.top());
            r.pop();
        }
        else if(c == 'B'){
            if(l.size() == 0){
                continue;
            }
            l.pop();
        }
        else if(c == 'P'){
            char sub_c;
            cin >> sub_c;
            l.push(sub_c);
        }
    }
    string ans = "";
    while(!l.empty()){
        ans += l.top();
        l.pop();
    }
    for(int i = ans.length() - 1; i >= 0; i--){
        cout << ans[i];
    }
    while(!r.empty()){
        cout << r.top();
        r.pop();
    }
    return 0;
}