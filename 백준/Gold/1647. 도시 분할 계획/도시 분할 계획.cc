#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

int n, m;
int uf[100001];
vector<pair<int, pair<int, int> > > v;
int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X < Y){
        uf[Y] = X;
    }
    else{
        uf[X] = Y;
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }
    for(int i = 0; i < m; i++){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        v.push_back(make_pair(cost, make_pair(x1, x2)));
    }

    sort(v.begin(), v.end());

    // for(int i = 1; i <= v.size(); i++){
    //     cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << '\n';
    // }

    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(n == 2){
            break;
        }
        if(cnt == n - 2){
            break;
        }
        int cost = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        //cout << cost << ' ' << x << ' ' << y << '\n';
        if(find(x) != find(y)){
            sum += cost;
            cnt++;
            Union(x, y);
        }
    }

    cout << sum;

	return 0;
}