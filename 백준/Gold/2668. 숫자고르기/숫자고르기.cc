#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int arr[101];
bool visited[101];
vector<int> v;

void dfs(int now, int start){
    if(visited[now]){
        if(start == now){
            v.push_back(now);
        }
        return;
    }

    visited[now] = 1;
    dfs(arr[now], start);
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }
}