#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
int arr[10];
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
        int n; cin >> n;
        char arr[n][n];
        int cnt = 0;
        int x = 100;
        int y = 100;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '#'){
                    x = min(x, i);
                    y = min(y, j);
                    cnt++;
                }
            }
        }

        int flag = 0;
        int flag1 = 0;
        while(n){
            if(cnt != n * n){
                n--;
                continue;
            }
            flag = 1;
            for(int i = x; i < x + n; i++){
                for(int j = y; j < y + n; j++){
                    if(arr[i][j] == '.'){
                        flag1 = 1;
                    }
                }
            }
            n--;
        }
        //cout << cnt << ' ' << flag << ' ' << flag1 << '\n';
        if(flag == 1 && flag1 == 0){
            cout << '#' << test_case << ' ' << "yes" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "no" << '\n';
        }
    }
    return 0;
}