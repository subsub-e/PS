#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

bool visited[200001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int> > v(n + 1);
    vector<int> indig(n + 1);
    queue<int> q;
    //vector<int> ans;
    
    
    for(int i = 1; i <= n; i++){
        int x1, x2; cin >> x1 >> x2;
        v[i].push_back(x1);
        v[i].push_back(x2);
        indig[x1]++;
        indig[x2]++;
    }


    for(int i = 1; i <= n; i++){
        if(indig[i] < 2){
            visited[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(auto next : v[cur]){
            indig[next]--;
            if(indig[next] < 2 && !visited[next]){
                q.push(next);
                visited[next] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            cnt++;
        }
    }
    cout << cnt << '\n';
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
            cout << i << ' ';
        }
    }
    return 0;
}