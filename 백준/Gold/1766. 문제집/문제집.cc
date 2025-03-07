#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>
#include <cmath>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v[n + 1];
    vector<int> indig(n + 1);
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        indig[y]++;
    }

    for(int i = 1; i <= n; i++){
        if(indig[i] == 0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int now = pq.top();
        pq.pop();

        cout << now << ' ';
        for(auto next : v[now]){
            indig[next]--;
            if(indig[next] == 0){
                pq.push(next);
            }
        }
    }


    return 0;
}
