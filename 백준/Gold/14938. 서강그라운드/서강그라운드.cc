#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

int n, m, t;
int arr[101][101];
int val[101];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> t;
	for(int i = 1; i <= n; i++){
		fill(arr[i], arr[i] + 1 + n, 1000001);
	}

	for(int i = 1; i <= n; i++){
		arr[i][i] = 0;
	}

	for(int i = 1; i <= n; i++){
		cin >> val[i];
	}

	for(int i = 0; i < t; i++){
		int x1,x2, cost;
		cin >> x1 >> x2 >> cost;
		arr[x1][x2] = min(arr[x1][x2], cost);
		arr[x2][x1] = min(arr[x2][x1], cost);
	}

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++){
	// 		cout << arr[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	int maxans = 0;
	for(int i = 1; i <= n; i++){
		int sum = 0;
		for(int j = 1; j <= n; j++){
			if(arr[i][j] <= m){
				sum += val[j];
			}
		}
		//cout << sum << '\n';
		maxans = max(maxans, sum);
	}

	cout << maxans;
	return 0;
}