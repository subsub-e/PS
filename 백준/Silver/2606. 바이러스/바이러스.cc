#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int n, m;
vector<int> v[101];
bool visited[101];
int cnt = 0;

void dfs(int x){
    for(auto next : v[x]){
        if(!visited[next]){
            visited[next] = 1;
            cnt++;
            dfs(next);
        }
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }
    visited[1] = 1;
    dfs(1);
    cout << cnt;
    return 0;
}