#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v.push_back(x);
	}
	for(int i = 0; i < n; i++){
		if(v[i] % m != 0){
			v[i] *= m;
		}
	}
	for(int i = 0; i < n; i++){
		cout << v[i] << ' ';
	}
	return 0;
}