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

long long arr[51];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 3;
    for(int i = 3; i <= 50; i++){
        arr[i] = (arr[i-1] % 1000000007 + arr[i-2] % 1000000007 + 1) % 1000000007;
    }

    int n; cin >> n;
    cout << arr[n];
    
    

	return 0;
}