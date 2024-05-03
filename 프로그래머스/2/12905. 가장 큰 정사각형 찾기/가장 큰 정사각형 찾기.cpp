#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int>> board)
{   
    
    for(int i = 1; i < board.size(); i++){
        for(int j = 1; j < board[i].size(); j++){
            if(board[i][j] == 1){
                board[i][j] = min(min(board[i-1][j], board[i][j-1]), board[i-1][j-1]) + 1;
            }
        }
    }
    
    int maxans = 0;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            maxans = max(maxans, board[i][j]);
        }
    }

    return maxans * maxans;
}