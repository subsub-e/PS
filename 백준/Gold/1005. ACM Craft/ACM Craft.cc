#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int temp_count;
    cin >> temp_count;
    while(temp_count--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > v(1001);
        vector<int> indig(1001);
        queue<int> q;
        int weight[1001] = {};
        int ans[1001] = {};

        for(int i = 1; i <= n; i++){
            cin >> weight[i];
        }

        for(int i = 0; i < m; i++){
            int x1, x2; cin >> x1 >> x2;
            v[x1].push_back(x2);
            indig[x2]++;
        }

        for(int i = 1; i <= n; i++){
            if(indig[i] == 0){
                q.push(i);
            }
            ans[i] = weight[i];
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto next : v[cur]){
                indig[next]--;
                ans[next] = max(ans[next], ans[cur] + weight[next]);
                if(indig[next] == 0){
                    q.push(next);
                }
            }
        }

        int pp; cin >> pp;
        cout << ans[pp] << '\n';

    }

    return 0;
}