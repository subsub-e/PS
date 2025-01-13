#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1002][3];
int dp[1002][3];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    if(n == 2){
        int answer = min(
            min(arr[1][1], arr[1][2]) + arr[2][0], 
            min(
                min(arr[1][0], arr[1][2]) + arr[2][1], 
                min(arr[1][0], arr[1][1]) + arr[2][2]
            )
        );
        cout << answer;
        return 0;
    }

    int ans = 1e9 + 10;
    for(int i=0; i<=2; i++){
        int dp[1001][3];
        for(int j=0;j<=2;j++){
            if(j==i) dp[1][i]=arr[1][i];
            else dp[1][j]= 1e9 + 10;
        }
        for(int j=2;j<=n;j++){
            dp[j][0] = min(dp[j-1][1],dp[j-1][2])+arr[j][0];
            dp[j][1] = min(dp[j-1][0],dp[j-1][2])+arr[j][1];
            dp[j][2] = min(dp[j-1][1],dp[j-1][0])+arr[j][2];
        }
        for(int j=0;j<=2;j++){
            if(j==i) continue;
            ans = min(ans, dp[n][j]);
        }
    }
    

    cout << ans;
}