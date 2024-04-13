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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        dp[i] = arr[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << ' ';
    // }

    cout << dp[n];
    
	return 0;
}