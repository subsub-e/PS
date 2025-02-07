#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

long long dp[500001][2];
long long maxans = INT_MIN;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    dp[0][0] = sequence[0] * -1;
    dp[0][1] = sequence[0] * 1;
    if(maxans < dp[0][0]){
        maxans = dp[0][0];
    }
    if(maxans < dp[0][1]){
        maxans = dp[0][1];
    }
    
    
    for(int i = 1; i < sequence.size(); i++){
        if(dp[i-1][1] > 0){
            dp[i][0] = dp[i-1][1] + sequence[i] * -1;
        }
        else{
            dp[i][0] = sequence[i] * -1;
        }
        if(dp[i-1][0] > 0){
            dp[i][1] = dp[i-1][0] + sequence[i];
        }
        else{
            dp[i][1] = sequence[i];
        }
        if(maxans < dp[i][0]){
            maxans = dp[i][0];
        }
        if(maxans < dp[i][1]){
            maxans = dp[i][1];
        }
    }
    
    // for(int i = 0; i < sequence.size(); i++){
    //     cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    // }
    
    return maxans;
}