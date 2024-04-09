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



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int arr[1001] = {};
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= 1000; i++){
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }

    cout << arr[n];
	return 0;
}