#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int n, m, k;
int arr[1001][1001];
bool visited[1001][1001][11];
queue<pair<pair<int, int>, pair<int, int> > > q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int flag = 0;

bool cango(int x, int y, int p){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y][p];
}


void bfs(){
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    visited[0][0][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int crash = q.front().second.second;
        q.pop();
        //cout << x << ' ' << y << ' ' << cnt << ' ' << crash << '\n';

        if(x == n-1 && y == m-1){
            cout << ++cnt;
            flag = 1;
            return;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny, crash + 1)){
                //cout << nx << ' '<< ny << '\n';
                if(arr[nx][ny] == 1 && crash < k){
                    //cout << nx << ' '<< ny << '\n';
                    q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, crash + 1)));
                    visited[nx][ny][crash + 1] = 1;
                }
            }
            if(cango(nx, ny, crash)){
                if(arr[nx][ny] == 0){
                    q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, crash)));
                    visited[nx][ny][crash] = 1;
                }
            }
        }
    }
}


int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            arr[i][j] = (int) (c - 48);
        }
    }

    bfs();
    if(flag == 0){
        cout << -1;
    }
    return 0;
}