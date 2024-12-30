#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


int s[10001];
const long long INF = 1e9 + 10;

int main(){
    int t; cin >> t;
    while(t--){
        vector<pair<int, int> > v[10001];
        int n, d, c;
        cin >> n >> d >> c;

        fill(s, s + n + 1, INF);

        while(d--){
            int x, y, cost;
            cin >> x >> y >> cost;
            v[y].push_back(make_pair(cost, x));
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        s[c] = 0;
        pq.push(make_pair(s[c], c));

        while(!pq.empty()){
            int cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();

            for(auto next : v[now]){
                if(s[next.second] > next.first + s[now]){
                    s[next.second] = next.first + s[now];
                    pq.push(make_pair(s[next.second], next.second));
                }
            }
        }
        int cnt = 0;
        int tot = 0;

        for(int i = 1; i <= n; i++){
            if(s[i] < INF){
                tot = max(tot, s[i]);
                cnt++;
            }
        }
        cout << cnt << ' ' << tot << '\n';
    }
}