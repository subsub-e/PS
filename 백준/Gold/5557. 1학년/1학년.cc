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
int arr[101];
long long dp[101][22];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    dp[1][arr[1]] = 1;

    for(int i = 2; i < n; i++){
        for(int j = 0; j <= 20; j++){
            if(dp[i-1][j] >= 1){
                if(j + arr[i] <= 20){
                    dp[i][j + arr[i]] += dp[i-1][j];
                }
                if(j - arr[i] >= 0){
                    dp[i][j - arr[i]] += dp[i-1][j];
                }
            }
        }
    }
    
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= 20; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n - 1][arr[n]];
	return 0;
}