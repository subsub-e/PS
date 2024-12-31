#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, start_x, start_y, end_x, end_y, flag;
char arr[101][101];
int d[101][101];
priority_queue<pair<pair<int, int>, pair<int, int> > > pq;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
const long long INF = 1e9 + 10;


bool cango(int x, int y){
    return 0 <= x && x < m && 0 <= y && y < n && arr[x][y] != '*';
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            d[i][j] = INF;
            if(arr[i][j] == 'C'){
                if(flag == 0){
                    flag = 1;
                    start_x = i;
                    start_y = j;
                }
                else{
                    end_x = i;
                    end_y = j;
                }
            }
        }
    }

    d[start_x][start_y] = 0;
    for(int i = 0; i < 4; i++){
        pq.push(make_pair(make_pair(-0, i), make_pair(start_x, start_y)));
    }

    while(!pq.empty()){
        int cost = -pq.top().first.first;
        int dir = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        
        pq.pop();

        for(int i = 0; i < 4; i++){
            if((dir + 2) % 4 == i){
                continue;
            }
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(cango(nx, ny)){
                if(i == dir){
                    if(d[nx][ny] >= cost){
                        d[nx][ny] = cost;
                        pq.push(make_pair(make_pair(-d[nx][ny], i), make_pair(nx, ny)));
                    }
                }
                else{
                    if(d[nx][ny] > cost + 1){
                        d[nx][ny] = cost + 1;
                        pq.push(make_pair(make_pair(-d[nx][ny], i), make_pair(nx, ny)));
                    }
                }
            }
        }
    }
    
    cout << d[end_x][end_y];

    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << d[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}
