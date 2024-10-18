#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int len;
int arr[201][201];
bool visited[201];

void dfs(int x){
    if(visited[x]){
        return;
    }
    visited[x] = 1;
    for(int i = 0; i < len; i++){
        if(x != i && arr[x][i] == 1){
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    len = computers.size();
    memset(arr, -1, sizeof(arr));
    
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[0].size(); j++){
            arr[i][j] = computers[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            
            answer++;
        }
    }
    
    return answer;
}