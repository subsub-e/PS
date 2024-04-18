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
 
        int n; cin >> n;
        if(n % 2 == 1){
            cout << '#' << test_case << ' ' << "Bob" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "Alice" << '\n';
        }
    }
    return 0;
}