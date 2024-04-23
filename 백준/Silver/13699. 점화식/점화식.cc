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

long long arr[36];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

   
    arr[0] = 1;
    arr[1] = arr[0] * arr[0];  
    for(int i = 2; i <= 35; i++){
        long long sum = 0;
        for(int j = 0; j < i; j++){
            sum += arr[j] * arr[i - j - 1];
        }
        arr[i] = sum;
    }

    int n; cin >> n;
    cout << arr[n];
    

	return 0;
}