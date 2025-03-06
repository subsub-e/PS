#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct point{
    int x;
    int y;
    int cnt;
    bool flag;
};

int n, m;
int arr[1001][1001];
bool visited[1001][1001][2];
queue<point> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool cango(int x, int y, bool flag){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y][flag];
}

int bfs(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        bool flag = q.front().flag;
        q.pop();

        if(x == n - 1 && y == m - 1){
            return cnt;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(cango(nx, ny, flag)){
                if(arr[nx][ny] == 0){
                    visited[nx][ny][flag] = 1;
                    q.push({nx, ny, cnt + 1, flag});
                }
                else{
                    if(flag == 0){
                        visited[nx][ny][1] = 1;
                        q.push({nx, ny, cnt + 1, 1});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            arr[i][j] = (int) c - 48;
        }
    }

    visited[0][0][0] = 1;
    q.push({0, 0, 1, 0});

    int answer = bfs();
    cout << answer;

    return 0;
}
