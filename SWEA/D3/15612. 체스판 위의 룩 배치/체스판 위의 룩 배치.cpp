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
 
        char arr[8][8];
        int cnt = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 'O'){
                    cnt++;
                }
            }
        }

        if(cnt != 8){
            cout << '#' << test_case << ' ' << "no" << '\n';
        }
        else{
            int flag = 0;
            for(int i = 0; i < 8; i++){
                int cnt1 = 0;
                int cnt2 = 0;
                for(int j = 0; j < 8; j++){
                    if(arr[i][j] == 'O'){
                        cnt1++;
                    }
                    if(arr[j][i] == 'O'){
                        cnt2++;
                    }
                }
                if(cnt1 != 1 || cnt2 != 1){
                    flag = 1;
                }
            }
            if(flag == 0){
                cout << '#' << test_case << ' ' << "yes" << '\n';
            }
            else{
                cout << '#' << test_case << ' ' << "no" << '\n';
            }
        }
    }
    return 0;
}