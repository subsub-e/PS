#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int> > v[50001];
int d[50001];
const long long INF = 1e9 + 10;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int main(){
    cin >> n >> m;

    fill(d, d + n + 1, INF);

    while(m--){
        int x, y, cost; 
        cin >> x >> y >> cost;
        v[x].push_back(make_pair(cost, y));
        v[y].push_back(make_pair(cost, x));
    }

    d[1] = 0;
    pq.push(make_pair(d[1], 1));

    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for(auto next : v[now]){
            if(d[next.second] > next.first + d[now]){
                d[next.second] = next.first + d[now];
                pq.push(make_pair(d[next.second], next.second));
            }
        }
    }

    cout << d[n];
}