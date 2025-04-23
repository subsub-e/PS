#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
char arr[51][51];
bool visited[51][51];
int cnt[51][51];
int flag, answer;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y){
    if(flag == 1){
        return;
    }
    int amount = (int) arr[x][y] - '0';

    int now_cnt = cnt[x][y];

    for(int i = 0; i < 4; i++){
        int nx = x + (amount * dx[i]);
        int ny = y + (amount * dy[i]);

        if(0 <= nx && nx < r && 0 <= ny && ny < c && arr[nx][ny] != 'H'){
            if(visited[nx][ny]){
                flag = 1;
                return;
            }
            if(cnt[nx][ny] < now_cnt + 1){
                visited[nx][ny] = 1;
                cnt[nx][ny] = now_cnt + 1;
                dfs(nx, ny);
                visited[nx][ny] = 0;
            }

            
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
        for(int j = 0; j < c; j++){
            cnt[i][j] = -1;
        }
    }

    visited[0][0] = 1;
    cnt[0][0] = 1;
    dfs(0, 0);

    if(flag == 1){
        cout << -1;
    }
    else{
        int maxans = -1;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(cnt[i][j] != 1e9 + 10){
                    maxans = max(maxans, cnt[i][j]);
                    
                }
                //cout << cnt[i][j] << ' ';
                
            }
            //cout << '\n';
        }
        cout << maxans;
    }
}