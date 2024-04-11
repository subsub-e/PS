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
int dp[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 1000000; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    cin >> n;
    cout << dp[n];
    
	return 0;
}