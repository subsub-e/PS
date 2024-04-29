#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;


int n, m;
int s, e;
int uf[100001];
tuple<int, int, int> arr[300001];
vector<pair<int, int> > v[300001];
bool visited[100001];
int dist[100001];
const int INF = 987654321;

int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X != Y){
        uf[X] = Y;
    }
}

void bfs(){
    fill(dist, dist + 100000, INF);

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto next : v[cur]){
            if(!visited[next.second]){
                visited[next.second] = 1;
                dist[next.second] = min(dist[cur], next.first);
                q.push(next.second);
            }
        }
    }

    if(dist[e] == INF){
        cout << 0;
    }
    else{
        cout << dist[e];
    }

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> s >> e;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    for(int i = 0; i < m; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        arr[i] = make_tuple(cost, x, y);
    }

    sort(arr, arr + m, greater<tuple<int, int, int> > ());

    for(int i = 0; i < m; i++){
        int x, y, cost;
        tie(cost, x, y) = arr[i];
        if(find(x) != find(y)){
            Union(x, y);
            v[x].push_back(make_pair(cost, y));
            v[y].push_back(make_pair(cost, x));
        }
    }

    bfs();
	return 0;
}