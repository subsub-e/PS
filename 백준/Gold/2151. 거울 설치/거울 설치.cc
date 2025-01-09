#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <tuple>

using namespace std;

int n;
int stx, sty, enx, eny;
char arr[51][51];
int visited[51][51][4];
queue<tuple<int, int, int, int> > q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9 + 10;

bool cango(int x, int y, int dir, int mirror){
    return 0 <= x && x < n && 0 <= y && y < n && visited[x][y][dir] > mirror && arr[x][y] != '*';
}


void bfs(){
    while(!q.empty()){
        int x, y, dir, mirror;
        tie(x, y, dir, mirror) = q.front();
        q.pop();

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(!cango(nx, ny, dir, mirror)){
            continue;
        }

        visited[nx][ny][dir] = mirror;

        if(arr[nx][ny] == '.'){
            q.push(make_tuple(nx, ny, dir, mirror));
            continue;
        }
        if(arr[nx][ny] == '!'){
            q.push(make_tuple(nx, ny, dir, mirror));
            q.push(make_tuple(nx, ny, (dir + 1) % 4, mirror + 1));
            q.push(make_tuple(nx, ny, (dir + 3) % 4, mirror + 1));
        }
    }
}

int main(){
    cin >> n;
    
    int flag = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 4; k++){
                visited[i][j][k] = INF;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '#' && flag == 1){
                enx = i;
                eny = j;
            }
            if(arr[i][j] == '#' && flag == 0){
                stx = i;
                sty = j;
                flag = 1;
            }
        }
    }

    for(int i = 0; i < 4; i++){
        q.push(make_tuple(stx, sty, i, 0));
    }

    bfs();

    int ans = INF;

    for(int i = 0; i < 4; i++){
        ans = min(ans, visited[enx][eny][i]);
    }

    cout << ans;

}