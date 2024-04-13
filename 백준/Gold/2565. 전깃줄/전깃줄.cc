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
pair<int, int> arr[101];
int dp[101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        arr[i] = make_pair(x1, x2);
    }

    sort(arr, arr + n);
    fill(dp, dp + 101, 1);

    int maxans = 1;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(arr[i].second > arr[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxans = max(maxans, dp[i]);
    }


    cout << n - maxans;
    
	return 0;
}