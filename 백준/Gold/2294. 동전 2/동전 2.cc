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

int dp[10001];
int arr[101];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= 10000; i++){
        dp[i] = 100001;
    }
    int index = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        int flag = 0;
        
        for(int j = 0; j < i; j++){
            if(arr[j] == x){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            continue;
        }
        else{
            arr[index] = x;
            index++;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= m; j++){
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }

    // for(int i = 1; i <= m; i++){
    //     cout << dp[i] << '\n';
    // }

    if(dp[m] >= 100001){
        cout << -1;
    }
    else{
        cout << dp[m];
    }
    
	return 0;
}