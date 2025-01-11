#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, minans;
int arr[501][501];
int dp[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int dfs(int x, int y){
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    dp[x][y] = 1;


    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(cango(nx, ny) && arr[x][y] < arr[nx][ny]){
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }

    return dp[x][y];

}


int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            minans = max(minans, dfs(i, j));
        }   
    }

    cout << minans;
}