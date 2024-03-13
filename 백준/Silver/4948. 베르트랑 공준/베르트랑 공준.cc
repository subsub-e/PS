#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int arr[300000];
    for(int i = 1; i <= 300000; i++){
        arr[i] = i;
    }
    for(int i = 2; i <= sqrt(300000); i++){
        if(arr[i] == 0){
            continue;
        }
        for(int j = i * i; j <= 300000; j += i){
            arr[j] = 0;
        }
    }

    while(1){
        int n; cin >> n;
        int cnt = 0;
        if(n == 0){
            break;
        }
        for(int i = n + 1; i <= 2 * n; i++){
            if(arr[i] != 0){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
	return 0;
}