#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    stack<char> s;
    int sum = 0;
    int temp = 1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' ){
            s.push(str[i]);
            temp *= 2;
        }
        else if(str[i] == ')'){
            if(s.empty() || s.top() != '('){
                sum = 0;
                break;
            }
            if(str[i - 1] == '('){
                sum += temp;
                temp /= 2;
                s.pop();
            }
            if(str[i - 1] != '('){
                temp /= 2;
                s.pop();
            }
        }
        else if(str[i] == '['){
            s.push(str[i]);
            temp *= 3;
        }
        else if(str[i] == ']'){
            if(s.empty() || s.top() != '['){
                sum = 0;
                break;
            }
            if(str[i - 1] == '['){
                sum += temp;
                temp /= 3;
                s.pop();
            }
            if(str[i - 1] != '['){
                temp /= 3;
                s.pop();
            }
        }
    }
    if(!s.empty()){
        cout << 0;
        return 0;
    }
    cout << sum;
    return 0;
}