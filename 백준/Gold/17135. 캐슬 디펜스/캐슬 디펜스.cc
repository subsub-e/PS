#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

int n, m, d, maxans, cnt;
int arr[16][16];
int temp[16][16];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool visited[16][16];
int minh = 20;
vector<int> v;
bool visited_m[17];
queue<tuple<int, int, int> > q;
int check[16][16];

void attack(){
    while(!q.empty()){
        int x, y, level;
        tie(x, y, level) = q.front();
        q.pop();

        if(level > d){
            continue;
        }

        if(temp[x][y] == 1){
            visited[x][y] = 1;
            check[x][y]++;
            break;
        }
        else{
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    q.push(make_tuple(nx, ny, level + 1));
                }
            }
        }
    }
}

void simulate(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check[i][j] > 0){
                cnt++;
                //cout << i << ' ' << j << '\n';
                temp[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            check[i][j] = 0;
        }
    }

    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < m; j++){
            temp[i][j] = temp[i-1][j];
        }
    }

    for(int i = 0; i < m; i++){
        temp[0][i] = 0;
    }
}

void init(){
    for(int j = 0; j < n; j++){
        for(int k = 0; k < m; k++){
            visited[j][k] = 0;
        }
    }
    while(!q.empty()){
        q.pop();
    }
}

void solution(int now){
    if(v.size() == 3){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                temp[i][j] = arr[i][j];
            }
        }

        cnt = 0;

        for(int i = 0; i < minh; i++){
            init();
            visited[n-1][v[0]] = 1;
            q.push(make_tuple(n-1, v[0], 1));
            attack();

            init();
            visited[n-1][v[1]] = 1;
            q.push(make_tuple(n-1, v[1], 1));
            attack();

            init();
            visited[n-1][v[2]] = 1;
            q.push(make_tuple(n-1, v[2], 1));
            attack();

            simulate();
        }

        maxans = max(maxans, cnt);
    }

    for(int i = now; i < m; i++){
        if(!visited_m[i]){
            visited_m[i] = 1;
            v.push_back(i);
            solution(i + 1);
            v.pop_back();
            visited_m[i] = 0;
        }
    }
}

int main(){
    cin >> n >> m >> d;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                minh = min(minh, i);
            }
        }
    }

    minh = n - minh;
    solution(0);

    cout << maxans;
}