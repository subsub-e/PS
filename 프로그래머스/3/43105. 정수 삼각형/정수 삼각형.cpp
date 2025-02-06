#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        dp[i][triangle[i].size() - 1] = dp[i-1][triangle[i].size() - 2] + triangle[i][triangle[i].size() - 1];
        for(int j = 1; j < triangle[i].size() - 1; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    for(int i = 0; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            //cout << dp[i][j] << ' ';
            answer = max(answer, dp[i][j]);
        }
        //cout << '\n';
    }
    
    
    return answer;
}