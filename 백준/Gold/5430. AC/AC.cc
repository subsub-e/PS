#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    while(n--){
        deque<int> dq;
        string str;
        cin >> str;
        int m; cin >> m;
        string temp; cin >> temp;
        string digit = "";
        if(m != 0){
            for(int i = 0; i < temp.length(); i++){
                if(temp[i] == ',' || temp[i] == ']'){
                    dq.push_back(stoi(digit));
                    digit = "";
                    continue;
                }
                if(isdigit(temp[i])){
                    digit += temp[i];
                }
            }
        }
        

        

        int flag = 0;
        int error = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'R'){
                flag = abs(flag - 1);
            }
            else{
                if(dq.empty()){
                    error = 1;
                    break;
                }
                if(flag == 1){
                    dq.pop_back();
                }
                else{
                    dq.pop_front();
                }
            }
        }

        if(error == 1){
            cout << "error" << '\n';
        }
        else{
            if(dq.size() == 0){
                cout << "[]";
                cout << '\n';
                continue;
            }
            if(flag == 1){
                cout << '[';
                while(dq.size() > 1){
                    cout << dq.back() << ',';
                    dq.pop_back();
                }
                cout << dq.back() << ']';
                dq.pop_back();
            }
            else{
                cout << '[';
                while(dq.size() > 1){
                    cout << dq.front() << ',';
                    dq.pop_front();
                }
                cout << dq.front() << ']';
                dq.pop_back();
            }
            cout << '\n';
        }
    }

    return 0;
}