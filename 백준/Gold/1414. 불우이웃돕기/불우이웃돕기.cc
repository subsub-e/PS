#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

tuple<int, int, int> arr[3000];
int uf[51];
int n, sum, cnt;


int find(int x){
    if(x == uf[x]){
        return x;
    }
    return uf[x] = find(uf[x]);
}


void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    if(X > Y){
        uf[X] = Y;
    }
    else{
        uf[Y] = X;
    }
}


int main(){
    cin >> n;
    int index = 1;

    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
            int cost = 0;
            if(c >= 'a' && c <= 'z'){
                cost = (int) c - 96;
            }
            if(c >= 'A' && c <= 'Z'){
                cost = (int) c - 38;
            }
            if(cost > 0){
                if(i != j){
                    arr[index++] = make_tuple(cost, i, j);
                }
                sum += cost;
            }
        }
    }

    sort(arr + 1, arr + index + 1);

    for(int i = 1; i <= index; i++){
        int x1, x2, cost;
        tie(cost, x1, x2) = arr[i];

        if(find(x1) != find(x2)){
            Union(x1, x2);
            sum -= cost;
            cnt++;
        }
    }

    //cout << index << ' ' << cnt << '\n';
    if(cnt + 1 != n){
        cout << -1;
    }
    else{
        cout << sum;
    }
}