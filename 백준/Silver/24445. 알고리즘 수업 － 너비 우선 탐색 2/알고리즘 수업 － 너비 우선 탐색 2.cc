#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, r;
vector<int> v[100001];
queue<int> q;
bool visited[100001];
int answer[100001];
int cnt = 1;

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto next : v[x]){
            if(!visited[next]){
                visited[next] = 1;
                q.push(next);
                answer[next] = cnt++;
            }
        }
    }
}

int main(){
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int x1, x2; cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    visited[r] = 1;
    q.push(r);
    answer[r] = cnt++;
    for(int i = 1; i <= n; i++){
        sort(v[i].rbegin(), v[i].rend());
    }
    bfs();

    for(int i = 1; i <= n; i++){
        cout << answer[i] << '\n';
    }
}