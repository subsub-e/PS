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

int arr[10001];

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
        int temp = n * 2 / 60;
        int temp1 = n * 2 % 60;
        cout << '#' << test_case << ' ' << temp << ' ' << temp1 << '\n';
    }
    return 0;
}