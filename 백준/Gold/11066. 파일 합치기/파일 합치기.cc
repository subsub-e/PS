#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int dp[501][501];
int sum[501];
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while(t--){
        int n; cin >> n;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            sum[i] = sum[i-1] + x;
        }

        for(int i = 1; i < n; i++){
            for(int x = 1; x <= n - i; x++){
                int y = x + i;

                dp[x][y] = INF;

                for(int mid = x; mid < y; mid++){
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + (sum[y] - sum[x - 1]));
                }
            }
        }

        cout << dp[1][n] << '\n';

    }
}