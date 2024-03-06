#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<int> v[20001];
bool visited[20001];
queue<pair<int, int> > q;
vector<pair<int, int> > ans;

void bfs(){
    while(!q.empty()){
        int now = q.front().first;
        int level = q.front().second;
        ans.push_back(make_pair(now, level));
        q.pop();

        for(auto next : v[now]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(make_pair(next, level + 1));
            }
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

    q.push(make_pair(1, 0));
    visited[1] = 1;
    bfs();

    sort(ans.begin(), ans.end());

    int maxans = 0;
    for(int i = 0; i < ans.size(); i++){
        maxans = max(maxans, ans[i].second);
    }

    int sum = 0;
    for(int i = 0; i < ans.size(); i++){
        if(maxans == ans[i].second){
            sum++;
        }
    }

    for(int i = 0; i < ans.size(); i++){
        if(maxans == ans[i].second){
            cout << i + 1 << ' ' << maxans << ' ' << sum << '\n';
            return 0;
        }
    }
    return 0;
}