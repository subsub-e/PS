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

int dp[2000010];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    dp[1000000] = 0;
    dp[1000001] = 1;
    for(int i = 1000002; i <= 2000000; i++){
        dp[i] = ((dp[i - 1] % 1000000000) + (dp[i - 2] % 1000000000)) % 1000000000;
    }
    for(int i = 999999; i >= 0; i--){
        dp[i] = ((dp[i + 2] % 1000000000) - (dp[i + 1] % 1000000000)) % 1000000000;
    }

    cin >> n;
    if(dp[1000000 + n] < 0){
        cout << -1 << '\n' << abs(dp[1000000 + n]);
    }
    else if(dp[1000000 + n] == 0){
        cout << 0 << '\n' << 0;
    }
    else{
        cout << 1 << '\n' << dp[1000000 + n];
    }
    
    
	return 0;
}