#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, p;
int arr[301][301];
//int nxt[301][301];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> p;

    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + 1 + n, INF);
    }

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        arr[x][y] = cost;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int temp = max(arr[i][k], arr[k][j]);
                arr[i][j] = min(arr[i][j], temp);                
            }
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }


    while(p--){
        int x, y; cin >> x >> y;
        if(arr[x][y] >= INF){
            cout << -1 << '\n';
        }
        else{
            cout << arr[x][y] << '\n';
        }
    }
    
    
	return 0;
}