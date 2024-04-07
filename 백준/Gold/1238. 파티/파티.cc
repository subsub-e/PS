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

int n, m, t;
vector<pair<int, int> > v[1001];
int d[1001];
const int INF = 1e9-10;
int ans, ans1, ans2, result;

void func(int start, int x){
	fill(d, d + n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	d[start] = 0;
	pq.push(make_pair(d[start], start));

	while(!pq.empty()){
		int cur_x = pq.top().first;
		int cur_y = pq.top().second;
		pq.pop();

		if(cur_y == x){
			result = d[cur_y];
			break;
		}

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
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> t;
	

	for(int i = 0; i < m; i++){
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back(make_pair(cost, y));
	}



	for(int i = 1; i <= n; i++){
		func(t, i);
		ans1 = result;
		func(i, t);
		ans2 = result;
		if(ans < ans1 + ans2){
			ans = ans1 + ans2;
		}
	}
	cout << ans;

	return 0;
}