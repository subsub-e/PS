#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int n, m;
int arr[1001][1001];
int visited[1001][1001];
int cnt[1001][1001];
queue<pair<int, int> > q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans[1001][1001];
int order = 1;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && visited[x][y] == 0 && arr[x][y] == 0;
}

void bfs(int now){
    vector<pair<int, int> > v;
    int temp = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        v.push_back({x, y});
        temp++;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny)){
                visited[nx][ny] = now;
                q.push({nx, ny});
            }
        }
    }

    for(int i = 0; i < (int) v.size(); i++){
        cnt[v[i].first][v[i].second] = temp;
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            arr[i][j] = (int) c - '0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0 && arr[i][j] == 0){
                visited[i][j] = order;
                q.push({i, j});
                bfs(order);
                order++;
            }
        }
    }

    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1){
                int temp = 1;
                unordered_set<int> s;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(0 <= nx && nx < n && 0 <= ny && ny < m){
                        if(s.find(visited[i + dx[k]][j + dy[k]]) != s.end()){
                            continue;
                        }
                        s.insert(visited[i + dx[k]][j + dy[k]]);
                        temp += cnt[i + dx[k]][j + dy[k]];
                    }
                }   
                ans[i][j] = temp % 10;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j]; 
        }
        cout << '\n';
    }
}