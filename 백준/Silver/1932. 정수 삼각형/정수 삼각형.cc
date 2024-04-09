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

int dp[501][501];
int arr[501][501];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j + k - 1] + arr[i][j]);
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    int maxans = 0;
    for(int i = 0; i <= n; i++){
        maxans = max(maxans, dp[n][i]);
    }

    cout << maxans;

	return 0;
}