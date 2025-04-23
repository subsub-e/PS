#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
char arr[10001][501];
bool visited[10001][501];
int flag, answer;
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

void dfs(int x, int y){
    if(flag == 1){
        return;
    }
    if(y == c - 1){
        answer++;
        flag = 1;
        return;
    }
    visited[x][y] = 1;
    //cout << x << ' ' << y << '\n';

    for(int i = 0; i < 3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < r && 0 <= ny && ny < c && !visited[nx][ny] && arr[nx][ny] == '.'){
            
            dfs(nx, ny);
        }
    }
}


int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < r; i++){
        flag = 0;
        //cout << i << '\n';
        dfs(i, 0);
    }

    cout << answer;
}