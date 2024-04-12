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

int dp[5001];
int arr[5001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string str;
    cin >> str;
    
    for(int i = 1; i <= str.length(); i++){
        arr[i] = str[i-1] - '0';
    }
    if(str.length() == 1 && arr[1] == 0){
        cout << 0;
        return 0;
    }

    dp[0] = 1;

    for(int i = 1; i <= str.length(); i++){
        if(arr[i] >= 1 && arr[i] <= 9){
            dp[i] = (dp[i-1] + dp[i]) % 1000000;
        }
        if(i == 1){
            continue;
        }
        int temp = arr[i-1] * 10 + arr[i];
        if(temp >= 10 && temp <= 26){
            dp[i] = (dp[i-2] + dp[i]) % 1000000;
        }
    }

    cout << dp[str.length()];
    
	return 0;
}