#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g, n, ans;
bool visited[100001];
int uf[100001];

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
    cin.tie(0);
    cout.tie(0);

    cin >> g >> n;

    for(int i = 1; i <= g; i++){
        uf[i] = i;
    }

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        x = find(x);
        if(x == 0){
            break;
        }
        Union(x, x - 1);

        ans++;
    }
    cout << ans;
}