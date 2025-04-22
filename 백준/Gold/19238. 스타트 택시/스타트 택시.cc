#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Info{
    int stx, sty, enx, eny;
};

int n, m, oil, taxiX, taxiY;
int flag = 0;
vector<Info> v;
int arr[21][21];
bool visited[21][21];
vector<int> people[21][21];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int ind = -1;

void input(){
    cin >> n >> m >> oil;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    cin >> taxiX >> taxiY;
    taxiX--;
    taxiY--;
    for(int i = 0; i < m; i++){
        int stx, sty, enx, eny;
        cin >> stx >> sty >> enx >> eny;
        people[stx - 1][sty - 1].push_back(i);
        v.push_back({stx - 1, sty - 1, enx - 1, eny - 1});
    }
}

void bfs(int simulate){
    queue<pair<int, pair<int, int> > > q;
    memset(visited, 0, sizeof(visited));

    int temp_cnt = 1e9 + 10;
    int temp_x = 1e9 + 10;
    int temp_y = 1e9 + 10;


    visited[taxiX][taxiY] = 1;
    q.push({taxiX, {taxiY, 0}});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if(simulate == 1 && people[x][y].size() > 0){
            if(temp_cnt > cnt){
                temp_x = x;
                temp_y = y;
                temp_cnt = cnt;
            }
            else if(temp_cnt == cnt){
                if(temp_x > x){
                    temp_x = x;
                    temp_y = y;
                    temp_cnt = cnt;
                }
                else if(temp_x == x){
                    if(temp_y > y){
                        temp_x = x;
                        temp_y = y;
                        temp_cnt = cnt;
                    }
                }
                
            }
            
        }

        if(simulate == 2 && v[ind].enx == x && v[ind].eny == y){
            if(oil < cnt){
                while(!q.empty()){
                    q.pop();
                }
                return;
            }
            taxiX = x;
            taxiY = y;
            oil += cnt;
            while(!q.empty()){
                q.pop();
            }
            return;
        }



        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && arr[nx][ny] != 1){
                visited[nx][ny] = 1;
                q.push({nx, {ny, cnt + 1}});
            }
        }
    }

    if(simulate == 1 && temp_cnt != (1e9 + 10)){
        ind = people[temp_x][temp_y][0];
        people[temp_x][temp_y].clear();
        taxiX = temp_x;
        taxiY = temp_y;
        oil -= temp_cnt;
    }
}

void func(){
    int temp_x = taxiX;
    int temp_y = taxiY;
    ind = -1;

    bfs(1);

    if(ind == -1 || oil <= 0){
        cout << -1;
        flag = 1;
        return;
    }

    //cout << oil << '\n';

    temp_x = taxiX;
    temp_y = taxiY;

    bfs(2);

    if((temp_x == taxiX && temp_y == taxiY)){
        cout << -1;
        flag = 1;
        return;
    }

    //cout << oil << '\n';


}

int main(){
    input();
    for(int i = 0; i < m; i++){
        func();
        if(flag == 1){
            break;
        }
    }

    if(flag == 0){
        cout << oil;
    }
}