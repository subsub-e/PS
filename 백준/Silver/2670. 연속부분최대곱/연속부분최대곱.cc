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

double arr[10001];
double sum[10001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    double maxans = 0;

    sum[0] = arr[0];
    for(int i = 1; i < n; i++){
        sum[i] = max(arr[i], arr[i] * sum[i-1]);
        maxans = max(maxans, sum[i]);
    }

    cout << fixed;
    cout.precision(3);

    cout << maxans;
    
    

	return 0;
}