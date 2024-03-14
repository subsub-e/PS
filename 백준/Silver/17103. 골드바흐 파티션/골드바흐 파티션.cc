#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int arr[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for(int i = 2; i <= 1000000; i++){
        arr[i] = i;
    }

    for(int i = 2; i <= sqrt(1000000); i++){
        if(arr[i] == 0){
            continue;
        }
        for(int j = i * i; j <= 1000000; j += i){
            arr[j] = 0;
        }
    }


    while(n--){
        int m; cin >> m;
        int cnt = 0;
        for(int i = 0; i <= m/2; i++){
            int a = i;
            int b = m - i;

            if(arr[a] && arr[b]){
                cnt++;
            }
        }

        cout << cnt << '\n';

    }


	return 0;
}