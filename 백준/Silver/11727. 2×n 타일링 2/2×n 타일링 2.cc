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

int dp[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= 1000; i++){
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }

    cout << dp[n];
	return 0;
}