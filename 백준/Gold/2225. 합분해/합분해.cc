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

int n, m;
int dp[201][201];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        dp[i][1] = i;
    }
    for(int i = 1; i <= n; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= m; i++){
        for(int j = 2; j <= n; j++){
            dp[i][j] = (dp[i - 1][j] % 1000000000 + dp[i][j - 1] % 1000000000) % 1000000000;
        }
    }
    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[m][n];
	return 0;
}