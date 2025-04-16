#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, t;
int parent[10001];
vector<pair<long long, pair<int, int> > > v;
long long answer;

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X != Y){
        parent[Y] = X;
    }
    else{
        parent[X] = Y;
    }
}

int main(){
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int st, en;
        long long cost;
        cin >> st >> en >> cost;
        v.push_back({cost, {st, en}});
    }

    sort(v.begin(), v.end());

    int cnt = 0;

    for(int i = 0; i < m; i++){
        long long c = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;

        if(find(x) != find(y)){
            answer += (c + cnt * t);
            cnt++;
            Union(x, y);

        }
    }
    cout << answer;
}