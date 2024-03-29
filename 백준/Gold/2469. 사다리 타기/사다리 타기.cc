#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> start;
    vector<int> finish;
    char arr[m][n - 1];
    for(int i = 0; i < n; i++){
        start.push_back(i);
    }
    for(int i = 0; i < n; i++){
        char x; cin >> x;
        finish.push_back((int) x - 'A');
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n - 1; j++){
            char c; cin >> c;
            arr[i][j] = c;
        }
    }

    int change;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n - 1; j++){
            if(arr[i][j] == '?'){
                change = i;
                break;
            }
        }
    }

    for(int i = 0; i < change; i++){
        for(int j = 0; j < n - 1; j++){
            if(arr[i][j] == '-'){
                swap(start[j], start[j + 1]);
            }
        }
    }

    for(int i = m - 1; i > change; i--){
        for(int j = 0; j < n - 1; j++){
            if(arr[i][j] == '-'){
                swap(finish[j], finish[j + 1]);
            }
        }
    }

    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n - 1; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for(int i = 0; i < start.size(); i++){
    //     cout << (char)(start[i] + (int)'a') << ' ';
    // }
    // cout << '\n';

    // for(int i = 0; i < finish.size(); i++){
    //     cout << (char)(finish[i] + (int)'a') << ' ';
    // }
    // cout << '\n';

    string ans = "";
    char ppp;
    for(int i = 0; i < start.size() - 1; i++){
        if(start[i] == finish[i]){
            ans += '*';
        }
        else{
            if(start[i + 1] == finish[i] && start[i] == finish[i + 1]){
                swap(start[i], start[i + 1]);
                ans += '-';
            }
            else{
                //cout << i << '\n';
                for(int i = 0; i < start.size() - 1; i++){
                    cout << 'x';
                }
                return 0;
            }
        }
    }

    cout << ans;

    return 0;
}