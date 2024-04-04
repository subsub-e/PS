#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

int arr[11][11];
int n, m;
int visited[11];
int minans = INT_MAX;

void dfs(int start, int cnt, int sum){
    if(cnt == n){
        minans = min(minans, sum);
        return;
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i, cnt + 1, sum + arr[start][i]);
            visited[i] = 0;
        }
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    visited[m] = 1;
    dfs(m, 1, 0);

    cout << minans;
	return 0;
}