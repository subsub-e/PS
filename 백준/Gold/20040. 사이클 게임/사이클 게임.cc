#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int uf[500001];
vector<pair<int, int> > v;

int find(int x){
    if(x == uf[x]){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X < Y){
        uf[X] = Y;
    }
    else{
        uf[Y] = X;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v.push_back({x1, x2});
    }

    for(int i = 0; i < (int) v.size(); i++){
        if(find(v[i].first) == find(v[i].second)){
            cout << i + 1;
            return 0;
        }
        else{
            Union(v[i].first, v[i].second);
        }
    }

    cout << 0;
}   