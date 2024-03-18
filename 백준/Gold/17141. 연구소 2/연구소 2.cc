#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
int arr[51][51];
int temp[51][51];
bool visited[51][51];
int cnt[51][51];
int ans = INT_MAX;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int> > q;
vector<pair<int, int> > v;
vector<int> per;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && temp[nx][ny] == 0){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                cnt[nx][ny] = cnt[x][y] + 1;
            }
        }
    }
}

void func(int x){
    if(per.size() == m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 2){
                    temp[i][j] = 0;
                    continue;
                }
                temp[i][j] = arr[i][j];
            }
        }
        for(int i = 0; i < per.size(); i++){
            int x = v[per[i]].first;
            int y = v[per[i]].second;
            temp[x][y] = 2;
        }

        memset(visited, 0, sizeof(visited));
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(temp[i][j] == 2 && !visited[i][j]){
                    visited[i][j] = 1;
                    q.push(make_pair(i, j));
                    cnt[i][j] = 1;
                }
            }
        }

        bfs();
        int maxans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(temp[i][j] == 0 && cnt[i][j] == 0){
                    return;
                }
                maxans = max(maxans, cnt[i][j]);
            }
        }

        ans = min(ans, maxans);
        return;
    }

    for(int i = x; i < v.size(); i++){
        per.push_back(i);
        func(i + 1);
        per.pop_back();
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                v.push_back(make_pair(i, j));
            }
        }
    }

    func(0);
    if(ans == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << --ans;
	return 0;
}