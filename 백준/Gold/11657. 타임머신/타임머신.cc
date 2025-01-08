#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
long long dist[510];
vector<pair<int, pair<int, int> > > v;
const int INF = 1e9 + 10;

int main(){
    cin >> n >> m;
    fill(dist + 1, dist + 1 + n, INF);

    for(int i = 0; i < m; i++){
        int from, to, d;
        cin >> from >> to >> d;
        v.push_back(make_pair(from, make_pair(to, d)));
    }

    dist[1] = 0;

    for(int i = 1; i <= n - 1; i++){
        for(int j = 0; j < v.size(); j++){
            int from = v[j].first;
            int to = v[j].second.first;
            int cost = v[j].second.second;

            if(dist[from] == INF){
                continue;
            }
            if(dist[to] > dist[from] + cost){
                dist[to] = dist[from] + cost;
            }
        }
    }

    for(int i = 0; i < v.size(); i++){
        int from = v[i].first;
        int to = v[i].second.first;
        int cost = v[i].second.second;
        if(dist[from] == INF){
            continue;
        }
        if(dist[to] > dist[from] + cost){
            cout << -1;
            return 0;
        }
    }

    for(int i = 2; i <= n; i++){
        if(dist[i] == INF){
            cout << -1 << '\n';
        }
        else{
            cout << dist[i] << '\n';
        }
    }
}