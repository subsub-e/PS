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

int n, m, st;
vector<pair<int, int> > v[20001];
int d[20001];
const int INF = 1e9+10;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> st;
	fill(d, d + n + 1, INF);

	while(m--){
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back(make_pair(cost, y));
	}

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
		}
	}

	for(int i = 1; i <= n; i++){
		if(d[i] == INF){
			cout << "INF\n";
		}
		else{
			cout << d[i] << '\n';
		}
	}
	return 0;
}