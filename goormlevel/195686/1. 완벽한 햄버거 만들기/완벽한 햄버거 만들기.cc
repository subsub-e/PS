#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> v;
	int maxans = 0;
	int sum = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		maxans = max(maxans, x);
		sum += x;
		v.push_back(x);
	}
	
	int index = find(v.begin(), v.end(), maxans) - v.begin();
	int flag = 0;
	
	if(index != 0){
		for(int i = index; i >= 0; i--){
			if(v[i] < v[i-1]){
				flag = 1;
				break;
			}
		}
	}
	
	
	if(index != v.size() - 1){
		for(int i = index + 1; i < v.size(); i++){
			if(v[i] < v[i + 1]){
				flag = 1;
				break;
			}
		}
	}
	
	if(flag == 1){
		cout << 0;
	}
	else{
		cout << sum;
	}
	return 0;
}