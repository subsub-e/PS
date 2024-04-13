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
int dp[16][16];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        dp[i][1] = 1;
    }
    for(int i = 1; i <= m; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    if(k == 0){
        cout << dp[n][m];
    }
    else{
        k--;
        int x1 = k / m + 1;
        int y1 = k % m + 1;
        int temp = n * m - k - 1;
        int x2 = temp / m + 1;
        int y2 = temp % m + 1;
        cout << dp[x1][y1] * dp[x2][y2];
        //cout << dp[x1][y1] << ' ' << dp[x2][y2];
    }
    
	return 0;
}