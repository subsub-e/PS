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
        string str; cin >> str;
        int a = 1;
        int b = 1;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'L'){
                b+=a;
            }
            else{
                a += b;
            }
        }

        cout << '#' << test_case << ' ' << a << ' ' << b << '\n';

    }
    return 0;
}