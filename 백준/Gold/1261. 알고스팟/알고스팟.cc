#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[101][101];
int counted[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
deque<pair<int, int> > dq;

void bfs(){
    while(!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(counted[nx][ny] == -1){
                    if(arr[nx][ny] == 0){
                        dq.push_front(make_pair(nx, ny));
                        counted[nx][ny] = counted[x][y];
                    }
                    else{
                        dq.push_back(make_pair(nx, ny));
                        counted[nx][ny] = counted[x][y] + 1;
                    }
                }
            }
        }
    }
}

int main() {
	
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            arr[i][j] = (int)c - 48;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            counted[i][j] = -1;
        }
    }

    counted[0][0] = 0;
    dq.push_back(make_pair(0, 0));
    bfs();
    cout << counted[n-1][m-1];
	return 0;
}