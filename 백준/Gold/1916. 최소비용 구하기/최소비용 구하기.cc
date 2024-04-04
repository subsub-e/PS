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
int d[1001];
int st, en;
const int INF = 1e9+10;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    fill(d, d + n + 1, INF);

    while(m--){
        int x, y, cost;
        cin >> x >> y >> cost;
        v[x].push_back(make_pair(cost, y));
    }

    cin >> st >> en;
    d[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(d[st], st));

    while(!pq.empty()){
        int cur_x = pq.top().first;
        int cur_y = pq.top().second;
        pq.pop();

        if(d[cur_y] != cur_x){
            continue;
        }

        for(auto next : v[cur_y]){
            if(d[next.second] <= next.first + d[cur_y]){
                continue;
            }
            d[next.second] = next.first + d[cur_y];
            pq.push(make_pair(d[next.second], next.second));
        }
    }

    cout << d[en];
	return 0;
}