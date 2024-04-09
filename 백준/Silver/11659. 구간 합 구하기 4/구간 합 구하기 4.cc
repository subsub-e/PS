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

    int n, m; cin >> n >> m;
    int arr[n];
    int sum[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sum[0] = arr[0];
    for(int i = 1; i < n; i++){
        sum[i] = arr[i] + sum[i - 1];
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a == 0){
            cout << sum[b] << '\n';
        }
        else{
            cout << sum[b] - sum[a - 1] << '\n';
        }
    }
	return 0;
}