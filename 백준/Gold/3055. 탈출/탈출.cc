#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
char arr[51][51];
int water[51][51];
int v[51][51];
bool visited[51][51];
queue<pair<int, int> > q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && arr[x][y] != 'X';
}

void bfs1(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny)){
                if(arr[nx][ny] != 'D'){
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                    water[nx][ny] = water[x][y] + 1;
                }
            }
        }
    }
}

void bfs2(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny)){
                if(water[nx][ny] > v[x][y] + 1 || water[nx][ny] == 0){
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                    v[nx][ny] = v[x][y] + 1;
                }
            }
        }
    }
}


int main(){
    cin >> n >> m;
    int des_x, des_y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'D'){
                des_x = i;
                des_y = j;
            }
        }
    }

    water[des_x][des_y] = 100000;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '*'){
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }

    bfs1();

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'S'){
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }

    bfs2();


    if(v[des_x][des_y] == 0){
        cout << "KAKTUS";
    }
    else{
        cout << v[des_x][des_y];
    }
}