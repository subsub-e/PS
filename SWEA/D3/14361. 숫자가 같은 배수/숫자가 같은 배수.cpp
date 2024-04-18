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
        memset(arr, 0, sizeof(arr));

        string str = to_string(n);
        for(int i = 0; i < str.length(); i++){
            arr[(int) str[i] - 48]++;
        }
        int p = 0;
        
        for(int i = 2; i <= 9; i++){
            string temp = to_string(n * i);
            int now[10] = {};
            for(int j = 0; j < temp.length(); j++){
                //cout << (int) temp[j] << '\n';
                now[(int) temp[j] - 48]++;
            }
            int flag = 0;
            for(int j = 0; j < 10; j++){
                if(arr[j] != now[j]){
                    flag = 1;
                }
            }
            if(flag == 0){
                cout << '#' << test_case << ' ' << "possible" << '\n';
                //cout << i << '\n';
                p = 1;
                break;
            }
        }

        if(p == 0){
            cout << '#' << test_case << ' ' << "impossible" << '\n';
        }


    }
    return 0;
}