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

int dp[301][3];
int arr[301];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    dp[1][1] = arr[1];
    dp[1][2] = 0;
    dp[2][1] = arr[2];
    dp[2][2] = arr[1] + arr[2];
    for(int i = 3; i <= 300; i++){
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
    }

    cout << max(dp[n][1], dp[n][2]);
	return 0;
}