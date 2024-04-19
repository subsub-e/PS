#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <tuple>
#include <unordered_set>
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
        long long n, m; cin >> n >> m;
        int flag = 0;
        for(int i = 0; i < n; i++){
            if(m % 2 == 0){
                flag = 1;
                break;
            }
            m /= 2;
        }
        if(flag == 0){
            cout << '#' << test_case << ' ' << "ON" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "OFF" << '\n';
        }
    }
    return 0;
}