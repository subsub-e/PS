#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(32001);
    vector<int> indig(32001);
    set<int> s;

    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        indig[x2]++;
    }

    for(int i = n; i > 0; i--){
        if(indig[i] == 0){
            s.insert(i);
        }
    }

    while(!s.empty()){
        int cur = *s.begin();
        s.erase(s.begin());
        cout << cur << ' ';
        for(auto next : v[cur]){
            indig[next]--;
            if(indig[next] == 0){
                s.insert(next);
            }
        }
    }

    return 0;
}