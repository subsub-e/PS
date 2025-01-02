#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        vector<int> v;
        int n, m, k;
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < m; i++){
            sum += v[i];
        }
        if(sum < k){
            cnt++;
        }
        if(n == m){
            cout << cnt << '\n';
            continue;
        }
        for(int i = m; i < n + m - 1; i++){
            sum -= v[i - m];
            sum += v[i % n];
            if(sum < k){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}