#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v.push_back(x);
	}
	
	int temp = 0;
	int sum = 0;
	while(m--){
		sum += v[temp] % n;
		temp = (v[temp] + temp) % n;
	}
	cout << v[temp];
	return 0;
}