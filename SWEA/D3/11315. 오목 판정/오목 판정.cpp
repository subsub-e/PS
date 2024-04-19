#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
  
 
 
int main(int argc, char** argv)
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    int T;
      
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin >> n;
        char arr[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        int flag = 0;
        for(int i = 0; i < n - 4; i++){
            for(int j = 0 ; j < n - 4; j++){
                for(int k = i; k < i + 5; k ++){
                    int cnt = 0;
                    for(int p = j; p < j + 5; p++){
                        if(arr[k][p] == 'o'){
                            cnt++;
                        }
                    }
                    if(cnt >= 5){
                        flag = 1;
                    }
                }
            }
        }

        for(int i = 0; i < n - 4; i++){
            for(int j = 0 ; j < n - 4; j++){
                for(int k = i; k < i + 5; k ++){
                    int cnt = 0;
                    for(int p = j; p < j + 5; p++){
                        if(arr[p][k] == 'o'){
                            cnt++;
                        }
                    }
                    if(cnt >= 5){
                        flag = 1;
                    }
                }
            }
        }

        for(int i = 0; i < n - 4; i++){
            for(int j = 0 ; j < n - 4; j++){
                int cnt = 0;
                for(int k = 0; k < 5; k++){
                    if(arr[i + k][j + k] == 'o'){
                        cnt++;
                    }
                }
                if(cnt == 5){
                    flag = 1;
                }
            }
        }

        for(int i = n - 1; i > 3; i--){
            for(int j = 0 ; j < n - 4; j++){
                int cnt = 0;
                for(int k = 0; k < 5; k++){
                    if(arr[i - k][j + k] == 'o'){
                        cnt++;
                    }
                }
                if(cnt == 5){
                    flag = 1;
                }
            }
        }

        if(flag == 0){
            cout << '#' << test_case << ' ' << "NO" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "YES" << '\n';
        }
    }
    return 0;
}