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
int arr[1001][1001];
int dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c; cin >> c;
            arr[i][j] = (int)c - 48;
        }
    }

    int maxans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] == 1){
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                maxans = max(maxans, dp[i][j]);
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    

    cout << maxans * maxans;

    
	return 0;
}