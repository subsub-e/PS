#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, stx, sty;
int arr[1001][1001];
bool visited[1001][1001];
int cnt[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int> > q;


bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && arr[x][y] == 1;
}

void bfs(){
    visited[stx][sty] = 1;
    q.push({stx, sty});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny)){
                visited[nx][ny] = 1;
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                stx = i;
                sty = j;
            }
        }
    }

    bfs();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(cnt[i][j] == 0 && arr[i][j] == 1){
                cout << -1 << ' ';
            }
            else{
                cout << cnt[i][j] << ' ';
            }
        }
        cout << '\n';
    }

}