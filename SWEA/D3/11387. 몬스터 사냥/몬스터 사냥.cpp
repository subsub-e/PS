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
        int a;
        double b;
        int c;
        cin >> a >> b >> c;
        long long sum = 0;
        
        for(int i = 0; i < c; i++){
            
            sum += round(a * (1 + i * (b / 100)));
            //cout << a << '\n';
        }

        cout << '#' << test_case << ' ' << sum << '\n';

    }
    return 0;
}