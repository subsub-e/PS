#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cnt1, cnt2;
vector<vector<int>> MAP;

void func(int start_x, int start_y, int end_x, int end_y){
    if(start_x == end_x && start_y == end_y){
        if(MAP[start_x][start_y] == 1){
            cnt2++;
        }
        else{
            cnt1++;
        }
        return;
    }
    int flag1 = 0;
    int half_x = (start_x + end_x) / 2;
    int half_y = (start_y + end_y) / 2;
    for(int i = start_x; i <= end_x; i++){
        for(int j = start_y; j <= end_y; j++){
            if(MAP[start_x][start_y] != MAP[i][j]){
                flag1 = 1;
                break;
            }
        }
    }
    if(flag1 == 0){
        if(MAP[start_x][start_y] == 1){
            cnt2++;
        }
        else{
            cnt1++;
        }
        return;
    }
    else{
        func(start_x, start_y, half_x, half_y);
        func(half_x + 1, start_y, end_x, half_y);
        func(start_x, half_y + 1, half_x, end_y);
        func(half_x + 1, half_y + 1, end_x, end_y);
        return;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    MAP = arr;
    func(0, 0, arr.size() - 1, arr.size() - 1);
    answer.push_back(cnt1);
    answer.push_back(cnt2);
    return answer;
}