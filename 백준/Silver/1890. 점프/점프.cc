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
int arr[101][101];
long long dp[101][101];

void func(){
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == 0){
                continue;
            }
            if(i == n && j == n){
                continue;
            }
            int nx = i + arr[i][j];
            int ny = j + arr[i][j];
            if(nx <= n){
                dp[nx][j] = dp[i][j] + dp[nx][j];
            }
            if(ny <= n){
                dp[i][ny] = dp[i][j] + dp[i][ny];
            }
        }
    }
    cout << dp[n][n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    dp[1][1] = 1;

    
    func();
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << dp[i][j];
    //     }
    //     cout << '\n';
    // }
	return 0;
}