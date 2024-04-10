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

int dp[1001][3][31];
int arr[1001];
int n, m;

int go(int t, int pos, int cnt){
    if(cnt < 0 || t > n){
        return 0;
    }
    if(dp[t][pos][cnt]){
        return dp[t][pos][cnt];
    }

    if(pos == 1){
        dp[t][pos][cnt] += max(go(t + 1, pos, cnt), go(t + 1, pos + 1, cnt - 1));
    }
    if(pos == 2){
        dp[t][pos][cnt] += max(go(t + 1, pos - 1, cnt - 1), go(t + 1, pos, cnt));
    }

    if(arr[t] == pos){
        dp[t][pos][cnt]++;
    }
    // return max(dp[t][1][cnt], dp[t][2][cnt]);
    return dp[t][pos][cnt];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    cout << max(go(1, 1, m), go(1, 2, m - 1));

	return 0;
}