#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
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
 
        int n, m;
        cin >> n >> m;
        int temp = m * 2 + 1;
        int sum = n / temp;
        if(n % temp > 0){
            sum++;
        }
        
        cout << '#' << test_case << ' ' << sum << '\n';

    }
    return 0;
}