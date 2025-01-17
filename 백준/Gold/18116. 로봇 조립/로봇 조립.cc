#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uf[1000001];
int store[1000001];
int n;

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
        store[X] += store[Y];
    }
    else if(X == Y){
        return;
    }
    else{
        uf[X] = Y;
        store[Y] += store[X];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= 1000000; i++){
        uf[i] = i;
        store[i] = 1;
    }

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;

        if(c == 'I'){
            int x1, x2;
            cin >> x1 >> x2;
            Union(x1, x2);
        }

        else{
            int x; cin >> x;
            int X = find(x);
            cout << store[X] << '\n';
        }
    }
}