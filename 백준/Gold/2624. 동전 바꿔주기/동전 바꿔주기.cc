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
pair<int, int> arr[101];
int dp[101][10001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        arr[i] = make_pair(x1, x2);
    }
    sort(arr + 1, arr + m + 1);
    // for(int i = 1; i <= m; i++){
    //     cout << arr[i].first << ' ' << arr[i].second << '\n';
    // }
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++){
        int cost = arr[i].first;
        int amount = arr[i].second;
        for(int j = 0; j <= amount; j++){
            for(int k = 0; k <= n; k++){
                if(cost * j + k > n){
                    break;
                }
                dp[i][k + cost * j] += dp[i-1][k]; 
            }
        }
    }

    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[m][n];
	return 0;
}