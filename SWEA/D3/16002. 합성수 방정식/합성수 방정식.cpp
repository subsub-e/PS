#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
using namespace std;
 
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
        int n; cin >> n;
        cout << '#' << test_case << ' ' << n * 9 << ' ' << n * 8 << '\n';
 
    }
    return 0;
}