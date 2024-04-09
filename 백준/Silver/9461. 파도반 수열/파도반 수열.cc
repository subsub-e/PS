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

long long dp[101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= 100; i++){
        dp[i] = dp[i - 3] + dp[i - 2];
    }
    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        cout << dp[m] << '\n';
    }
	return 0;
}