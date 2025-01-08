#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
long long dist[502];
const int INF = 1e9 + 10;

int main(){
    cin >> t;
    while(t--){
        int n, m, w;
        cin >> n >> m >> w;
        fill(dist + 1, dist + n + 1, INF);

        vector<pair<int, pair<int, int> > > v;

        for(int i = 0; i < m; i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            v.push_back(make_pair(from, make_pair(to, cost)));
            v.push_back(make_pair(to, make_pair(from, cost)));
        }

        for(int i = 0; i < w; i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            v.push_back(make_pair(from, make_pair(to, -cost)));
        }

        dist[1] = 0;

        for(int i = 1; i <= n-1; i++){
            for(int j = 0; j < (int) v.size(); j++){
                int from = v[j].first;
                int to = v[j].second.first;
                int cost = v[j].second.second;
            
                if(dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                }
            }
        }

        int flag = 0;
        for(int i = 0; i < (int) v.size(); i++){
            int from = v[i].first;
            int to = v[i].second.first;
            int cost = v[i].second.second;
                
            if(dist[from] == INF){
                continue;
            }
            if(dist[to] > dist[from] + cost){
                cout << "YES" << '\n';
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "NO" << '\n';
        }
    }
}