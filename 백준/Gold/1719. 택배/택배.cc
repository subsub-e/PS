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
int n, m;
int arr[201][201];
int nxt[201][201];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + n + 1, INF);
    }

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        arr[x][y] = cost;
        arr[y][x] = cost;
        nxt[x][y] = y;
        nxt[y][x] = x;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(nxt[i][j] == 0){
                cout << '-' << ' ';
            }
            else{
                cout << nxt[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    
    
	return 0;
}