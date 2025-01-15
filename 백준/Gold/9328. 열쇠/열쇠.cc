#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <string>
using namespace std;

int t;
int n, m, ans;
char arr[105][105];
bool visited[105][105];
queue<pair<int, int> > q;
multimap<char, pair<int, int> > posi;
unordered_set<char> k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool cango(int x, int y){
    return 0 <= x && x <= n + 1 && 0 <= y && y <= m + 1 && !visited[x][y] && arr[x][y] != '*';
}

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        //cout << arr[x][y] << ' ';
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(cango(nx, ny)){
                //cout << nx << ' ' << ny << '\n';
                if(arr[nx][ny] == '.'){
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
                else if(arr[nx][ny] == '$'){
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                    ans++;
                }
                else if(arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z'){
                    //cout << nx << ' ' << ny << '\n';
                    if(k.find(arr[nx][ny]) != k.end()){
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                    else{
                        posi.insert(make_pair(arr[nx][ny], make_pair(nx, ny)));
                        //posi[arr[nx][ny]] = make_pair(nx, ny);
                    }
                }
                else if(arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z'){
                    //cout << nx << ' ' << ny << '\n';
                    char temp = (int) arr[nx][ny] - 32;
                    k.insert(temp);
                    if(posi.find(temp) != posi.end()){
                        for(auto now : posi){
                            if(now.first == temp){
                                int temp_x = now.second.first;
                                int temp_y = now.second.second;
                                visited[temp_x][temp_y] = 1;
                                q.push({temp_x, temp_y});
                            }
                        }
                    }
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void init(){
    memset(visited, 0, sizeof(visited));
    posi.clear();
    ans = 0;
    k.clear();
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            arr[i][j] = '.';
        }
    }
}

void game(){
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    string str;
    cin >> str;

    // for(int i = 0; i <= n + 1; i++){
    //     for(int j = 0; j <= m + 1; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    if(str != "0"){
        for(int i = 0; i < str.length(); i++){
            char temp = (int) str[i] - 32;
            k.insert(temp);
        }
    }
    

    visited[0][0] = 1;
    q.push({0, 0});
    bfs();
    cout << ans << '\n'; 

}

int main(){
    cin >> t;
    while(t--){
        game();
    }
}