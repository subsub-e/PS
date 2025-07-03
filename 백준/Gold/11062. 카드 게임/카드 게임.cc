#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T, N, arr[1001], dp[1001][1001];

int CardGame(int left, int right, int turn) {
	if (left > right) return 0;
	if (dp[left][right]) return dp[left][right];

	if (turn % 2) // 근우 차례
	   return dp[left][right] = max(arr[left] + CardGame(left + 1, right, turn + 1), arr[right] + CardGame(left, right - 1, turn + 1));
	else // 명우 차례 
	   return dp[left][right] = min(CardGame(left + 1, right, turn + 1), CardGame(left, right - 1, turn + 1));
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int n = 0; n < N; n++) cin >> arr[n];
		CardGame(0, N - 1, 1);
		cout << dp[0][N - 1] << "\n";
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}