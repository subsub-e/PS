#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int l, r, c;
char arr[31][31][31];
bool visited[31][31][31];
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
bool found = false;
int ans = 0;


void bfs(int start, int end, int layer, int cnt){
    queue<tuple<int, int, int, int> > q;
    q.push(make_tuple(start, end, layer, cnt));
    visited[layer][end][start] = 1;

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        int p = get<3>(q.front());
        if(arr[z][y][x] == 'E'){
            found = true;
            ans = p;
            return;
        }
        q.pop();

        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(0 <= nx && 0 <= ny && 0 <= nz && nx < c && ny < r && nz < l){
                if(!visited[nz][ny][nx] && arr[nz][ny][nx] != '#'){
                    q.push(make_tuple(nx, ny, nz, p + 1));
                    visited[nz][ny][nx] = 1;
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
   
    while(1){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0){
            break;
        }
        memset(visited, false, sizeof(visited));
        found = false;
        int start, end, layer;
        ans = 0;

        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> arr[i][j][k];
                    if(arr[i][j][k] == 'S'){
                        start = k;
                        end = j;
                        layer = i;
                    }
                }
            }
        }

        bfs(start, end, layer, 0);

        if(!found){
            cout << "Trapped!" << '\n';
        }
        else{
            cout << "Escaped in " << ans << " minute(s)." << '\n';
        }
    }
    return 0;
}