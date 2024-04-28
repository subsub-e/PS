#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

tuple<int, int, int> arr[200001];
int n, m;
int uf[200001];


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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while(1){
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		int cost_sum = 0;
		for(int i = 0; i < n; i++){
			uf[i] = i;
		}

		for(int i = 0; i < m; i++){
			int x, y, cost;
			cin >> x >> y >> cost;
			cost_sum += cost;
			arr[i] = make_tuple(cost, x, y);
		}

		sort(arr, arr + m);
		

		int sum = 0;

		for(int i = 0; i < m; i++){
			int x, y, cost;
			tie(cost, x, y) = arr[i];

			if(find(x) != find(y)){
				sum += cost;
				Union(x, y);
			}
		}

		cout << cost_sum - sum << '\n';
	}
	
	return 0;
}