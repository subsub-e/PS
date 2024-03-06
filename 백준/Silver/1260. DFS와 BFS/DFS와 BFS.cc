#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int n, m, start;
vector<int> v[1001];
bool visited_bfs[1001];
bool visited_dfs[1001];
queue<int> q;

void dfs(int x){
    cout << x << ' ';
    visited_dfs[x] = 1;
    for(auto next : v[x]){
        if(!visited_dfs[next]){
            dfs(next);
        }
    }
}


void bfs(){
    while(!q.empty()){
        int x = q.front();
        cout << x << ' ';
        q.pop();

        for(auto next1 : v[x]){
            if(!visited_bfs[next1]){
                visited_bfs[next1] = 1;
                q.push(next1);
            }
        }
    }
}


int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> start;
    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }

    dfs(start);
    cout << '\n';
    q.push(start);
    visited_bfs[start] = 1;
    bfs();
    
    return 0;
}