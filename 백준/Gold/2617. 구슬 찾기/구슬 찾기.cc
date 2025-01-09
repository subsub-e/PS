#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][100];
int n, m;
const int INF = 1e9 + 10;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int st, en;
        cin >> st >> en;
        arr[en][st] = 1;
    }


    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int ans = 0;
    int ansarr[101][2] = {};

    for(int i = 1; i <= n; i++){
        int cnt1 = 0;
        int cnt2 = 0;
        for(int j = 1; j <= n; j++){
            if(arr[i][j] != INF && arr[i][j] != 0){
                cnt1++;
            }
            if(arr[j][i] != INF && arr[j][i] != 0){
                cnt2++;
            }
        }
        if(cnt1 > n / 2 || cnt2 > n / 2){
            ans++;
        }
    }

    cout << ans;
}