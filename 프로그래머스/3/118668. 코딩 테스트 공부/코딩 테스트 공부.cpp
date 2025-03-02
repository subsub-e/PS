#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[151][151];
const int INF = 1e9 + 10;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    for(int i = 0; i <= 150; i++){
        for(int j = 0; j <= 150; j++){
            dp[i][j] = INF;
        }
    }
    
    int max_alp = -1;
    int max_cop = -1;
    
    for(int i = 0; i < problems.size(); i++){
        for(int j = 0; j < 5; j++){
            max_alp = max(max_alp, problems[i][0]);
            max_cop = max(max_cop, problems[i][1]);
        }
    }
    
    if(alp > max_alp){
        alp = max_alp;
    }
    if(cop > max_cop){
        cop = max_cop;
    }
    
    dp[alp][cop] = 0;
    
    for(int i = alp; i <= max_alp; i++){
        for(int j = cop; j <= max_cop; j++){
            if(j + 1 <= max_cop){
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }
            if(i + 1 <= max_alp){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            
            for(int k = 0; k < problems.size(); k++){
                if(i >= problems[k][0] && j >= problems[k][1]){
                    dp[min(i + problems[k][2], max_alp)][min(j + problems[k][3], max_cop)] = min(dp[min(i + problems[k][2], max_alp)][min(j + problems[k][3], max_cop)], dp[i][j] + problems[k][4]);
                }
            }
        }
    }
    
    return dp[max_alp][max_cop];
}