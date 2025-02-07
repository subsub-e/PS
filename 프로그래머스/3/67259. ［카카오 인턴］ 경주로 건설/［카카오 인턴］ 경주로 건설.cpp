#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[26][26];
int visited[26][26][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, pair<int, int> > > q;
const int INF = 1e9 + 10;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int dir = q.front().second.second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int cost = visited[x][y][dir];
            if(dir == i){
                cost += 100;
            }
            else{
                cost += 600;
            }
            
            if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[nx][ny] == 0 && cost < visited[nx][ny][i]){
                visited[nx][ny][i] = cost;
                q.push({nx, {ny, i}});
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = INF;
    n = board.size();
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            for(int k = 0; k < 4; k++){
                visited[i][j][k] = INF;
            }
            arr[i][j] = board[i][j];
        }
    }
    
    q.push({0, {0, 2}});
    visited[0][0][2] = 0;
    q.push({0, {0, 3}});
    visited[0][0][3] = 0;
    bfs();
    
    for(int i = 0; i < 4; i++){
        answer = min(answer, visited[board.size() - 1][board.size() - 1][i]);
    }
    
    return answer;
}