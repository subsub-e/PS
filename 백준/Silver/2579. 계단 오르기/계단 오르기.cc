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

int dp[301];
int arr[301];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    dp[1] = arr[1];
    dp[2] = arr[2];
    dp[3] = arr[3];
    for(int i = 4; i <= 300; i++){
        dp[i] = arr[i] + min(dp[i - 2], dp[i - 3]);
    }
    cout << sum - min(dp[n - 1], dp[n - 2]);
	return 0;
}