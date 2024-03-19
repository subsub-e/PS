#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    long long n; cin >> n;
    int arr[6];
    for(int i = 0; i < 6; i++){
        cin >> arr[i];
    }

    if(n == 1){
        sort(arr, arr + 6);
        cout << arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
        return 0;
    }



    long long index1 = n * n + n * (n-1) + 2 * (n-1) * (n-1) + (n-2) * (n-1);
    long long index2 = n + 6 * (n-1) + (n - 2);
    long long index3 = 4;

    arr[0] = min(arr[0], arr[5]);
    arr[1] = min(arr[1], arr[4]);
    arr[2] = min(arr[2], arr[3]);
    sort(arr, arr + 3);
    

    long long ans = index1 * arr[0] + index2 * arr[1] + index3 * arr[2];
    //cout << index1 << ' ' << index2 << ' ' << index3 << ' ' << ans << '\n';
    cout << ans;
	return 0;
}