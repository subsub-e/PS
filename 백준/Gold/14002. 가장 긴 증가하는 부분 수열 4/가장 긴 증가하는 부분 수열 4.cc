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

vector<int> v;
int arr[1001];
int dp[1001];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    int maxans = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = i - 1; j >= 1; j--){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxans = max(maxans, dp[i]);
    }

    cout << maxans << '\n';

    for(int i = n; i > 0; i--){
        if(maxans == dp[i]){
            v.push_back(arr[i]);
            maxans--;
        }
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    
	return 0;
}