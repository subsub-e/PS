#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
#include <map>
#include <climits>
#include <set>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int pp;
    cin >> pp;
    while(pp--){
        int n, m; cin >> n >> m;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        int st = 0;
        int en = n - 1;
        int minans = INT_MAX;
        int cnt = 0;
        while(st < en){
            int sum = v[st] + v[en];
            if(abs(sum - m) < minans){
                cnt = 1;
                minans = abs(sum - m);
            }
            else if(abs(sum - m) == minans){
                cnt++;
            }
            if(sum < m){
                st++;
            }
            else{
                en--;
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}