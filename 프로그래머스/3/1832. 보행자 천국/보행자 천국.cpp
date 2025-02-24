#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int MOD = 20170805;
int dp[501][501][2];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(dp, 0, sizeof(dp));
    dp[1][1][0] = dp[1][1][1] = 1;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(city_map[i][j] == 0){
                dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i + 1][j][1] + dp[i][j + 1][0]) % MOD;
                dp[i + 1][j + 1][1] = (dp[i + 1][j + 1][1] + dp[i + 1][j][1] + dp[i][j + 1][0]) % MOD;
            }
            else if(city_map[i][j] == 1){
                dp[i + 1][j + 1][0] = dp[i + 1][j + 1][1] = 0;
            }
            else{
                dp[i + 1][j + 1][0] = dp[i][j + 1][0] % MOD;
                dp[i + 1][j + 1][1] = dp[i + 1][j][1] % MOD;
            }
        }
    }
    
    
    return dp[m][n][0] % MOD;
}