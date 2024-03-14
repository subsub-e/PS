#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
#define MAX 10001

int arr[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    for(int i = 2; i < MAX; i++){
        arr[i] = i;
    }

    for(int i = 2; i < sqrt(MAX); i++){
        if(arr[i] == 0){
            continue;
        }
        for(int j = i * i; j < MAX; j += i){
            arr[j] = 0;
        }
    }

    int n; cin >> n;
    while(n--){
        int m; cin >> m;

        for(int i = m/2; i >= 0; i--){
            int a = i;
            int b = m - i;

            if(arr[a] && arr[b]){
                cout << a << ' ' << b << '\n';
                break;
            }
        }
    }

	return 0;
}