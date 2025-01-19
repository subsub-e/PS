#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int arr[11][11];
int n, m, k;
vector<int> v[11][11];
int grow[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool cango(int x, int y){
    return 0 < x && x <= n && 0 < y && y <= n;
}

void input(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grow[i][j];
        }
    }
    while(m--){
        int x, y, level;
        cin >> x >> y >> level;
        v[x][y].push_back(level);
    }
}

void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = 5;
        }
    }
}

void springAndSummer(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(v[i][j].size() == 0){
                continue;
            }
            int die = 0;
            sort(v[i][j].begin(), v[i][j].end());
            vector<int> temp;
            for(auto now : v[i][j]){
                if(now > arr[i][j]){
                    die += (now / 2);
                }
                else{
                    arr[i][j] -= now;
                    temp.push_back(now + 1);
                }
            }
            v[i][j].clear();
            for(int k = 0; k < temp.size(); k++){
                v[i][j].push_back(temp[k]);
            }
            arr[i][j] += die;
        }
    }
}




void fall(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(v[i][j].size() == 0){
                continue;
            }
            for(auto now : v[i][j]){
                if(now % 5 == 0){
                    for(int k = 0; k < 8; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(cango(nx, ny)){
                            v[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] += grow[i][j];
        }
    }
}


void simulate(){
    springAndSummer();
    fall();
    winter();
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    init();
    while(k--){
        simulate();
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans += v[i][j].size();
        }
    }
    cout << ans;
}