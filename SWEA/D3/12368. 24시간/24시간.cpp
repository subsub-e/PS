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
        int n, m;
        cin >> n >> m;
        int temp = n + m;
        if(temp >= 24){
            cout << '#' << test_case << ' ' << temp - 24 << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << temp << '\n';
        }

    }
    return 0;
}