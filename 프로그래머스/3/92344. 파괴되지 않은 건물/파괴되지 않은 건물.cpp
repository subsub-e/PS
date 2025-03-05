#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1005][1005];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for(auto s : skill){
        int x1 = s[1];
        int y1 = s[2];
        int x2 = s[3] + 1;
        int y2 = s[2];
        int x3 = s[1];
        int y3 = s[4] + 1;
        int x4 = s[3] + 1;
        int y4 = s[4] + 1;
        int target = s[5];
        if(s[0] == 1){
            dp[x1][y1] -= target;
            dp[x2][y2] += target;
            dp[x3][y3] += target;
            dp[x4][y4] -= target;
        }
        else{
            dp[x1][y1] += target;
            dp[x2][y2] -= target;
            dp[x3][y3] -= target;
            dp[x4][y4] += target;
        }
    }
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 1; j < board[i].size(); j++){
            dp[i][j] += dp[i][j-1];
        }
    }
    
    for(int i = 0; i < board[0].size(); i++){
        for(int j = 1; j < board.size(); j++){
            dp[j][i] += dp[j - 1][i];
        }
    }
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            board[i][j] += dp[i][j];
        }
    }
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] > 0){
                answer++;
            }
        }
    }
    
    return answer;
}