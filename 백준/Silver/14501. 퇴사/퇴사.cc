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

long long dp[105];
int arr[16][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    int maxans = 0;
    for(int i = n; i > 0; i--){
        int t = i + arr[i][0];
        if(t > n + 1){
            dp[i] = dp[i + 1];
        }
        else{
            dp[i] = max(dp[i + 1], dp[t] + arr[i][1]);
        }
    }
    cout << dp[1];
	return 0;
}