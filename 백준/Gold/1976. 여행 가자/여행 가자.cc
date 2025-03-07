#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <tuple>
using namespace std;

int uf[201];
int n, m;
int arr[1001][1001];
vector<int> v;

int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Merge(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X == Y){
        return;
    }
    else{
        uf[X] = Y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = i; i <= n; i++){
        uf[i] = i;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(arr[i][j] == 1){
                if(find(i) != find(j)){
                    Merge(i, j);
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    for(int i = 1; i < v.size(); i++){
        if(find(v[i]) != find(v[i-1])){
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
