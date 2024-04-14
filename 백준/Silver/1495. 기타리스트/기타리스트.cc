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

int n, m, k;
int dp[55][1005];
int arr[51];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < 55; i++){
		fill(dp[i], dp[i] + 1005, -1);
	}

	dp[0][m] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			if(dp[i-1][j] > 0){
				//cout << i-1 << ' ' << j << '\n';
				if(j + arr[i] <= k){
					dp[i][j + arr[i]] = dp[i-1][j] + 1;
				}
				if(j - arr[i] >= 0){
					dp[i][j - arr[i]] = dp[i-1][j] + 1;
				}
			}
		}
	}

	int maxans = -1;
	for(int i = 0; i <= k; i++){
		if(dp[n][i] > 0){
			maxans = max(maxans, i);
		}
	}
	if(maxans == -1){
		cout << -1;
	}
	else{
		cout << maxans;
	}
	return 0;
}