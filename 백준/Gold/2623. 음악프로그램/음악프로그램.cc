#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int> > v(1001);
    queue<int> q;
    vector<int> indig(1001);
    vector<int> temp;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        for(int j = 0; j < x; j++){
            int p;
            cin >> p;
            temp.push_back(p);
        }
        for(int j = 0; j < x - 1; j++){
            v[temp[j]].push_back(temp[j + 1]);
            indig[temp[j + 1]]++;
        }
        temp.clear();
    }

    for(int i = 1; i <= n; i++){
        if(indig[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto next : v[cur]){
            indig[next]--;
            if(indig[next] == 0){
                q.push(next);
            }
        }
    }

    if(n != ans.size()){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }

    return 0;
}