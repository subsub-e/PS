#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char arr[51][51];
bool visited[51][51];
int cnt[51][51];
int n, m;
queue<pair<int, int> > q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int maxans = 0;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && arr[x][y] == 'L';
}

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny)){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
                cnt[nx][ny] = cnt[x][y] + 1;
            }
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            arr[i][j] = c;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'L'){
                memset(visited, 0, sizeof(visited));
                memset(cnt, 0, sizeof(cnt));
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                bfs();
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < m; l++){
                        maxans = max(maxans, cnt[k][l]);
                    }
                }
            }
        }
    }

    cout << maxans;
}