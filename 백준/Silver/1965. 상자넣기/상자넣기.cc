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
int arr[1001];
int dp[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    fill(dp, dp + 1001, 1);

    dp[1] = 1;
    int maxans = 0;
    for(int i = 2; i <= n; i++){
        for(int j = i - 1; j > 0; j--){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxans = max(maxans, dp[i]);
    }

    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << ' ';
    // }

    cout << maxans;
	return 0;
}