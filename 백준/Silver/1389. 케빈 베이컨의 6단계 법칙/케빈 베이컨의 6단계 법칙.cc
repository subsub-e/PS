#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<int> v[101];
bool visited[101];
vector<int> ans;


void bfs(int x){
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    queue<pair<int, int> > q;
    visited[x] = 1;
    q.push(make_pair(x, 0));
    int sum = 0;
    while(!q.empty()){
        int now = q.front().first;
        int level = q.front().second;
        q.pop();
        sum += level;
        for(auto next : v[now]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(make_pair(next, level + 1));
            }
        }
    }

    ans.push_back(sum);
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

    for(int i = 1; i <= n; i++){
        bfs(i);
    }

    int minans = INT_MAX;
    for(int i = 0; i < ans.size(); i++){
        //cout << ans[i] << '\n';
        minans = min(minans, ans[i]);
    }

    for(int i = 0; i < ans.size(); i++){
        if(minans == ans[i]){
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}