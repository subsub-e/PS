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

int dp[1001][3];
int arr[1001][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    //cout << arr[2][0] << ' ' << arr[2][1] << ' ' << arr[2][2];
    
    dp[1][0] = arr[1][0];
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];

    for(int i = 2; i <= 1000; i++){
        dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    sum = min(dp[n][0], dp[n][1]);
    sum = min(sum, dp[n][2]);

    cout << sum;


	return 0;
}