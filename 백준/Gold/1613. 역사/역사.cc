#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[402][402];
const int INF = 1e9 + 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
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
        arr[st][en] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int t; cin >> t;
    while(t--){
        int st, en;
        cin >> st >> en;
        if(arr[st][en] == INF && arr[en][st] == INF){
            cout << 0 << '\n';
        }
        else if(arr[st][en] != INF){
            cout << -1 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
    }
}