#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char arr[2001][2001];
int psum[2002][2002];
int n, m, k;

int func(char target){
    int value;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            psum[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i + j) % 2 == 0){
                value = arr[i][j] != target;
            }
            else{
                value = arr[i][j] == target;
            }

            psum[i + 1][j + 1] = psum[i+1][j] + psum[i][j + 1] - psum[i][j] + value;
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << psum[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int result = 100000000;

    for(int i = 0; i <= n - k; i++){
        for(int j = 0; j <= m - k; j++){
            int cnt = psum[i + k][j + k] + psum[i][j] - psum[i][j + k] - psum[i + k][j];
            result = min(result, cnt);
        }
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    cout << min(func('B'), func('W')) << '\n';
}
