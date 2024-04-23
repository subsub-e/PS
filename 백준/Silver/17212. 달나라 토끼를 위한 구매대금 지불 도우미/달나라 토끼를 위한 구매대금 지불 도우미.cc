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

long long arr[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int coin[4] = {1, 2, 5, 7};
    fill(arr, arr + 100001, 1e9+10);

    int n; cin >> n;
    arr[0] = 0;
    

    for(int i = 0; i < 4; i++){
        for(int j = coin[i]; j <= n; j++){
            arr[j] = min(arr[j], arr[j - coin[i]] + 1);
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << arr[i] << ' ';
    // }

    cout << arr[n];
    
    

	return 0;
}