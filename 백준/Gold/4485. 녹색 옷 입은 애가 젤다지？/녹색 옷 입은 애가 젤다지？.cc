#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[126][126];
int d[126][126];
bool visited[126][126];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
const long long INF = 1e9+10;

bool cango(int x, int y, int s){
    return 0 <= x && x < s && 0 <= y && y < s;
}

int main(){
    int now = 1;
    while(1){
        int x; cin >> x;
        if(x == 0){
            break;
        }

        for(int i = 0; i < x; i++){
            for(int j = 0; j < x; j++){
                cin >> arr[i][j];
                d[i][j] = INF;
            }
        }

        priority_queue<pair<int, pair<int, int> > > pq;
        d[0][0] = arr[0][0];
        pq.push(make_pair(-d[0][0], make_pair(0, 0)));

        while(!pq.empty()){
            int cost = -pq.top().first;
            int cur_x = pq.top().second.first;
            int cur_y = pq.top().second.second;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if(cango(nx, ny, x)){
                    if(d[nx][ny] > cost + arr[nx][ny]){
                        d[nx][ny] = cost + arr[nx][ny];
                        pq.push(make_pair(-d[nx][ny], make_pair(nx, ny)));
                    }
                }
            }
        }

        cout << "Problem " << now++ << ": " << d[x-1][x-1] << '\n';
        
    }
}