#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[100001];

int solution(int n, vector<int> tops) {
    int answer = 0;
    dp[0] = 1;
    dp[1] = 3 + tops[0];
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] * (3 + tops[i - 1]) - dp[i - 2]) % 10007;
        if(dp[i] < 0){
            dp[i] += 10007;
        }
    }
    
    
    return dp[n];
}