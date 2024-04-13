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

int n, k;
int arr1[21];
int arr2[21];
int dp[21][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        cin >> arr1[i] >> arr2[i];
    }
    cin >> k;

    for(int i = 0; i <= n; i++){
        fill(dp[i], dp[i] + 2, 100001);
    }
    

    dp[1][0] = 0;
    dp[2][0] = arr1[1];
    dp[3][0] = min(dp[2][0] + arr1[2], dp[1][0] + arr2[1]);
    for(int i = 4; i <= n; i++){
        dp[i][0] = min(dp[i-1][0] + arr1[i-1], dp[i-2][0] + arr2[i-2]);
        dp[i][1] = min(dp[i-1][1] + arr1[i-1], dp[i-2][1] + arr2[i-2]);
        dp[i][1] = min(dp[i][1], dp[i-3][0] + k);
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < 2; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << min(dp[n][0], dp[n][1]);
    
	return 0;
}