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
 
        string str1, str2; cin >> str1 >> str2;
        if(str1 == str2){
            cout << '#' << test_case << ' ' << "yes" << '\n';
            continue;
        }

        int len1 = str1.length();
        int len2 = str2.length();
        int temp = len1 * len2;

        int flag = 0;
        for(int i = 0; i < temp; i++){
            if(str1[i % len1] != str2[i % len2]){
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            cout << '#' << test_case << ' ' << "no" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "yes" << '\n';
        }
    }
    return 0;
}