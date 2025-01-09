#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
vector<pair<int, int> > v[100001];
bool visited[10001];
int maxCost = 0;
int st, en;

bool bfs(int x){
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    visited[st] = 1;
    q.push(st);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(now == en){
            return true;
        }

        for(auto next : v[now]){
            if(!visited[next.first] && next.second >= x){
                q.push(next.first);
                visited[next.first] = 1;
            }
        }
    }
    return false;
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
        v[to].push_back(make_pair(from, cost));
        maxCost = max(maxCost, cost);
    }
    cin >> st >> en;

    int left = 0;
    int right = maxCost;

    while(left <= right){
        int mid = (left + right) / 2;
        if(bfs(mid)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << right << '\n';

}