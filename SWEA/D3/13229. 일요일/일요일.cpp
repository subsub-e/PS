#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
 
int check[10];

int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string str; cin >> str;
        if(str == "SUN"){
            cout << '#' << test_case << ' ' << 7 << '\n';
        }
        else if(str == "MON"){
            cout << '#' << test_case << ' ' << 6 << '\n';
        }
        else if(str == "TUE"){
            cout << '#' << test_case << ' ' << 5 << '\n';
        }
        else if(str == "WED"){
            cout << '#' << test_case << ' ' << 4 << '\n';
        }
        else if(str == "THU"){
            cout << '#' << test_case << ' ' << 3 << '\n';
        }
        else if(str == "FRI"){
            cout << '#' << test_case << ' ' << 2 << '\n';
        }
        else if(str == "SAT"){
            cout << '#' << test_case << ' ' << 1 << '\n';
        }
    }
    return 0;
}