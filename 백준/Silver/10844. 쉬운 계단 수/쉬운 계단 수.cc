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

int dp[101][10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

	for(int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}

	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++){
			if(j == 0){
				dp[i][j] = dp[i-1][j + 1];
			}
			else if(j == 9){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j + 1];
			}
			dp[i][j] = dp[i][j] % 1000000000;
		}
	}

	int ans = 0;
	for(int i = 0; i <= 9; i++){
		ans = (ans + dp[n][i]) % 1000000000;
		//ans += dp[n][i];
	}

	cout << ans;

	return 0;
}