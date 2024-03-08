#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;


int n, rem;
vector<int> v[51];
bool visited[51];
int cnt = 0;

void dfs(int cur, int x){
    if(cur == x){
        return;
    }
    visited[cur] = 1;
    if(v[cur].size() == 0){
        cnt++;
    }
    for(auto next : v[cur]){
        if(next == x && v[cur].size() == 1){
            cnt++;
        }
        if(!visited[next]){
            dfs(next, x);
        }
    }
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int index;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == -1){
            index = i;
            continue;
        }
        v[x].push_back(i);
    }
    cin >> rem;

    dfs(index, rem);

    cout << cnt;

    return 0;
}