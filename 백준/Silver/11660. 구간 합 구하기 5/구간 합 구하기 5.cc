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

int n, m;
int arr[1025][1025];
int sum[1025][1025];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        sum[1][i] = sum[1][i - 1] + arr[1][i];
        sum[i][1] = sum[i-1][1] + arr[i][1];
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j - 1] + arr[i][j] - sum[i-1][j-1];
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << sum[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    while(m--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x2][y1-1] - sum[x1-1][y2] << '\n';
    }
    
	return 0;
}