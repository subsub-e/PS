#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
bool visited[11];
int arr[11][11];
int minans = INT_MAX;

void dfs(int first, int now, int cnt, int cost){
    if(cnt == n){
        if(arr[now][first] == 0){
            return;
        }
        minans = min(minans, cost + arr[now][first]);
        return;
    }

    for(int i = 0; i < n; i++){
        if(arr[now][i] == 0 || visited[i]){
            continue;
        }
        visited[i] = 1;
        dfs(first, i, cnt + 1, cost + arr[now][i]);
        visited[i] = 0;
    }
}

int main() {
	
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        visited[i] = 1;
        dfs(i, i, 1, 0);
        visited[i] = 0;
    }

    cout << minans;
	return 0;
}