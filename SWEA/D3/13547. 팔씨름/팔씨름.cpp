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
 
        string str;
        cin >> str;

        int cnt = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'o'){
                cnt++;
            }
        }

        cnt += (15 - str.length());
        if(cnt >= 8){
            cout << '#' << test_case << ' ' << "YES" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "NO" << '\n';
        }
    }
    return 0;
}