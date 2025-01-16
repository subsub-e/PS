#include<iostream>
#include<algorithm>
using namespace std;

int arr[501][2];
int dp[501][501]; // start - end
const int INF = 2147483647;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int len = 1; len < N; ++len) {
		for (int s = 1; s + len <= N; ++s) {
			dp[s][s + len] = INF;
			for (int k = s; k <= s + len; ++k) {
				dp[s][s + len] = min(dp[s][s + len], dp[s][k] + dp[k+1][s + len] + arr[s][0] * arr[k + 1][0] * arr[s + len][1]);
			}
		}
	}
	
	cout << dp[1][N];
}