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

bool arr[1001];

int main(int argc, char** argv)
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    int T;
    
    arr[1] = 1;
    arr[4] = 1;
    arr[9] = 1;
    arr[121] = 1;
    arr[484] = 1;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n, m; cin >> n >> m;
        int cnt = 0;
        for(int i = n; i <= m; i++){
            if(arr[i]){
                cnt++;
            }
        }
        cout << '#' << test_case << ' ' << cnt << '\n';
    }
    return 0;
}