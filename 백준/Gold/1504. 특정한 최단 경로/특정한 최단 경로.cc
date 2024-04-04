#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int> > v[801];
int d1[801];
int d2[801];
int d3[801];
int d4[801];
int d5[801];
int d6[801];
int x1, x2;
const int INF = 1e9-10;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    fill(d1, d1 + 1 + n, INF);
    fill(d2, d2 + 1 + n, INF);
    fill(d3, d3 + 1 + n, INF);
    fill(d4, d4 + 1 + n, INF);
    fill(d5, d5 + 1 + n, INF);
    fill(d6, d6 + 1 + n, INF);
    
    while(m--){
        int x, y, cost;
        cin >> x >> y >> cost;
        v[x].push_back(make_pair(cost, y));
        v[y].push_back(make_pair(cost, x));
    }

    cin >> x1 >> x2;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    d1[1] = 0;
    pq.push(make_pair(d1[1], 1));

    while(!pq.empty()){
        int cur_x = pq.top().first;
        int cur_y = pq.top().second;
        pq.pop();

        if(d1[cur_y] != cur_x){
            continue;
        }

        for(auto next : v[cur_y]){
            if(d1[next.second] <= next.first + d1[cur_y]){
                continue;
            }
            d1[next.second] = next.first + d1[cur_y];
            pq.push(make_pair(d1[next.second], next.second));
        }
    }

    d2[x1] = 0;
    pq.push(make_pair(d2[x1], x1));

    while(!pq.empty()){
        int cur_x = pq.top().first;
        int cur_y = pq.top().second;
        pq.pop();

        if(d2[cur_y] != cur_x){
            continue;
        }

        for(auto next : v[cur_y]){
            if(d2[next.second] <= next.first + d2[cur_y]){
                continue;
            }
            d2[next.second] = next.first + d2[cur_y];
            pq.push(make_pair(d2[next.second], next.second));
        }
    }

    d3[x2] = 0;
    pq.push(make_pair(d3[x2], x2));

    while(!pq.empty()){
        int cur_x = pq.top().first;
        int cur_y = pq.top().second;
        pq.pop();

        if(d3[cur_y] != cur_x){
            continue;
        }

        for(auto next : v[cur_y]){
            if(d3[next.second] <= next.first + d3[cur_y]){
                continue;
            }
            d3[next.second] = next.first + d3[cur_y];
            pq.push(make_pair(d3[next.second], next.second));
        }
    }

    d4[1] = 0;
    pq.push(make_pair(d4[1], 1));

    while(!pq.empty()){
        int cur_x = pq.top().first;
        int cur_y = pq.top().second;
        pq.pop();

        if(d4[cur_y] != cur_x){
            continue;
        }

        for(auto next : v[cur_y]){
            if(d4[next.second] <= next.first + d4[cur_y]){
                continue;
            }
            d4[next.second] = next.first + d4[cur_y];
            pq.push(make_pair(d4[next.second], next.second));
        }
    }

    d5[x2] = 0;
    pq.push(make_pair(d5[x2], x2));

    while(!pq.empty()){
        int cur_x = pq.top().first;
        int cur_y = pq.top().second;
        pq.pop();

        if(d5[cur_y] != cur_x){
            continue;
        }

        for(auto next : v[cur_y]){
            if(d5[next.second] <= next.first + d5[cur_y]){
                continue;
            }
            d5[next.second] = next.first + d5[cur_y];
            pq.push(make_pair(d5[next.second], next.second));
        }
    }

    d6[x1] = 0;
    pq.push(make_pair(d6[x1], x1));

    while(!pq.empty()){
        int cur_x = pq.top().first;
        int cur_y = pq.top().second;
        pq.pop();

        if(d6[cur_y] != cur_x){
            continue;
        }

        for(auto next : v[cur_y]){
            if(d6[next.second] <= next.first + d6[cur_y]){
                continue;
            }
            d6[next.second] = next.first + d6[cur_y];
            pq.push(make_pair(d6[next.second], next.second));
        }
    }

    int temp = min(d1[x1] + d2[x2] + d3[n], d4[x2] + d5[x1] + d6[n]);
    //cout << d1[x1] << ' ' << d2[x2] << ' ' << d3[n] << ' ' << d4[x2] << ' ' << d5[x1] << ' ' << d6[n] << '\n';
    if((d1[x1] != INF && d2[x2] != INF && d3[n] != INF) || (d4[x2] != INF && d5[x1] != INF && d6[n] !=INF)){
        cout << temp;
    }
    else{
        cout << -1;
    }
	return 0;
}