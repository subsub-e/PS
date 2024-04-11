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
long long dp[1001][10];
long long ans[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    cin >> n;
    for(int i = 0; i <= 9; i++){
        dp[1][i] = 1;
    }
    ans[1] = 10;

    for(int i = 2; i <= n; i++){
        dp[i][9] = 1;
        for(int j = 8; j >= 0; j--){
            dp[i][j] = (dp[i][j + 1] + dp[i-1][j]) % 10007;
        }
    }

    long long result = 0;
    for(int i = 0; i <= 9; i++){
        result += dp[n][i];
    }
    cout << result % 10007;

    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= 9; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(int i = 1; i <= n; i++){
    //     cout << ans[i] << ' ';
    // }
    // cout << '\n';
	return 0;
}