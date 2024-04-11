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




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    int n;
    cin >> n;
    while(n--){
        int arr[100001][3] = {};
        int dp[100001][3] = {};
        int m; cin >> m;
        for(int i = 1; i <= m; i++){
            cin >> arr[i][1];
        }
        for(int i = 1; i <= m; i++){
            cin >> arr[i][2];
        }

        dp[1][1] = arr[1][1];
        dp[1][2] = arr[1][2];
        dp[2][1] = arr[1][1] + arr[2][2];
        dp[2][2] = arr[1][2] + arr[2][1];


        int flag = 0;
        for(int i = 3; i <= m; i++){
            if(flag == 0){
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][2]) + arr[i][1];
                dp[i][2] = max(dp[i-1][2], dp[i - 2][1]) + arr[i][2];
                flag++;
            }
            else{
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][2]) + arr[i][2];
                dp[i][2] = max(dp[i-1][2], dp[i - 2][1]) + arr[i][1];
                flag--;
            }
        }

        // for(int i = 1; i <= m; i++){
        //     cout <<  dp[i][1] << ' ';
        // }
        // cout << '\n';
        // for(int i = 1; i <= m; i++){
        //     cout << dp[i][2] << ' ';
        // }
        cout << max(dp[m][1], dp[m][2]) << '\n';
    }


	return 0;
}