#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1e9 + 10;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int dp[info.size() + 1][m];
    for(int i = 0; i <= info.size(); i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= info.size(); i++){
        int a = info[i-1][0];
        int b = info[i-1][1];
        
        for(int j = 0; j < m; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j] + a);
            
            if(b + j < m){
                dp[i][j + b] = min(dp[i][j + b], dp[i-1][j]);
            }
        }
    }
    
    int minans = INF;
    
    for(int i = 0; i < m; i++){
        //cout << dp[info.size()][i] << ' ';
        minans = min(minans, dp[info.size()][i]);
    }
    
    if(minans >= n){
        return -1;
    }
    return minans;
}