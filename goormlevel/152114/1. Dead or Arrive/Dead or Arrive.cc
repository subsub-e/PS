#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;


int main() {
	int n; cin >> n;
	vector<tuple<int, int, int> > v;
	for(int i = 0; i < n; i++){
		int x1, x2; cin >> x1 >> x2;
		v.push_back(make_tuple(x1, x2, i + 1));
	}
	sort(v.begin(), v.end());
	
	int temp;
	int sum = 0;
	for(int i = v.size() - 1; i >= 0; i--){
		int x1, x2, x3;
		tie(x1, x2, x3) = v[i];
		if(i == v.size() - 1){
			temp = x1;
			sum += x3;
			continue;
		}
		if(temp != x1){
			sum += x3;
			temp = x1;
		}
	}
	cout << sum;
	return 0;
}