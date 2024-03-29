#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, m, r;
int arr[301][301];


void func(int min_x, int min_y, int max_x, int max_y, int cnt){
    while(cnt--){
        int temp1[301] = {};
        int temp2[301] = {};
        int temp3[301] = {};
        int temp4[301] = {};

        for(int i = max_x; i > min_x; i--){
            temp1[i] = arr[i - 1][min_y];
        }
        for(int i = max_y; i > min_y; i--){
            temp2[i] = arr[max_x][i - 1];
        }
        for(int i = min_x; i < max_x; i++){
            temp3[i] = arr[i + 1][max_y];
        }
        for(int i = min_y; i < max_y; i++){
            temp4[i] = arr[min_x][i + 1];
        }

        // for(int i = min_y + 1; i <= max_y; i++){
        //     cout << temp2[i] << ' ';
        // }
        // cout << '\n';

        for(int i = max_x; i > min_x; i--){
            arr[i][min_y] = temp1[i];
        }
        for(int i = max_y; i > min_y; i--){
            arr[max_x][i] = temp2[i];
        }
        for(int i = min_x; i < max_x; i++){
            arr[i][max_y] = temp3[i];
        }
        for(int i = min_y; i < max_y; i++){
            arr[min_x][i] = temp4[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < min(n, m) / 2; i++){
        int k = (n - i * 2) * (m - i * 2) - (n - (i + 1) * 2) * (m - (i + 1) * 2);
        func(i, i, n - i - 1, m - i - 1, r % k);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}