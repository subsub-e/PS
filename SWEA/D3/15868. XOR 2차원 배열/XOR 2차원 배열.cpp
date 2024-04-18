#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c; cin >> c;
                arr[i][j] = (int) c - 48;
            }
        }

        int arr1[n];
        int arr2[m];
        if(arr[0][0] == 0){
            for(int i = 0; i < n; i++){
                arr1[i] = arr[i][0];
            }
            for(int i = 0; i < m; i++){
                arr2[i] = arr[0][i];
            }
        }
        else{
            for(int i = 0; i < n; i++){
                arr1[i] = arr[i][0];
            }
            for(int i = 0; i < m; i++){
                arr2[i] = abs(1 - arr[0][i]);
            }
        }

        int temp[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((arr1[i] == 0 && arr2[j] == 0) || (arr1[i] == 1 && arr2[j] == 1)){
                    temp[i][j] = 0;
                }
                else{
                    temp[i][j] = 1;
                }
            }
        }

        int flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] != temp[i][j]){
                    flag = 1;
                }
            }
        }
        
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << temp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }


        if(flag == 0){
            cout << '#' << test_case << ' ' << "yes" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "no" << '\n';
        }
 
    }
    return 0;
}