#include <string>
#include <vector>
#include <iostream>
using namespace std;

int visited[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i = 0; i < results.size(); i++){
        visited[results[i][0] - 1][results[i][1] - 1] = 1;
    }
    
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][k] && visited[k][j]){
                    visited[i][j] = 1;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(visited[i][j] || visited[j][i]){
                cnt++;
            }
        }
        if(cnt == n - 1){
            answer++;
        }
    }
    
    
    
    return answer;
}