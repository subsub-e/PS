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

int arr[41];
int dp[41];
int n, m;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> arr[i];
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 40; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    int ans = 1;
    int start = 0;
    for(int i = 0; i < m; i++){
        int end = arr[i];
        ans *= dp[end - start - 1];
        start = end;
    }
    ans *= dp[n - start];

    cout << ans;


	return 0;
}