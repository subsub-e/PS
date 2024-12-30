#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int d[300001];
bool visited[300001];
int n, m, k, x;
vector<int> v[300001];
queue<int> q;
const int INF = 1e9 + 10;
vector<int> ans;


void bfs(){
    while(!q.empty()){
        int cur_x = q.front();
        q.pop();

        for(auto next : v[cur_x]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(next);
                d[next] = d[cur_x] + 1;
            }
        }
    }
}

int main(){
    cin >> n >> m >> k >> x;

    fill(d, d + n + 1, INF);

    while(m--){
        int st, en;
        cin >> st >> en;
        v[st].push_back(en);
    }

    visited[x] = 1;
    q.push(x);
    d[x] = 0;

    bfs();

    for(int i = 1; i <= n; i++){
        if(d[i] == k){
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());

    if(ans.size() == 0){
        cout << -1;
    }
    else{
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << '\n';
        }
    }
}   