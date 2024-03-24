#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> v;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        v.push_back(x);
    }

    vector<long long> ans;
    for(int i = 1; i < n; i++){
        long long temp = v[i] - v[i - 1];
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    int sum = 0;
    for(int i = 0; i < ans.size() - m + 1; i++){
        sum += ans[i];
    }
    cout << sum;
    return 0;
}