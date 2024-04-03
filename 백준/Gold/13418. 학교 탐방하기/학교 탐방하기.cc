#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

vector<pair<int, pair<int, int> > > v1;
vector<pair<int, pair<int, int> > > v2;
int n, m;
int uf1[1001];
int uf2[1001];

int find1(int x){
	if(uf1[x] == x){
		return x;
	}
	return uf1[x] = find1(uf1[x]); 
}

int find2(int x){
	if(uf2[x] == x){
		return x;
	}
	return uf2[x] = find2(uf2[x]); 
}

void Union1(int x, int y){
	int X = find1(x);
	int Y = find1(y);
	uf1[X] = Y;
}

void Union2(int x, int y){
	int X = find2(x);
	int Y = find2(y);
	uf2[X] = Y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
	for(int i = 1; i <= n; i++){
		uf1[i] = i;
		uf2[i] = i;
	}

	for(int i = 0; i <= m; i++){
		int x1, x2, cost;
		cin >> x1 >> x2 >> cost;
		v1.push_back(make_pair(cost, make_pair(x1, x2)));
		v2.push_back(make_pair(cost, make_pair(x1, x2)));
	}

	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());

	int minans = 0;
	int maxans = 0;

	int index = 0;
	for(int i = 0; i <= m; i++){
		int cost = v1[i].first;
		int x = v1[i].second.first;
		int y = v1[i].second.second;
		if(find1(x) != find1(y)){
			if(cost == 0){
				index++;
				maxans = index * index;
			}
			Union1(x, y);
		}
	}

	index = 0;

	for(int i = 0; i <= m; i++){
		int cost = v2[i].first;
		int x = v2[i].second.first;
		int y = v2[i].second.second;
		if(find2(x) != find2(y)){
			if(cost == 0){
				index++;
				minans = index * index;
			}
			Union2(x, y);
		}
	}

	cout << maxans - minans;
	return 0;
}