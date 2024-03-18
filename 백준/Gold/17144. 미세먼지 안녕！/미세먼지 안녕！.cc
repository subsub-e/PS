#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <string.h>
using namespace std;

int r, c, t;
int arr[51][51];
int temp[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void simulate(){
    int clean[r][c];

    int index = 1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(arr[i][j] == -1 && index == 2){
                for(int k = i + 1; k < r - 1; k++){
                    arr[k][0] = arr[k+1][0];
                }
                for(int k = 0; k < c - 1; k++){
                    arr[r - 1][k] = arr[r - 1][k + 1];
                }
                for(int k = r - 1; k > i; k--){
                    arr[k][c - 1] = arr[k - 1][c - 1];
                }
                for(int k = c-1; k > 1; k--){
                    arr[i][k] = arr[i][k-1];
                }
                arr[i][j + 1] = 0;
                return;
            }

            if(arr[i][j] == -1 && index == 1){
                for(int k = i - 1; k > 0; k--){
                    //cout << arr[k-1][0] << '\n';;
                    arr[k][0] = arr[k-1][0];
                }
                for(int k = 0; k < c - 1; k++){
                    //cout << arr[0][k + 1] << '\n'; 
                    arr[0][k] = arr[0][k + 1];
                }
                for(int k = 0; k < i; k++){
                    //cout << arr[k][c-1] <<arr[k + 1][c-1] << '\n';
                    arr[k][c-1] = arr[k + 1][c-1];
                }
                for(int k = c - 1; k > 1; k--){
                    //cout << arr[i][k - 1] << '\n';
                    arr[i][k] = arr[i][k-1];
                }
                arr[i][j + 1] = 0;
                index++;
            }

            
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> t;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }
    
	while(t--){
        memset(temp, 0, sizeof(temp));

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(arr[i][j] > 0){
                    int temp_cnt = 0;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(0 <= nx && nx < r && 0 <= ny && ny < c && arr[nx][ny] != -1){
                            temp_cnt++;
                            temp[nx][ny] += arr[i][j] / 5;
                        }
                    }
                    arr[i][j] -= (arr[i][j] / 5) * temp_cnt;
                }
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                arr[i][j] += temp[i][j];
            }
        }

        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        simulate();

        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    int sum = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            sum += arr[i][j];
        }
    }
    cout << sum + 2;
	return 0;
}