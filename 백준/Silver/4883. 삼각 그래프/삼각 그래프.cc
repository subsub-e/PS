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



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int index = 1;
	while(1){
		int m; cin >> m;
		if(m == 0){
			break;
		}
		int arr[100001][3] = {};
		int dp[100001][3] = {};
		for(int i = 1; i <= m; i++){
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		}

		dp[1][0] = INT_MAX;
		dp[1][1] = arr[1][1];
		dp[1][2] = arr[1][1] + arr[1][2];
		for(int i = 2; i <= m; i++){
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + arr[i][0];
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
			dp[i][1] = min(dp[i][1], dp[i-1][1]);
			dp[i][1] = min(dp[i][1], dp[i][0]) + arr[i][1];
			dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
			dp[i][2] = min(dp[i][2], dp[i][1]) + arr[i][2];
		}

		// for(int i = 1; i <= m; i++){
		// 	cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
		// }

		cout << index << '.' << ' ' << dp[m][1] << '\n';
		index++;
	}
    
	return 0;
}