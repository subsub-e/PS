#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
vector<pair<int, int> > v[100001];
bool visited[100001];
int maxans;
int endpoint;

void dfs(int cur, int sum){
    if(visited[cur]){
        return;
    }
    if(maxans < sum){
        maxans = sum;
        endpoint = cur;
    }
    visited[cur] = 1;
    for(auto next : v[cur]){
        dfs(next.first, next.second + sum);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int x1;
        cin >> x1;
        while(1){
            int x2;
            cin >> x2;
            if(x2 == -1){
                break;
            }
            int x3; cin >> x3;
            v[x1].push_back(make_pair(x2, x3));
        }
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));

    dfs(endpoint, 0);
    cout << maxans;

    return 0;
}