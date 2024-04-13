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
int w[101];
int v[101];
int dp[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= 100000; j++){
            if(j - w[i] >= 0){
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }  

    for(int i = 1; i <= 100000; i++){
        if(dp[i] >= n){
            cout << i;
            break;
        }
    }
    
	return 0;
}