#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> sum;

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    sum.push_back(0);
    sum.push_back(v[0]);
    for(int i = 1; i < n; i++){
        sum.push_back(v[i] + sum[i]);
    }

    int maxans = -1000000;
    for(int i = k; i < sum.size(); i++){
        maxans = max(maxans, (sum[i] - sum[i - k]));
    }
    cout << maxans;
}