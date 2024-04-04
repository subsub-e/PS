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
int arr[401][401];

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
        arr[x][y] = cost;
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

    int minans = INT_MAX;

    for(int i = 1; i <= n; i++){
        vector<int> v;
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(arr[i][j] != 0 && arr[i][j] != INF){
                v.push_back(j);
            }
        }
        for(int j = 0; j < v.size(); j++){
            if(arr[v[j]][i] != 0){
                sum = arr[i][v[j]] + arr[v[j]][i];
                minans = min(minans, sum);
            }
            
        }
    }
    if(minans >= INF){
        cout << -1;
    }
    else{
        cout << minans;
    }
    
    
	return 0;
}