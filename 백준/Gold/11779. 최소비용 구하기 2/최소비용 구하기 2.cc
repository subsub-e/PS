#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int> > v[1001];
int st, en;
int d[1001];
int pre[1001];
const int INF = 1e9+10;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    fill(d, d + 1 + n, INF);
    while(m--){
        int x, y, cost;
        cin >> x >> y >> cost;
        v[x].push_back(make_pair(cost, y));
    }

    cin >> st >> en;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    d[st] = 0;
    pq.push(make_pair(d[st], st));
    while(!pq.empty()){
        int cur_x = pq.top().first;
        int cur_y = pq.top().second;
        pq.pop();

        if(d[cur_y] != cur_x){
            continue;
        }

        for(auto next : v[cur_y]){
            if(d[next.second] <= d[cur_y] + next.first){
                continue;
            }
            d[next.second] = d[cur_y] + next.first;
            pq.push(make_pair(d[next.second], next.second));
            pre[next.second] = cur_y;
        }
    }


    cout << d[en] << '\n';
    vector<int> path;
    int cur = en;
    while(cur != st){
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    cout << path.size() << '\n';
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << ' ';
    }

	return 0;
}