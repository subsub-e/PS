#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n;
int arr[10001];
vector<pair<int, int> > v[10001];
bool visited[10001];
int maxans = 0;

void dfs(int cur, int sum){
    visited[cur] = 1;
    for(auto next : v[cur]){
        if(!visited[next.first]){
            dfs(next.first, sum + next.second);
        }
    }
    maxans = max(maxans, sum);
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++){
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        arr[x1] = 1;
        v[x1].push_back(make_pair(x2, x3));
        v[x2].push_back(make_pair(x1, x3));
    }

    for(int i = 1; i <= n; i++){
        if(arr[i] == 0){
            fill_n(visited, 10001, 0);
            dfs(i, 0);
        }
    }

    cout << maxans;
    return 0;
}