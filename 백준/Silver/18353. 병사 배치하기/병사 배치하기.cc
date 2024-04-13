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
int arr[2001];
int dp[2001];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    fill(dp, dp + 2001, 1);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int maxans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(arr[j] > arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxans = max(maxans, dp[i]);
    }
    
    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << ' ';
    // }
    cout << n - maxans;
	return 0;
}