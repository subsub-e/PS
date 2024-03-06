#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <climits>

using namespace std;

int n;
bool visited[51];
vector<int> v[51];
vector<pair<int, int> > ans;


void bfs(int x){
    queue<pair<int, int> > q;
    for(int i = 0; i <= n; i++){
        visited[i] = 0;
    }
    visited[x] = 1;
    q.push(make_pair(x, 0));
    int tot = 0;

    while(!q.empty()){
        int now = q.front().first;
        int level = q.front().second;
        q.pop();
        tot = max(tot, level);
        
        for(auto next : v[now]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(make_pair(next, level + 1));
            }
        }
    }

    ans.push_back(make_pair(x, tot));
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
    cin >> n;
    while(1){
        int x1, x2;
        cin >> x1 >> x2;
        if(x1 == -1 && x2 == -1){
            break;
        }
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }
    
    for(int i = 1; i <= n; i++){
        bfs(i);
    }

    int min_level = INT_MAX;
    for(int i = 0; i < ans.size(); i++){
        min_level = min(min_level, ans[i].second);
    }

    int sum = 0;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i].second == min_level){
            sum++;
        }
    }
    cout << min_level << ' ' << sum << '\n';
    for(int i = 0; i < ans.size(); i++){
        if(ans[i].second == min_level){
            cout << ans[i].first << ' ';
        }
    }
    return 0;
}