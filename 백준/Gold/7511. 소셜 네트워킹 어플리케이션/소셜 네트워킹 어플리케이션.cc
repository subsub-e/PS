#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int uf[1000001];

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
    
    cin >> t;
    int temp = 1;
    while(t--){
        int n, m, p;
        cin >> n;
        for(int i = 1; i <= n; i++){
            uf[i] = i;
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            int x1, x2;
            cin >> x1 >> x2;
            Union(x1, x2);
        }
        cin >> p;
        cout << "Scenario " << temp++ << ':' << '\n';
        for(int i = 0; i < p; i++){
            int x1, x2;
            cin >> x1 >> x2;
            if(find(x1) != find(x2)){
                cout << 0 << '\n';
            }
            else{
                cout << 1 << '\n';
            }
        }
        cout << '\n';
    }
}