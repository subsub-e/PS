#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>
using namespace std;


int n, m, st, en;
vector<pair<int, int> > v[1001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int d[1001];
int parent[1001];
const int INF = 1e9 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    fill(d, d + n + 1, INF);

    
    while(m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].push_back({cost, b});
    }

    cin >> st >> en;
    d[st] = 0;
    pq.push({d[st], st});
    
    while(!pq.empty()){
        int now_cost = pq.top().first;
        int now_point = pq.top().second;
        pq.pop();

        if(d[now_point] != now_cost){
            continue;
        }

        for(auto next : v[now_point]){
            int next_cost = next.first;
            int next_point = next.second;

            if(d[next_point] > next_cost + d[now_point]){
                d[next_point] = next_cost + d[now_point];
                //cout << now_point << ' ' << next_point << ' ' << d[next_point] << '\n';
                pq.push({d[next_point], next_point});
                parent[next_point] = now_point;
            }
        }
    }

    cout << d[en] << '\n';

    int now = en;
    vector<int> answer;
    while(now != st){
        answer.push_back(now);
        now = parent[now];
    }
    answer.push_back(st);
    cout << answer.size() << '\n';

    reverse(answer.begin(), answer.end());
    for(auto now : answer){
        cout << now << ' '; 
    }

    return 0;
}
