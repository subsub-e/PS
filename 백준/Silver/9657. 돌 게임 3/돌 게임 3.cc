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
int dp[1001];

bool func(int x){
    if(x > n){
        return false;
    }
    return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    cin >> n;
    for(int i = 6; i <= n; i++){
        if(dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0){
            dp[i] = 1;
        }
        else{
            dp[i] = 0;
        }
    }

    if(dp[n] == 0){
        cout << "CY";
    }
    else{
        cout << "SK";
    }
    
	return 0;
}