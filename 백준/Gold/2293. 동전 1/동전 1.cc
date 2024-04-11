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


int n, m;
int dp[10001];
int arr[101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= m; j++){
            dp[j] += dp[j - arr[i]];
        }
    }

    cout << dp[m];
    
	return 0;
}