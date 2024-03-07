#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <climits>

using namespace std;

int t;
int n, m;
vector<int> v[20001];
bool visited[20001];
vector<pair<int, int> > ans;

void bfs(int x){
    queue<pair<int,int> > q;
    int red = 1;
    q.push(make_pair(x, red));
    visited[x] = 1;

    while(!q.empty()){
        int now = q.front().first;
        int color = q.front().second;
        ans.push_back(make_pair(now, color % 2));
        q.pop();

        for(auto next : v[now]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(make_pair(next, color + 1));
            }
        }
    }
    return;
}

bool func(){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < (int) v[i].size(); j++){
            int next = v[i][j];
            if(ans[i - 1].second == ans[next - 1].second){
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
    
    cin >> t;
    for(int i = 0; i < t; i++){
        
        cin >> n >> m;
        for(int j = 0; j <= n; j++){
            visited[j] = 0;
        }
        
        for(int j = 0; j < m; j++){
            int x1, x2; cin >> x1 >> x2;
            v[x1].push_back(x2);
            v[x2].push_back(x1);
        }

        for(int j = 1; j <= n; j++){
            if(!visited[j]){
                bfs(j);
            }
        }

        sort(ans.begin(), ans.end());

        if(func()){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }

        ans.clear();
        for(int j = 0; j <= n; j++){
            v[j].clear();
        }
    }
    return 0;
}