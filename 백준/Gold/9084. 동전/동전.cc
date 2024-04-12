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

    int n; cin >> n;
	while(n--){
		int m; cin >> m;
		int dp[10001] = {};
		int arr[21] = {};
		for(int i = 0; i < m; i++){
			cin >> arr[i];
		}
		
		int cost; cin >> cost;
		dp[0] = 1;

		for(int i = 0; i < m; i++){
			for(int j = arr[i]; j <= cost; j++){
				dp[j] += dp[j - arr[i]];
				
				
			}
		}

		cout << dp[cost] << '\n';
	}
    
    
	return 0;
}