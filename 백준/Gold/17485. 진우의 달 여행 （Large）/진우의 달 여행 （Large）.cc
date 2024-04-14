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

int n, m;
int arr[1001][1001];
int dp[1001][1001][3];
const int INF = 0x3f3f3f3f;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= m; i++){
        dp[1][i][0] = arr[1][i];
        dp[1][i][1] = arr[1][i];
        dp[1][i][2] = arr[1][i];
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j == 1){
                dp[i][j][1] = dp[i-1][j+1][0] + arr[i][j];
                dp[i][j][2] = min(dp[i-1][j][1], dp[i-1][j+1][0]) + arr[i][j];
            }
            else if(j == m){
                dp[i][j][0] = min(dp[i-1][j][1], dp[i-1][j-1][2]) + arr[i][j];
                dp[i][j][1] = dp[i-1][j-1][2] + arr[i][j];
            }
            else{
                dp[i][j][0] = min(dp[i-1][j-1][2], dp[i-1][j][1]) + arr[i][j];
                dp[i][j][1] = min(dp[i-1][j-1][2], dp[i-1][j+1][0]) + arr[i][j];
                dp[i][j][2] = min(dp[i-1][j][1], dp[i-1][j+1][0]) + arr[i][j];
            }
        }
    }

    int minans = INT_MAX;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < 3; j++){
            if(dp[n][i][j] == 0){
                continue;
            }
            //cout << dp[n][i][j] << ' ';
            minans = min(minans, dp[n][i][j]);
        }
        //cout << '\n';
    }

    cout << minans;

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         for(int k = 0; k < 3; k++){
    //             cout << dp[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

	return 0;
}