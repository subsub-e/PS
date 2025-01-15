#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
int c[30001];
int p[30001];
int person[30001];
int dp[30001];


int find(int x){
    if(p[x] == x){
        return x;
    }
    return p[x] = find(p[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);

    if(X < Y){
        p[Y] = X;
    }
    else{
        p[X] = Y;
    }
}

void init(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    for(int i = 1; i <= n; i++){
        cin >> c[i];
        person[i] = 1;
    }

    

    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        if(find(x1) != find(x2)){
            Union(x1, x2);
        }
    }
}

void solve(){

    for(int i = 1; i <= n; i++){
        if(p[i] != i){
            int parent = find(i);
            c[parent] += c[i];
            person[parent] += person[i];
        }
    }

    for(int i = 1; i <= n; i++){
        if(p[i] != i){
            continue;
        }
        for(int j = k - 1; j - person[i] >= 0; j--){
            dp[j] = max(dp[j], dp[j - person[i]] + c[i]);
        }
    }
    cout << dp[k - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    init();
    solve();

}