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
using namespace std;

int n;
int arr[12];
int plu, minu, sca, divi;
int maxans = INT_MIN;
int minans = INT_MAX;

void func(int depth, int sum){
	if(depth == n){
		minans = min(minans, sum);
		maxans = max(maxans, sum);
		return;
	}

	if(plu > 0){
		plu--;
		func(depth + 1, sum + arr[depth]);
		plu++;
	}
	if(minu > 0){
		minu--;
		func(depth + 1, sum - arr[depth]);
		minu++;
	}
	if(sca > 0){
		sca--;
		func(depth + 1, sum * arr[depth]);
		sca++;
	}
	if(divi > 0){
		divi--;
		func(depth + 1, sum / arr[depth]);
		divi++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cin >> plu >> minu >> sca >> divi;

	func(1, arr[0]);

	cout << maxans << '\n' << minans;

	return 0;
}