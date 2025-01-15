#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, ans;
int num = 1;
char arr[1001][1001];
int visited[1001][1001];

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y){
    if(visited[x][y] != 0 && visited[x][y] == num){
        ans++;
        return;
    }

    if(visited[x][y] != 0 && visited[x][y] != num){
        return;
    }

    visited[x][y] = num;

    if(arr[x][y] == 'L'){
        y--;
    }
    else if(arr[x][y] == 'R'){
        y++;
    }
    else if(arr[x][y] == 'U'){
        x--;
    }
    else{
        x++;
    }

    if(cango(x, y)){
        dfs(x, y);
    }
    
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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0){
                dfs(i, j);
                num++;
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << ans;
}