#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, h, flag;
bool ladder[31][11];


bool game(){
    for(int i = 1; i <= n; i++){
        int y = i;
        for(int j = 1; j <= h; j++){
            if(ladder[j][y]){
                y++;
                continue;
            }
            if(ladder[j][y-1]){
                y--;
            }
        }
        if(i != y){
            return false;
        }
    }

    return true;
}


void dfs(int cnt, int now){
    if(flag == 1){
        return;
    }

    if(cnt == now){
        if(game()){
            cout << cnt;
            flag = 1;
            exit(0);
        }
        return;
    }

    for(int j = 1; j <= n-1; j++){
        for(int i = 1; i <= h; i++){
            if(ladder[i][j] || ladder[i][j-1] || ladder[i][j + 1]){
                continue;
            }
            ladder[i][j] = 1;
            dfs(cnt, now + 1);
            ladder[i][j] = 0;

            while(!ladder[i][j-1] && !ladder[i][j+1]) i++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> h;

    for(int i = 0; i < m; i++){
        int st, en;
        cin >> st >> en;
        ladder[st][en] = 1;
    }

    for(int i = 0; i < 4; i++){
        dfs(i, 0);
    }

    if(flag == 0){
        cout << -1;
    }
}
