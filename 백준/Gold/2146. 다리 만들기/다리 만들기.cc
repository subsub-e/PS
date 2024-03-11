#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

int n;
int arr[101][101];
bool visited[101][101];
int counted[101][101];
queue<pair<int, int> > q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int minans = INT_MAX;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n && !visited[x][y];
}

void bfs(int index){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(cango(nx, ny)){
                if(arr[nx][ny] != 0){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                    arr[nx][ny] = index;
                }
            }
        }
    }
}

int func(int index){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny)){
                //cout << nx << ' ' << ny << '\n';
                if(arr[nx][ny] == 0){
                    //cout << nx << ' ' << ny << '\n';
                    counted[nx][ny] = counted[x][y] + 1;
                }
                if(arr[nx][ny] != 0 && arr[nx][ny] != index){
                    //cout << nx << ' ' << ny << '\n';
                    // for(int j = 0; j < n; j++){
                    //     for(int k = 0; k < n; k++){
                    //         cout << counted[j][k] << ' ';
                    //     }
                    //     cout << '\n';
                    // }
                    // cout << '\n';
                    return counted[x][y];
                }
                if(arr[nx][ny] == index){
                    counted[nx][ny] = 1;
                }
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            if(x == 1){
                arr[i][j] = -1;
            }
            else{
                arr[i][j] == 0;
            }
        }
    }
    int index1 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == -1 && !visited[i][j]){
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                arr[i][j] = index1;
                bfs(index1);
                index1++;
            }
        }
    }

    for(int k = 1; k < index1; k++){
        memset(visited, 0, sizeof(visited));
        memset(counted, 0, sizeof(counted));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == k && !visited[i][j]){
                    for(int st = 0; st < 4; st++){
                        int nx = i + dx[st];
                        int ny = j + dy[st];
                        if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[nx][ny] == 0){
                            q.push(make_pair(i, j));
                            break;
                        }
                    }
                    visited[i][j] = 1;
                    counted[i][j] = 1;
                }
            }
        }
        minans = min(minans, func(k));
        while(!q.empty()){
            q.pop();
        }
    }

    cout << --minans;
    return 0;
}