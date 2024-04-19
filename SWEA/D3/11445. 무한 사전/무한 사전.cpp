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
        string str1, str2; cin >> str1 >> str2;
        if(str1 + "a" == str2){
            cout << '#' << test_case << ' ' << 'N' << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << 'Y' << '\n';
        }

    }
    return 0;
}