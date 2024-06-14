#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int calc(int x){
	int temp = 1;
	while(x > 0){
		temp *= (x % 10);
		x /= 10;
	}
	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x; cin >> x;
	if(x < 10){
		cout << x;
	}
	else{
		vector<int> v;
		while(x > 0){
			v.push_back(x % 10);
			x /= 10;
		}
		reverse(v.begin(), v.end());
		int temp = 0;
		int maxans = 0;
		for(int i = 0; i < v.size() - 1; i++){
			temp += v[i] * pow(10, v.size() - i - 1);
			maxans = max(maxans, calc(temp - 1));
			//cout << temp << '\n';
		}
		maxans = max(maxans, calc(temp + v[v.size() - 1]));
		cout << maxans;
	}
	return 0;
}