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

int arr[50001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    int n; cin >> n;
    arr[1] = 1;

    for(int i = 2; i <= n; i++){
        int minans = INT_MAX;
        for(int j = 1; j * j <= i; j++){
            int temp = i - j * j;
            minans = min(minans, arr[temp]);
        }
        arr[i] = minans + 1;
    }

    cout << arr[n];
    

	return 0;
}