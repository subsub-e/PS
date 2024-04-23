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

    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int temp = m - n;
        long long ans = 1;
        for(int i = 0; i < min(temp, n); i++){
            ans *= (m - i);
        }
        for(int i = min(temp, n); i > 0; i--){
            ans /= i;
        }

        cout << ans << '\n';
    }

    

	return 0;
}