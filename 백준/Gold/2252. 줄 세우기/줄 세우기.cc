#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n + 1);
    vector<int> indeg(n + 1);
    while(m--){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        indeg[x2]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(auto next : v[cur]){
            indeg[next]--;
            if(indeg[next] == 0){
                q.push(next);
            }
        }
    }
    return 0;
}