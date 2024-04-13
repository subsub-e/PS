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
int dp[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    dp[1] = 3;
    dp[2] = 7;
    for(int i = 3; i <= 100000; i++){
        dp[i] = (dp[i - 1] * 2 + dp[i-2]) % 9901;
    }
    cin >> n;
    cout << dp[n];
	return 0;
}