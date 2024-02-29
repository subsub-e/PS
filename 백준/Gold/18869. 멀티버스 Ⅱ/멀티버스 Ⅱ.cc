#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
using namespace std;

pair<int, int> arr[101][10001];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int p; cin >> p;
            arr[i][j] = {p, j};
        }
        sort(&arr[i][0], &arr[i][m]);
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << arr[i][j].first << ' ';
    //     }
    //     cout << '\n';
    // }
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            int flag = 0;
            for(int k = 0; k < m; k++){
                if(arr[i][k].second != arr[j][k].second){
                    flag = 1;
                    break;
                }
                else{
                    if(i != m-1){
                        if((arr[i][k].first < arr[i][k + 1].first) != (arr[j][k].first < arr[j][k + 1].first)){
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if(flag == 0){
                //cout << i << ' ' << j << '\n';
                cnt++;
            }   
        }
    }
    cout << cnt;
}