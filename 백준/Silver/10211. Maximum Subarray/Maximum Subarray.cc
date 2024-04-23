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

int arr[1001];
int sum[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

   
    int t; cin >> t;
    while(t--){
        memset(arr, 0, sizeof(arr));
        memset(sum, 0, sizeof(sum));

        int n; cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int maxans = INT_MIN;
        sum[0] = arr[0];
        for(int i = 1; i < n; i++){
            sum[i] = max(arr[i], arr[i] + sum[i-1]);
            maxans = max(maxans, sum[i]);
        }

        cout << max(maxans, arr[0]) << '\n';
    }
    

	return 0;
}