#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int gcd(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd(y, x % y);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        int arr[m];
        for(int i = 0; i < m; i++){
            cin >> arr[i];
        }
        long long sum = 0;
        for(int i = 0; i < m - 1; i++){
            for(int j = i + 1; j < m; j++){
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum << '\n';
    }
	return 0;
}