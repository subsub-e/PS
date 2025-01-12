#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, stx, sty, ans;
int level = 2;
int arr[21][21];
int cnt[21][21];
bool visited[21][21];
queue<pair<int, int> > q;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};


bool check(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] != 0 && arr[i][j] < level){
                return true;
            }
        }
    }
    return false;
}

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n && !visited[x][y] && level >= arr[x][y];
}

void bfs(int start_x, int start_y){

    memset(visited, 0, sizeof(visited));
    memset(cnt, 0, sizeof(cnt));

    visited[start_x][start_y] = 1;
    q.push({start_x, start_y});

    vector<pair<int, pair<int, int> > > v;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //cout << x << ' ' << y << '\n';
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny)){
                visited[nx][ny] = 1;
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push({nx, ny});
                if(arr[nx][ny] != 0 && arr[nx][ny] < level){
                    v.push_back({cnt[nx][ny], {nx, ny}});
                }
            }
        }
    }

    if(!v.empty()){
        sort(v.begin(), v.end());

        stx = v[0].second.first;
        sty = v[0].second.second;
        //cout << stx << ' ' << sty << '\n';
        arr[stx][sty] = 0;
    }
    
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                stx = i;
                sty = j;
            }
        }
    }

    int temp_cnt = 0;
    while(1){
        if(!check()){
            break;
        }
        arr[stx][sty] = 0;
        bfs(stx, sty);
        //cout << stx << ' ' << sty << '\n';
        if(cnt[stx][sty] == 0){
            break;
        }
        ans += cnt[stx][sty];
        temp_cnt++;
        if(temp_cnt == level){
            temp_cnt = 0;
            level++;
        }
    }

    cout << ans;

}