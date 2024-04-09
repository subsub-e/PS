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

int dp[1000001];
int pre[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i = 2; i <= 1000000; i++){
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;
        if(i % 2 == 0 && dp[i] > dp[i / 2] + 1){
            dp[i] = min(dp[i], dp[i/2] + 1);
            pre[i] = i / 2;
        }
        if(i % 3 == 0 && dp[i] > dp[i / 3] + 1){
            dp[i] = min(dp[i], dp[i / 3] + 1);
            pre[i] = i / 3;
        }
    }

    cout << dp[n] << '\n';
    cout << n << ' ';
    while(n > 1){
        cout << pre[n] << ' ';
        n = pre[n];
    }
    

	return 0;
}