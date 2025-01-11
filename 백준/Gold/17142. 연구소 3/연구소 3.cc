#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


int n, m;
vector<pair<int, int> > v;
queue<pair<int, int> > q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int arr[51][51];
int cnt[51][51];
bool visited[51][51];
vector<int> temp;
int minans = 1e9 + 10;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n && !visited[x][y] && arr[x][y] != 1;
}

void game(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cango(nx, ny)){
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }   
}


void solution(int now){
    if((int) temp.size() == m){

        memset(visited, 0, sizeof(visited));
        memset(cnt, -1, sizeof(cnt));


        for(int i = 0; i < m; i++){
            q.push({v[temp[i]].first, v[temp[i]].second});
            cnt[v[temp[i]].first][v[temp[i]].second] = 0;
            visited[v[temp[i]].first][v[temp[i]].second] = 1;
        }

        game();

        int maxans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(cnt[i][j] == -1 && arr[i][j] == 0){
                    return;
                }
                if(arr[i][j] == 2 || arr[i][j] == 1){
                    continue;
                }
                maxans = max(maxans, cnt[i][j]);
            }
        }
        minans = min(minans, maxans);
        return;
    }

    for(int i = now; i < (int) v.size(); i++){
        temp.push_back(i);
        solution(i + 1);
        temp.pop_back();
    }
}

void init(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                v.push_back({i, j});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    solution(0);

    if(minans == 1e9 + 10){
        cout << -1;
    }
    else{
        cout << minans;
    }
}