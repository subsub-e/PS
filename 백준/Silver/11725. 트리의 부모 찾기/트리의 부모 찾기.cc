#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int n; 
vector<int> v[100001];
bool visited[100001];
int p[100001];

void dfs(int x){
    for(auto next : v[x]){
        if(p[x] == next){
            continue;
        }
        p[next] = x;
        dfs(next);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    p[1] = 1;
    dfs(1);

    for(int i = 2; i <= n; i++){
        cout << p[i] << '\n';
    }
    return 0;
}