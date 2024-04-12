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
int dp[2002][2002];
int arr[2001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i + 1]){
            dp[i][i + 1] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        dp[i][i] = 1;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 2; j <= n; j++){
            if(arr[i] == arr[j] && dp[i + 1][j - 1] == 1){
                dp[i][j] = 1;
            }
        }
    }

    int m; cin >> m;
    while(m--){
        int x1, x2; cin >> x1 >> x2;
        cout << dp[x1][x2] << '\n';
    }


    
	return 0;
}