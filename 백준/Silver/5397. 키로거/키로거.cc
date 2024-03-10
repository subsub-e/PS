#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        stack<char> l;
        stack<char> r;
        for(int j = 0; j < str.length(); j++){
            if(str[j] == '<'){
                if(l.empty()){
                    continue;
                }
                r.push(l.top());
                l.pop();
            }
            else if(str[j] == '>'){
                if(r.empty()){
                    continue;
                }
                l.push(r.top());
                r.pop();
            }
            else if(str[j] == '-'){
                if(l.empty()){
                    continue;
                }
                l.pop();
            }
            else{
                l.push(str[j]);
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
        cout << '\n';
    }
    return 0;
}