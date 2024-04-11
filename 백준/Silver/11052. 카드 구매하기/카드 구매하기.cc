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

int arr[1001];
int dp[1001];
int n;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    for(int i = 2; i <= n; i++){
        dp[i] = arr[i];
        for(int j = 1; j <= i / 2; j++){
            if(j % n == 0){
                dp[i] = max(dp[i], dp[j] * (n / j));
            }
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << dp[n];


	return 0;
}