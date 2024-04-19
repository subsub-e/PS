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
        int n; cin >> n;
        int flag = 0;
        for(int i = 1; i <= 9; i++){
            if(n % i == 0){
                if(n / i <= 9){
                    flag = 1;
                    
                    break;
                }
            }
        }
        if(flag == 1){
            cout << '#' << test_case << ' ' << "Yes" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "No" << '\n';
        }

    }
    return 0;
}