#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int arr[101][101];
int minans = 1000001;

void func(int start_x, int start_y, int end_x, int end_y){
    int temp = arr[start_x][end_y];
    
    for(int i = end_y; i > start_y; i--){
        arr[start_x][i] = arr[start_x][i - 1];
        minans = min(minans, arr[start_x][i - 1]);
    }
    for(int i = start_x; i < end_x; i++){
        arr[i][start_y] = arr[i + 1][start_y];
        minans = min(minans,  arr[i + 1][start_y]);
    }
    for(int i = start_y; i < end_y; i++){
        arr[end_x][i] = arr[end_x][i + 1];
        minans = min(minans,  arr[end_x][i + 1]);
    }
    for(int i = end_x; i > start_x; i--){
        arr[i][end_y] = arr[i-1][end_y];
        minans = min(minans,  arr[i-1][end_y]);
    }
    arr[start_x + 1][end_y] = temp;
    minans = min(minans,  temp);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int ttt = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            arr[i][j] = ttt;
            ttt++;
        }
    }
    for(int i = 0; i < queries.size(); i++){
        func(queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1);
        answer.push_back(minans);
        minans = 1000001;
        // for(int j = 0; j < rows; j++){
        //     for(int k = 0; k < columns; k++){
        //         cout << arr[j][k] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    return answer;
}