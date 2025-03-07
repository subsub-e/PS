#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>
#include <cmath>
using namespace std;

int n;
vector<int> v[1000001];
bool visited[1000001];
int dp[1000001][2];
const int INF = 1e9 + 10;

void dfs(int now){
    visited[now] = 1;
    dp[now][0] = 0;
    dp[now][1] = 1;

    for(auto next : v[now]){
        if(!visited[next]){
            visited[next] = 1;
            dfs(next);

            dp[now][0] += dp[next][1];
            dp[now][1] += min(dp[next][0], dp[next][1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i <= n; i++){
        dp[i][0] = INF;
        dp[i][1] = INF;
    }
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]);

    return 0;
}
