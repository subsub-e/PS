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

int n;
int dp[10001];
int arr[10001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	dp[3] = max(dp[3], arr[1] + arr[2]);
	for(int i = 4; i <= n; i++){
		dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
		dp[i] = max(dp[i], dp[i-1]);
	}

	int maxans = 0;
	for(int i = 1; i <= n; i++){
		maxans = max(maxans, dp[i]);
	}

	cout << maxans;
	// for(int i = 1; i <= n; i++){
	// 	cout << dp[i] << ' ';
	// }

	return 0;
}