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

int dp[100001][2];
int arr[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    dp[1][0] = arr[1];
    dp[1][1] = max(arr[1], 0);
    for(int i = 2; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        if(arr[i] + dp[i-1][1] < 0){
            dp[i][1] = 0;
        }
        else{
            dp[i][1] = dp[i-1][1] + arr[i];
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    // }

    cout << dp[n][0];
	return 0;
}