#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
char arr[10][10];
bool visited[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans;

void dfs(int x, int y, int cnt){
    if(x == 0 && y == c-1){
        if(k == cnt){
            ans++;
        }
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < r && 0 <= ny && ny < c && !visited[nx][ny] && arr[nx][ny] == '.'){
            visited[nx][ny] = 1;
            dfs(nx, ny, cnt + 1);
            visited[nx][ny] = 0;
        }
    }
}

int main() {
	
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }

    visited[r-1][0] = 1;
    dfs(r-1, 0, 1);
    cout << ans;
	return 0;
}