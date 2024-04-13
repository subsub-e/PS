#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;


int n;
int arr[1001];
int dp[1001];
bool visited[1001];
queue<int> q;

void bfs(){
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i = 1; i <= arr[x]; i++){
            if(x + i > n){
                dp[n] = min(dp[n], dp[x] + 1);
                continue;
            }
            if(!visited[x + i]){
                q.push(x + i);
                dp[x + i] = min(dp[x + i], dp[x] + 1);
                visited[x + i] = 1;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    fill(dp, dp + 1001, 1000001);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    dp[1] = 0;
    visited[1] = 1;
    q.push(1);
    bfs();
    if(dp[n] == 1000001){
        cout << -1;
    }
    else{
        cout << dp[n];
    }
	return 0;
}