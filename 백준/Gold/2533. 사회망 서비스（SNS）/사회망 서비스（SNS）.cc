#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int n;
vector<int> v[1000001];
int dp[1000001][2];
bool visited[1000001];

void find(int now){
    visited[now] = 1;
    dp[now][1] = 1;
    for(auto next : v[now]){
        if(!visited[next]){
            find(next);
            dp[now][1] += min(dp[next][1], dp[next][0]);
            dp[now][0] += dp[next][1]; 
        }
    }
}

int main(){
    cin >> n;
    // int maxans = 0;
    for(int i = 0; i < n-1; i++){
        int st, en;
        cin >> st >> en;
        // maxans = max(maxans, st);
        // maxans = max(maxans, en);
        v[st].push_back(en);
        v[en].push_back(st);
    }

    find(1);
    // for(int i = 1; i <= maxans; i++){
    //     cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    // }
    cout << min(dp[1][0], dp[1][1]);
}