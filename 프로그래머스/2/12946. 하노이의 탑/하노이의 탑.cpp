#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int go, int des, vector<vector<int>>& answer){
    if(n == 1){
        answer.push_back({go, des});
        return;
    }
    
    hanoi(n-1, go, 6 - go - des, answer);
    hanoi(1, go, des, answer);
    hanoi(n-1, 6 - go - des, des, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(n, 1, 3, answer);
    return answer;
}