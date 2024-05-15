#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
#include <vector>
#include <string>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, inven;
    cin >> n >> m >> inven;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int h = 0;
    int time = INT_MAX;
    for(int k = 0; k < 257; k++){
        int sum = 0;
        int temp = inven;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] < k){
                    int plus = k - arr[i][j];
                    temp -= plus;
                    sum += plus;
                }
                else if(arr[i][j] > k){
                    int minus = arr[i][j] - k;
                    temp += minus;
                    sum += minus * 2;
                }
            }
        }
        if(temp < 0){
            break;
        }
        if(time >= sum){
            h = k;
            time = sum;
        }
    }

    cout << time << ' ' << h;

    return 0;
}