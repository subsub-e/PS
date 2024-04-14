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
int dp[101][10001];
int w[101];
int v[101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        sum += v[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j - v[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]] + w[i]);
            }
        }
    }

    for(int i = 0; i <= sum; i++){
        if(dp[n][i] >= m){
            cout << i;
            return 0;
        }
    }
	return 0;
}