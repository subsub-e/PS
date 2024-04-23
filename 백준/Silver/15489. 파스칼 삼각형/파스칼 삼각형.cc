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

int arr[31][31];

void func(){
    for(int i = 0; i <= 30; i++){
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
    for(int i = 2; i <= 30; i++){
        for(int j = 1; j < i; j++){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j]; 
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    int n, m, r;
    cin >> n >> m >> r;
    func();

    n--;
    m--;
    long long sum = 0;
    for(int i = n; i < n + r; i++){
        for(int j = m; j < m + i - n + 1; j++){
            sum += arr[i][j];
            //cout << arr[i][j] << '\n';
        }
    }

    cout << sum;
    

	return 0;
}