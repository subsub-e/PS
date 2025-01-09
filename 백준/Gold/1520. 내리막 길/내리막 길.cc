#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int arr[501][501];
int visited[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};




bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}


int dfs(int x, int y){

    if(visited[x][y] != -1){
        return visited[x][y];
    }

    if(x == n - 1 && y == m - 1){
        return 1;
    }

    visited[x][y] = 0;


    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(cango(nx, ny) && arr[x][y] > arr[nx][ny]){
            visited[x][y] = visited[x][y] + dfs(nx, ny);
        }
    }

    return visited[x][y];
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    

    cout << dfs(0, 0);;
}