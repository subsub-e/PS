#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int arr[501][501];
bool visited[501][501];
int n, m;
int ans = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y, int cnt, int score){
    if(cnt == 4){
        ans = max(ans, score);
        return;
    }


    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < n && 0 <= y && y < m && !visited[nx][ny]){
            visited[nx][ny] = 1;
            dfs(nx, ny, cnt + 1, score + arr[nx][ny]);
            visited[nx][ny] = 0;
        }
    }

    if(x - 1 >= 0 && y - 1 >= 0 && x + 1 < n){
        ans = max(ans, arr[x-1][y] + arr[x][y-1] + arr[x+1][y] + arr[x][y]);
    }

    if(x - 1 >= 0 && y + 1 >= 0 && x + 1 < n){
        ans = max(ans, arr[x-1][y] + arr[x][y+1] + arr[x+1][y] + arr[x][y]);
    }

    if(y - 1 >= 0 && x - 1 >= 0 && y + 1 < m){
        ans = max(ans, arr[x-1][y] + arr[x][y-1] + arr[x][y+1] + arr[x][y]);
    }

    if(y - 1 >= 0 && x + 1 >= 0 && y + 1 < m){
        ans = max(ans, arr[x+1][y] + arr[x][y-1] + arr[x][y+1] + arr[x][y]);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = 1;
            dfs(i, j, 1, arr[i][j]);
            visited[i][j] = 0;
        }
    }

    cout << ans;
	return 0;
}