#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int x[1000005] = {};
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        v.push_back(x[i]);
    }
    sort(v.begin(), v.end());
    vector<int> q;
    for(int i = 0; i < n; i++){
        if(i == 0 || v[i] != v[i-1]){
            q.push_back(v[i]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << lower_bound(q.begin(), q.end(), x[i]) - q.begin() << ' ';
    }
    return 0;
}