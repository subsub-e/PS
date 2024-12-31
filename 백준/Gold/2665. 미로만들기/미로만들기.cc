#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[51][51];
int d[51][51];
priority_queue<pair<int, pair<int, int> > > pq;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n;
const long long INF = 1e9 + 10;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            arr[i][j] = (int) c - 48;
            d[i][j] = INF;
        }
    }

    d[0][0] = 0;
    pq.push(make_pair(-d[0][0], make_pair(0, 0)));
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(cango(nx, ny)){
                if(arr[nx][ny] == 1){
                    if(d[nx][ny] > d[x][y]){
                        d[nx][ny] = d[x][y];
                        pq.push(make_pair(-d[nx][ny], make_pair(nx, ny)));
                    }
                }
                else{
                    if(d[nx][ny] > d[x][y] + 1){
                        d[nx][ny] = d[x][y] + 1;
                        pq.push(make_pair(-d[nx][ny], make_pair(nx, ny)));
                    }
                }
            }
        }
    }

    cout << d[n-1][n-1];
}   