#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

int k;
int n, m;
queue<pair<pair<int, int> , pair<int, int> > > q;
int arr[201][201];
bool visited[201][201][31];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int horse_x[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int horse_y[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int flag = 0;

bool cango(int x, int y, int chance){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y][chance];
}


void bfs(){
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    visited[0][0][0] = 1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int horse = q.front().second.second;
        q.pop();
        //cout << x << ' ' << y << ' ' << cnt << ' ' << horse << '\n';

        if(x == n-1 && y == m-1){
            cout << cnt;
            flag = 1;
            return;
        }

        if(horse < k){
            for(int i = 0; i < 8; i++){
                int nx = x + horse_x[i];
                int ny = y + horse_y[i];

                if(cango(nx, ny, horse + 1)){
                    if(arr[nx][ny] == 0){
                        q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, horse + 1)));
                        visited[nx][ny][horse + 1] = 1;
                    }
                }
            }
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(cango(nx, ny, horse)){
                if(arr[nx][ny] == 0){
                    q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, horse)));
                    visited[nx][ny][horse] = 1;
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> k >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    bfs();
    if(flag == 0){
        cout << -1;
    }
    return 0;
}