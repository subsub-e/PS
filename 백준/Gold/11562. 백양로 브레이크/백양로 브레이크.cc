#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

const int INF = 0X3f3f3f3f;
int n, m, p;
int arr[251][251];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + 1 + n, INF);
    }

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        if(cost == 1){
            arr[x][y] = 0;
            arr[y][x] = 0;
        }
        else{
            arr[x][y] = 0;
            arr[y][x] = 1;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cin >> p;

    while(p--){
        int x, y;
        cin >> x >> y;
        cout << arr[x][y] << '\n';
    }
    
	return 0;
}