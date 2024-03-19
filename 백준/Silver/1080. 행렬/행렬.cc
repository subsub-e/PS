#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int arr1[n][m];
    int arr2[n][m];
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            arr1[i][j] = (int)c - 48;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            arr2[i][j] = (int)c - 48;
        }
    }

    for(int i = 0; i < n - 2; i++){
        for(int j = 0; j < m - 2; j++){
            if(arr1[i][j] != arr2[i][j]){
                cnt++;
                for(int k = i; k < i + 3; k++){
                    for(int p = j; p < j + 3; p++){
                        //cout << arr1[k][p] << '\n';
                        arr1[k][p] = abs(arr1[k][p] - 1);
                    }
                }
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << arr1[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr1[i][j] != arr2[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    
    cout << cnt;
    
	return 0;
}