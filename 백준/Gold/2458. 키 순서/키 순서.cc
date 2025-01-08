#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[502][502];
int n, m;
const int INF = 1e9 + 10;

int main(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            arr[i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int from, to; cin >> from >> to;
        arr[from][to] = 1;
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



    int ans[n][2];

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        int cnt2 = 0;
        for(int j = 1; j <= n; j++){
            if(arr[i][j] != INF){
                cnt++;
            }
            if(arr[j][i] != INF){
                cnt2++;
            }
        }
        ans[i][0] = cnt;
        ans[i][1] = cnt2;
    }

    int answer = 0;

    for(int i = 1; i <= n; i++){
        if(ans[i][0] + ans[i][1] == n+1){
            answer++;
        }
    }

    cout << answer;
}