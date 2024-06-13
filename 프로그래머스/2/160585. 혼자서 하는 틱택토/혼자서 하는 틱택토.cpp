#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 'O'){
                sum1++;
            }
            if(board[i][j] == 'X'){
                sum2++;
            }
        }
    }
    int flag1 = 0;
    int flag2 = 0;
    for(int i = 0; i < 3; i++){
        if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O'){
            flag1 = 1;
        }
        if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O'){
            flag1 = 1;
        }
    }
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
        flag1 = 1;
    }
    if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
        flag1 = 1;
    }
    
    for(int i = 0; i < 3; i++){
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X'){
            flag2 = 1;
        }
        if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X'){
            flag2 = 1;
        }
    }
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
        flag2 = 1;
    }
    if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
        flag2 = 1;
    }
    
    if(flag1 == 1){
        if(sum1 == sum2){
            answer = 0;
        }
    }
    if(flag2 == 1){
        if(sum1 != sum2){
            answer = 0;
        }
    }
    if(sum1 - sum2 != 0 && sum1 - sum2 != 1){
        answer = 0;
    }
    return answer;
}