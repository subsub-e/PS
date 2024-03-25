#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;



int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    if(n <= m){
        cout << 0;
        return 0;
    }
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    vector<int> ans;
    for(int i = 1; i < n; i++){
        int temp = v[i] - v[i - 1];
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