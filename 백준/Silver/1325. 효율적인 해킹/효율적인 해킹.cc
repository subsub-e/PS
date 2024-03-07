#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <climits>

using namespace std;
int n, m;
vector<int> v[10001];
queue<int> q;
vector<pair<int, int> > ans;
bool visited[10001];


void bfs(int x){
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }
    visited[x] = 1;
    q.push(x);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto next : v[now]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(next);
            }
        }
    }

    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i] && x != i){
            sum++;
        }
    }
    ans.push_back(make_pair(x, sum));
    return;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x2].push_back(x1);
    }

    for(int i = 1; i <= n; i++){
        bfs(i);
    }

    int maxans = 0;
    for(int i = 0; i < ans.size(); i++){
        maxans = max(maxans, ans[i].second);
    }

    for(int i = 0; i < ans.size(); i++){
        if(maxans == ans[i].second){
            cout << i+1 << ' ';
        }
    }
    return 0;
}