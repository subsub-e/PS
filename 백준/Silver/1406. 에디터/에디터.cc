#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> left;
    stack<char> right;
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        left.push(str[i]);
    }

    int n; cin >> n;
    while(n--){
        char c; cin >> c;
        if(c == 'L'){
            if(left.empty()){
                continue;
            }
            right.push(left.top());
            left.pop();
        }
        else if(c == 'D'){
            if(right.empty()){
                continue;
            }
            left.push(right.top());
            right.pop();
        }
        else if(c == 'B'){
            if(left.empty()){
                continue;
            }
            left.pop();
        }
        else{
            char x; cin >> x;
            left.push(x);
        }
    }

    string answer = "";
    string answer1 = "";
    while(!right.empty()){
        answer += right.top();
        right.pop();
    }
    while(!left.empty()){
        answer1 += left.top();
        left.pop();
    }

    reverse(answer1.begin(), answer1.end());
    cout << answer1 + answer;

    return 0;
}