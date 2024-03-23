#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
bool visited[30];
char arr[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int maxans;

void dfs(int x, int y, int cnt){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[(int) arr[nx][ny] - 65]){
            visited[(int) arr[nx][ny] - 65] = 1;
            dfs(nx, ny, cnt + 1);
            visited[(int) arr[nx][ny] - 65] = 0;
            maxans = max(maxans, cnt);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    visited[(int) arr[0][0] - 65] = 1;
    dfs(0, 0, 1);
    cout << maxans + 1;
    return 0;
}