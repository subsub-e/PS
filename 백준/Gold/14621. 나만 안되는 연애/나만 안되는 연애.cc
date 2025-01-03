#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m, sum, cnt;
tuple<int, int, int> arr[10001];
char gen[1001];
int uf[1001];



int find(int x){
    if(x == uf[x]){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    uf[X] = Y;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
        cin >> gen[i];
    }

    for(int i = 1; i <= m; i++){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        arr[i] = make_tuple(cost, x1, x2);
    }

    sort(arr + 1, arr + 1 + m);

    for(int i = 1; i <= m; i++){
        int x1, x2, cost;
        tie(cost, x1, x2) = arr[i];

        if(find(x1) != find(x2)){
            if(gen[x1] == gen[x2]){
                continue;
            }
            sum += cost;
            Union(x1, x2);
            if(++cnt == n - 1){
                cout << sum;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}