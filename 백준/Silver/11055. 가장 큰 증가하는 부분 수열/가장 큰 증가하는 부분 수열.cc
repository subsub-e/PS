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

int dp[1001];
int arr[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int maxans = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = arr[i];
        for(int j = 1; j < i; j++){
            if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i]){
                dp[i] = dp[j] + arr[i];
            }
        }
        maxans = max(maxans, dp[i]);
    }

    cout << maxans;
	return 0;
}