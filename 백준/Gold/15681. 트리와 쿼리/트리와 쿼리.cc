#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int n, r, q;
int dp[100001];
vector<int> v[100001];
bool visited[100001];

void dfs(int x, int parent){
    visited[x] = 1;
    for(auto next : v[x]){
        if(!visited[next]){
            dfs(next, x);
        }
    }

    if(parent != -1){
        dp[parent] += dp[x];
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    fill_n(dp, 100001, 1);
    cin >> n >> r >> q;
    for(int i = 0; i < n-1; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    dfs(r, -1);

    for(int i = 0; i < q; i++){
        int x; cin >> x;
        cout << dp[x] << '\n';
    }
    return 0;
}