#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, ans, stx, sty;
char arr[601][601];
bool visited[601][601];
queue<pair<int, int> > q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && arr[x][y] != 'X';
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
                if(arr[nx][ny] == 'P'){
                    ans++;
                }
                visited[nx][ny] = 1;
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
            if(arr[i][j] == 'I'){
                stx = i;
                sty = j;
            }
        }
    }

    bfs();

    if(ans == 0){
        cout << "TT";
    }
    else{
        cout << ans;
    }

}