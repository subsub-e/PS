#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int n, m;
struct Info
{
    int rx, ry, bx, by, count;
};
Info start;
char map[11][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool visited[11][11][11][11];


int bfs(){
    queue<Info> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;

    int ans = -1;

    while(!q.empty()){
        Info cur = q.front();
        q.pop();
        if(cur.count > 10){
            break;
        } 
        if(map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O'){
            ans = cur.count;
            break;
        }

        for(int i = 0; i < 4; i++){
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;

            while(1){
                if(map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O'){
                    next_ry += dy[i];
                    next_rx += dx[i];
                }
                else{
                    if(map[next_ry][next_rx] == '#'){
                        next_ry -= dy[i];
                        next_rx -= dx[i]; 
                    }
                    break;
                }
            }

            while(1){
                if(map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O'){
                    next_by += dy[i];
                    next_bx += dx[i];
                }
                else{
                    if(map[next_by][next_bx] == '#'){
                        next_by -= dy[i];
                        next_bx -= dx[i];
                    }
                    break;
                }
            }

            if(next_rx == next_bx && next_ry == next_by){
                if(map[next_ry][next_rx] != 'O'){
                    int red_dist = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
                    int blue_dist = abs(next_bx - cur.bx) + abs(next_by - cur.by);

                    if(red_dist < blue_dist){
                        next_bx -= dx[i];
                        next_by -= dy[i];
                    }
                    else{
                        next_rx -= dx[i];
                        next_ry -= dy[i];
                    }
                }
            }

            if(!visited[next_ry][next_rx][next_by][next_bx]){
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                Info next;
                next.rx = next_rx;
                next.ry = next_ry;
                next.bx = next_bx;
                next.by = next_by;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }

    return ans;

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                start.ry = i;
                start.rx = j;
            }
            if(map[i][j] == 'B'){
                start.by = i;
                start.bx = j;
            }
        }
    }

    //start.count = 0;

    int ans = bfs();

    cout << ans;
}


