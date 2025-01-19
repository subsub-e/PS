#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;


int uf[100001];
int n, m;
vector<tuple<int, int, int, int> > v;

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

bool comp(tuple<int, int, int, int> t1, tuple<int, int, int, int> t2){
    int i, x1, x2, h1;
    int j, x3, x4, h2;
    tie(i, x1, x2, h1) = t1;
    tie(j, x3, x4, h2) = t2;
    if(x2 < x4){
        return true;
    }
    else{
        return false;
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

    for(int i = 1; i <= n; i++){
        int x1, x2, h;
        cin >> x1 >> x2 >> h;
        v.push_back(make_tuple(i, x1, x2, h));
    }

    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < v.size() - 1; i++){
        int x, x1, x2, h1;
        int t, t1, t2, h2;
        tie(x, x1, x2, h1) = v[i];
        tie(t, t1, t2, h2) = v[i + 1]; 

        if(x2 >= t1){
            Union(x, t);
        }
    }

    while(m--){
        int x1, x2;
        cin >> x1 >> x2;
        if(find(x1) != find(x2)){
            cout << 0 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
    }

}