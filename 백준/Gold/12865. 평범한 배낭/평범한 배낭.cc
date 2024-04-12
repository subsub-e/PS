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

int n, weight;
int dp[101][100001];
int w[101];
int v[101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> weight;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= weight; i++){
        for(int j = 1; j <= n; j++){
            if(w[j] > i){
                dp[j][i] = dp[j-1][i];
            }
            else{
                dp[j][i] = max(dp[j-1][i], dp[j-1][i - w[j]] + v[j]);
            }
        }
    }
    
    cout << dp[n][weight];

	return 0;
}