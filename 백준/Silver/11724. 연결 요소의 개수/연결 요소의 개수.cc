#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int n, m;
vector<int> v[1001];
bool visited[1001];
queue<int> q;

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : v[x]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(next);
            }
        }   
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
    cin >> n >> m;
    int x1, x2;
    for(int i = 0; i < m; i++){
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            q.push(i);
            visited[i] = 1;
            //cout << i << '\n';
            cnt++;
            bfs();
        }
    }
    cout << cnt;
}