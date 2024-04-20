#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <tuple>
#include <map>
using namespace std;

int arr[1001];

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
        map<int, int> m;
        m[2] = 4;
        m[3] = 4;
        m[4] = 4;
        m[5] = 4;
        m[6] = 4;
        m[7] = 4;
        m[8] = 4;
        m[9] = 4;
        m[10] = 16;
        m[11] = 4;

        int n; cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            m[x]--;
            sum += x;
        }

        int temp = 21 - sum;

        int cnt1 = 0;
        for(int i = 2; i <= temp; i++){
            cnt1 += m[i];
        }
        
        int cnt2 = 0;
        for(int i = temp + 1; i <= 11; i++){
            cnt2 += m[i];
        }

        if(cnt2 >= cnt1){
            cout << '#' << test_case << ' ' << "STOP" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "GAZUA" << '\n';
        }
    }
    return 0;
}