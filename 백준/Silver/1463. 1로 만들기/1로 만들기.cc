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


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int dp[1000001] = {};
    int n; cin >> n;
    dp[1] = 0;
    for(int i = 2; i <= 1000000; i++){
        dp[i] = dp[i - 1] + 1;
        if(i % 2 == 0){
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if(i % 3 == 0){
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout << dp[n];
    
	return 0;
}