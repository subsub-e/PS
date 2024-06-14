#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(pair<double, int> p1, pair<double, int> p2){
	if(p1.first == p2.first){
		return p1.second > p2.second;
	}
	return p1.first < p2.first;
}
int main() {
	int n; cin >> n;
	vector<pair<double, int> > v;
	for(int i = 0; i < n; i++){
		double x1, x2; cin >> x1 >> x2;
		double temp = floor(x1 * x2 * 10) / 10;
		v.push_back(make_pair(temp, i + 1));
	}
	sort(v.begin(), v.end(), comp);
	for(int i = v.size() - 1; i >= 0; i--){
		cout << v[i].second << ' ';
	}
	return 0;
}