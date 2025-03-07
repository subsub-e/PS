#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>
using namespace std;


int n, m, t;
int s, g, h, test_case;
int d_s[2001];
int d_g[2001];
int d_h[2001];
vector<pair<int, int> > v[2001];
vector<int> answer;
const int INF = 1e9  +10;

void init(){
    for(int i = 1; i <= 2000; i++){
        d_s[i] = INF;
        d_g[i] = INF;
        d_h[i] = INF;
        v[i].clear();
    }
    answer.clear();
}

void input(){
    cin >> n >> m >> t >> s >> g >> h;

    while(m--){
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].push_back({cost, b});
        v[b].push_back({cost, a});
    }

    while(t--){
        int x; cin >> x;
        answer.push_back(x);
    }
}

void dijkstra(int st, int a[2001]){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    a[st] = 0;
    pq.push({a[st], st});

    while(!pq.empty()){
        int now_cost = pq.top().first;
        int now_point = pq.top().second;
        pq.pop();

        for(auto next : v[now_point]){
            if(a[next.second] > a[now_point] + next.first){
                a[next.second] = a[now_point] + next.first;
                pq.push({a[next.second], next.second});
            }
        }
    }
}

void solution(){
    dijkstra(s, d_s);
    dijkstra(g, d_g);
    dijkstra(h, d_h);

    sort(answer.begin(), answer.end());

    for(int i = 0; i < answer.size(); i++){
        int des = answer[i];
        if(d_s[des] == d_s[g] + d_g[h] + d_h[des]){
            cout << des << ' ';
        }
        else if(d_s[des] == d_s[h] + d_h[g] + d_g[des]){
            cout << des << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> test_case;
    while(test_case--){
        init();
        input();
        solution();
    }
    return 0;
}
