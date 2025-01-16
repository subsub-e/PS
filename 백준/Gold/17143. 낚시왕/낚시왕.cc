#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <map>
using namespace std;

int n, m, t, ans;
int arr[102][102];
priority_queue<tuple<int, int, int, int, int> > pq;
int hunt_x, hunt_y;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void simulate(){
    tuple<int, int, int> temp[102][102];
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            temp[i][j] = make_tuple(0, 0, 0);
        }
    }
    while(!pq.empty()){
        int r, c, s, d, z;
        tie(r, c, s, d, z) = pq.top();
        pq.pop();
        if(r == hunt_x && c == hunt_y){
            continue;
        }

        int dist_x = s % ((n - 1) * 2);
        int dist_y = s % ((m - 1) * 2);
        int dir = d;
        if(dir == 0 || dir == 1){
            dist_y = 0;
        }
        else{
            dist_x = 0;
        }
        int nx = r;
        int ny = c;

        for(int i = 0; i < max(dist_x, dist_y); i++){
            if(nx + dx[dir] == 0){
                dir = 1;
            }
            if(nx + dx[dir] == n + 1){
                dir = 0;
            }
            if(ny + dy[dir] == m + 1){
                dir = 3;
            }
            if(ny + dy[dir] == 0){
                dir = 2;
            }
            nx += dx[dir];
            ny += dy[dir];
        }

        int temp_s, temp_d, temp_z;
        tie(temp_s, temp_d, temp_z) = temp[nx][ny];
        if(temp_z < z){
            temp[nx][ny] = make_tuple(s, dir, z);
        }
        else{
            temp[nx][ny] = make_tuple(temp_s, temp_d, temp_z);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int temp_s, temp_d, temp_z;
            tie(temp_s, temp_d, temp_z) = temp[i][j];
            if(temp_z > 0){
                pq.push(make_tuple(i, j, temp_s, temp_d, temp_z));
                arr[i][j] = temp_z;
            }
            else{
                arr[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m >> t;
    while(t--){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        pq.push(make_tuple(r, c, s, d - 1, z));
        arr[r][c] = z;
    }

    // for(int j = 1; j <= n; j++){
    //         for(int k = 1; k <= m; k++){
    //             cout << arr[j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';

    for(int i = 1; i <= m; i++){
        hunt_x = 0;
        hunt_y = 0;
        for(int j = 1; j <= n; j++){
            if(arr[j][i] > 0){
                ans+=arr[j][i];
                hunt_x = j;
                hunt_y = i;
                break;
            }
        }

        simulate();
        
        // for(int j = 1; j <= n; j++){
        //     for(int k = 1; k <= m; k++){
        //         cout << arr[j][k] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << ans;
}




