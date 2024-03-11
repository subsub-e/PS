#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int arr[100001];
bool visited[100001];
bool finished[100001];
int cnt = 0;

void dfs(int now){
    visited[now] = 1;

    int next1 = arr[now];

    if(!visited[next1]){
        dfs(next1);
    }
    else{
        if(!finished[next1]){
            for(int i = next1; i != now; i = arr[i]){
                cnt++;
            }
            cnt++;
        }
    }
    finished[now] = 1;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        cnt = 0;
        for(int j = 1; j <= m; j++){
            cin >> arr[j];
        }
        for(int j = 1; j <= m; j++){
            if(!visited[j]){
                dfs(j);
            }
        }

        cout << m - cnt << '\n';
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
    }
    return 0;
}