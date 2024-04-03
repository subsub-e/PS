#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
using namespace std;

int arr[105][105];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + 1 + n, 10000001);
    }

    while(m--){
        int x, y, cost;
        cin >> x >> y >> cost;
        arr[x][y] = min(arr[x][y], cost);
    }

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == 10000001){
                cout << '0' << ' ';
            }
            else{
                cout << arr[i][j] << ' ';
            }
        }
        cout << '\n';
    }


    
	return 0;
}