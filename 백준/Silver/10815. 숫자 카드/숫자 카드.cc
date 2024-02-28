#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> one;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        one.push_back(x);
    }
    int m; cin >> m;
    vector<int> two;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        two.push_back(x);
    }
    sort(one.begin(), one.end());

    for(int i = 0; i < m; i++){
        cout << binary_search(one.begin(), one.end(), two[i]) << ' ';
    }
    return 0;
}