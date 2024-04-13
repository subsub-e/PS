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
int dp[131];
int sum[131];
int ans[1000001];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    fill(ans, ans + 1000001, 100001);
    dp[1] = 1;
    for(int i = 2; i <= 130; i++){
        dp[i] = dp[i-1] + i;
    }

    sum[1] = 1;
    for(int i = 2; i <= 130; i++){
        sum[i] = sum[i-1] + dp[i];
    }
    
    int index = 1;
    ans[0] = 0;
    ans[1] = sum[1];
    for(int i = 1; i <= 130; i++){
        ans[sum[i]] = 1;
    }
    for(int i = 2; i <= 300000; i++){
        for(int j = 1; j <= 130; j++){
            if(i < sum[j]){
                break;
            }
            else{
                ans[i] = min(ans[i], ans[sum[j]] + ans[i - sum[j]]);
            }
        }
    } 

    cout << ans[n];
	return 0;
}