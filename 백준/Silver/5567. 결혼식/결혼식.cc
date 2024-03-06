#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int n, m;
vector<int> v[501];
bool visited[501];
queue<int> q;
int counted[501];

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto next : v[x]){
            if(!visited[next]){
                visited[next] = 1;
                counted[next] = counted[x] + 1;
                q.push(next);
            }
        }
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x1, x2; cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    visited[1] = 1;
    q.push(1);
    counted[1] = 1;
    bfs();
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        //cout << counted[i] << '\n';
        if(counted[i] == 2 || counted[i] == 3){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}