#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int n;
int arr[101][101];
bool visited[101];
vector<int> v[101];


void dfs(int x){
    for(auto next : v[x]){
        if(!visited[next]){
            visited[next] = 1;
            dfs(next);
        }
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                v[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[j] = 0;
        }
        dfs(i);
        for(int j = 0; j < n; j++){
            cout << visited[j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}