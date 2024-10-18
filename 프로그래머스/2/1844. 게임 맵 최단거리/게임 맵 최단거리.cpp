#include<vector>
#include <algorithm>
// #include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
queue<pair<int, int> > q;
int cnt[101][101];
int visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y];
}

void bfs(vector<vector<int> > maps){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny) && maps[nx][ny] == 1){
                visited[nx][ny]++;
                q.push(make_pair(nx, ny));
                cnt[nx][ny] = cnt[x][y] + 1;
                if(nx == n-1 && ny == m-1){
                    return;
                }
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    visited[0][0]++;
    n = maps.size();
    m = maps[0].size();
    q.push(make_pair(0, 0));
    cnt[0][0] = 1;
    
    bfs(maps);
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    if(cnt[n-1][m-1] == 0){
        return -1;
    }
    return cnt[n-1][m-1];
}