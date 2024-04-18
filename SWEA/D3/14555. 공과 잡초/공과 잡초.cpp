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
 
        string str; cin >> str;
        int cnt = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ')'){
                cnt++;
            }
            if(str[i] == '('){
                if(str[i + 1] == ')'){
                    i++;
                }
                cnt++;
            }

        }
        cout << '#' << test_case << ' ' << cnt << '\n';
    }
    return 0;
}