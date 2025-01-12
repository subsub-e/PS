#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int arr[101][101];
bool visited[101][101];
int air[101][101];
queue<pair<int, int> > q;
queue<pair<int, int> > cheese;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};


void bfs1(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && arr[nx][ny] == 0){
                air[nx][ny] = -1;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}


void init(){
    memset(visited, 0, sizeof(visited));
    memset(air, 0, sizeof(air));
    q.push({0, 0});
    visited[0][0] = 1;
    air[0][0] = -1;
    bfs1();
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    while(1){
        init();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(air[i][j] == -1){
                    cnt++;
                }
            }
        }

        if(cnt == n * m){
            break;
        }  

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 1){
                    int cnt = 0;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(arr[nx][ny] == 0 && air[nx][ny] == -1){
                            cnt++;
                        }
                    }
                    if(cnt >= 2){
                        cheese.push({i, j});
                    }
                }
            }
        }

        while(!cheese.empty()){
            int x = cheese.front().first;
            int y = cheese.front().second;
            cheese.pop();
            arr[x][y] = 0;
        }


        ans++;

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << air[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    cout << ans;
}