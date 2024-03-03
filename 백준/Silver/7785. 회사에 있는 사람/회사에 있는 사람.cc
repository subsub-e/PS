#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    unordered_set<string> m;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string str1;
        string str2;
        cin >> str1 >> str2;
        if(str2 == "enter"){
            m.insert(str1);
        }
        else{
            m.erase(str1);
        }
    }

    vector<string> v(m.begin(), m.end());
    sort(v.rbegin(), v.rend());

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }
}