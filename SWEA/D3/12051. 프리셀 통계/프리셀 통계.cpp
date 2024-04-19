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
        long long n, p, q;
        cin >> n >> p >> q;
        if((p < 100 && q == 100) || (p > 0 && q == 0)){
            cout << '#' << test_case << ' ' << "Broken" << '\n';
            continue;
        }
        int flag = 0;
        for(int i = 1; i <= n; i++){
            if(i * p % 100 == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << '#' << test_case << ' ' << "Broken" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "Possible" << '\n';
        }

    }
    return 0;
}