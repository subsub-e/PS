#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int weight[10001] = {};
    vector<vector<int> > v(n + 1);
    vector<int> indig(n + 1);
    int result[10001] = {};
    queue<int> q;
    

    for(int i = 1; i <= n; i++){
        int cnt;
        cin >> weight[i] >> cnt;
        for(int j = 0; j < cnt; j++){
            int pre; cin >> pre;
            v[pre].push_back(i);
            indig[i]++;
        }
    }

    for(int i = 1; i <= n; i++){
        if(indig[i] == 0){
            q.push(i);
        }
        result[i] = weight[i];
    }


    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : v[cur]){
            indig[next]--;
            result[next] = max(result[next], result[cur] + weight[next]);
            if(indig[next] == 0){
                q.push(next);
            }
        }
    }

    int maxans = 0;
    for(int i = 1; i <= n; i++){
        maxans = max(maxans, result[i]);
        //cout << result[i] << '\n';
    }
    cout << maxans;
    return 0;
}