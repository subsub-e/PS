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

int dp[11];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int m; cin >> m;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < 11; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while(m--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    
	return 0;
}