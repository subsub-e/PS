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
int dp[31];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    cin >> n;
    if(n % 2 == 1){
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i <= n; i += 2){
        int sum = dp[i-2] * 3;
        for(int j = 0; j < i - 2; j += 2){
            sum += dp[j] * 2;
        }
        dp[i] = sum;
    }

    cout << dp[n];
    
	return 0;
}