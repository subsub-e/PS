#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;


int n;
map<int, pair<int, int> > m;
int sub = -1;
int sub_r = -1;

void func(int cur, int flag){
    if(cur == -1){
        return;
    }

    sub++;
    func(m[cur].first, 0);

    if(flag){
        sub_r++;
        func(m[cur].second, 1);
    }
    else{
        func(m[cur].second, 0);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        int x, l, r;
        cin >> x >> l >> r;
        m[x].first = l;
        m[x].second = r;
    }
    func(1, 1);

    cout << sub * 2 - sub_r;

    return 0;
}