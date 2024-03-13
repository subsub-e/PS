#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int arr[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int cnt = 0;

    for(int i = 2; i <= n; i++){
        arr[i] = i;
    }

    for(int i = 2; i <= n; i++){
        if(arr[i] == 0){
            continue;
        }
        //arr[i] = 0;
        cnt++;
        //cout << i << '\n';
        if(cnt == m){
            cout << i;
            return 0;
        }
        for(int j = i * i; j <= n; j += i){
            if(arr[j] == 0){
                continue;
            }
            arr[j] = 0;
            //cout << j << '\n';
            cnt++;
            if(cnt == m){
                cout << j;
                return 0;
            }
        }
    }
	return 0;
}