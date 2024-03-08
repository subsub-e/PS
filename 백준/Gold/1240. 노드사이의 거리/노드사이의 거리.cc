#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int n, r;
vector<pair<int, int> > v[1001];
int dist[1001];


int bfs(int start, int end){
    int sum = 0;
    fill_n(dist, 1001, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : v[x]){
            if(dist[next.first] != -1){
                continue;
            }
            dist[next.first] = dist[x] + next.second;
            q.push(next.first);
        }
    }

    return dist[end];
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> r;
    for(int i = 0; i < n-1; i++){
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        v[x1].push_back(make_pair(x2, x3));
        v[x2].push_back(make_pair(x1, x3));
    }

    for(int i = 0; i < r; i++){
        int x1, x2;
        cin >>x1 >> x2;
        cout << bfs(x1, x2) << '\n';
    }
    return 0;
}