#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int k, v, e;
vector<int> t[20001];
bool visited[20001];
vector<pair<int, int> > ans;

void bfs(int x){
    visited[x] = 1;
    queue<pair<int, int> > q;
    q.push({x, 0});

    while(!q.empty()){
        int now = q.front().first;
        int color = q.front().second;
        ans.push_back({now, color % 2});
        q.pop();

        for(auto next : t[now]){
            if(!visited[next]){
                visited[next] = 1;
                q.push({next, color + 1});
            }
        }
    }
}

bool func(){
    for(int i = 1; i <= v; i++){
        for(auto next : t[i]){
            if(ans[i-1].second == ans[next-1].second){
                return false;
            }
        }
    }
    return true;
}

void solution(){
    for(int i = 1; i <= v; i++){
        t[i].clear();
    }
    ans.clear();
    memset(visited, 0, sizeof(visited));


    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        t[x].push_back(y);
        t[y].push_back(x);
    }

    for(int i = 1; i <= v; i++){
        if(!visited[i]){
            bfs(i);
        }
    }

    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i].first << ' ' << ans[i].second << '\n';
    // }

    sort(ans.begin(), ans.end());

    if(func()){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    while(k--){
        cin >> v >> e;
        solution();
    }

    return 0;
}
