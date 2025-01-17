#include <iostream>
#include <algorithm>

using namespace std;

int uf[1000001];
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

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    while(m--){
        int flag, x1, x2;
        cin >> flag >> x1 >> x2;

        if(flag == 0){
            Union(x1, x2);
        }

        else{
            if(find(x1) != find(x2)){
                cout << "NO" << '\n';
            }
            else{
                cout << "YES" << '\n';
            }
        }

    }
}