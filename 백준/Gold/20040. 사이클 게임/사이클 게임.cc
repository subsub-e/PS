#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>
using namespace std;

int uf[500001];
int n, m;

int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X == Y){
        return;
    }
    uf[X] = Y;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        uf[i] = i;
    }

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        if(find(x) == find(y)){
            cout << i;
            return 0;
        }
        else{
            Union(x, y);
        }
        //cout << uf[x] << ' ' << uf[y] << '\n';
    }
    cout << 0;
    return 0;
}
