#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        unordered_map<string, int> m;
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            string dumm, str;
            cin >> dumm >> str;
            m[str]++;
        }

        int sum = 1;
        for(auto u : m){
            sum *= (u.second + 1);
        }
        cout << sum - 1 << '\n';
    }
}