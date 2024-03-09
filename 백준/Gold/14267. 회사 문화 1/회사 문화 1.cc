#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n, m;
vector<int> v[100001];
int sum[100001];

void dfs(int cur){
    for(auto next : v[cur]){
        sum[next] += sum[cur];
        dfs(next);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x == -1){
            continue;
        }
        v[x].push_back(i);
    }

    for(int i = 0; i < m; i++){
        int x1, x2; cin >> x1 >> x2;
        sum[x1] += x2;
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
        cout << sum[i] << ' ';
    }
    return 0;
}