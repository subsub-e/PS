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
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int cnt = 0;
        for(int i = 0; i < n - 2; i++){
            if((arr[i] < arr[i + 1] && arr[i + 1] < arr[i + 2]) || (arr[i] > arr[i + 1] && arr[i + 1] > arr[i + 2])){
                cnt++;
            }
        }

        cout << '#' << test_case << ' ' << cnt << '\n';

    }
    return 0;
}