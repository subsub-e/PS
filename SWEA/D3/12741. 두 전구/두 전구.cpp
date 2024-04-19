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
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int temp = min(b, d) - max(a, c);
        if(temp < 0){
            cout << '#' << test_case << ' ' << 0 << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << min(b, d) - max(a, c) << '\n';
        }

    }
    return 0;
}